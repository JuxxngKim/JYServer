#include "ProjectJY.h"
#include "NetworkBuffer.h"
#include "NetworkContext.h"

namespace jy
{
	NetworkBuffer::NetworkBuffer()
		: m_buffer(nullptr)
		, m_bufferSize(0)
		, m_writeSize(0)
		, m_readSize(0)
	{
	}

	NetworkBuffer::~NetworkBuffer()
	{
		if (m_buffer == nullptr) return;
		delete[] m_buffer;
	}

	bool NetworkBuffer::Write(void* src, int srcSize)
	{
		if (src == nullptr || srcSize <= 0)
		{
			S_LOG_ERROR("failed - src");
			return false;
		}

		if (srcSize > GetEmptySize())
		{
			S_LOG_ERROR("failed - GetEmptySize");
			return false;
		}

		memcpy(GetEmpty(), (char*)src, srcSize);
		m_writeSize += srcSize;

		return true;
	}

	bool NetworkBuffer::CompleteWrite(int size)
	{
		if (size > 0)
		{
			if (size > GetEmptySize())
			{
				S_LOG_ERROR("failed - GetEmptySize");
				return false;
			}

			m_writeSize += size;
		}

		return true;
	}

	bool NetworkBuffer::Read(void* dest, int destSize)
	{
		if (dest == nullptr || destSize <= 0)
		{
			S_LOG_ERROR("failed - dest");
			return false;
		}

		char* src = GetData();
		int srcSize = GetDataSize();
		if (src == nullptr || srcSize < destSize)
		{
			S_LOG_ERROR("failed - src");
			return false;
		}

		memcpy((char*)dest, src, destSize);
		m_readSize += destSize;

		return true;
	}

	bool NetworkBuffer::CompleteRead(int size)
	{
		if (size > 0)
		{
			if (size > GetDataSize())
			{
				S_LOG_ERROR("failed - size");
				return false;
			}

			m_readSize += size;
		}

		return true;
	}

	char* NetworkBuffer::GetData()
	{
		if (m_buffer == nullptr) return nullptr;
		if (m_bufferSize < m_writeSize) return nullptr;
		if (m_writeSize <= 0 || m_writeSize <= m_readSize) return nullptr;

		return m_buffer + m_readSize;
	}

	int NetworkBuffer::GetDataSize()
	{
		if (m_buffer == nullptr) return 0;
		if (m_bufferSize < m_writeSize) return 0;
		if (m_writeSize <= 0 || m_writeSize <= m_readSize) return 0;

		return m_writeSize - m_readSize;
	}

	char* NetworkBuffer::GetEmpty()
	{
		if (m_buffer == nullptr) return nullptr;
		if (m_bufferSize <= m_writeSize) return nullptr;

		return m_buffer + m_writeSize;
	}

	int NetworkBuffer::GetEmptySize()
	{
		if (m_buffer == nullptr) return 0;
		if (m_bufferSize <= m_writeSize) return 0;

		return (int)m_bufferSize - m_writeSize;
	}

	bool NetworkBuffer::PacketToByte(int packetId, google::protobuf::Message& packet)
	{
		//이미 버퍼가 할당되어있으면 실패
		if (m_buffer) return false;

		//사이즈 체크
		int messageSize = packet.ByteSize();
		if (messageSize < 0)
		{
			S_LOG_ERROR("packet size under(id : %, size : %)", packetId, messageSize);
			messageSize = 0;
		}
		else if (messageSize >= g_iPacketBodySize)
		{
			S_LOG_ERROR("packet size over(id : %, size : %)", packetId, messageSize);
		}

		//버퍼 할당
		m_bufferSize = g_iPacketHeaderSize + messageSize;
		m_buffer = new char[m_bufferSize];

		//데이터 복사
		uint64_t tempMessageSize = 0;
		uint64_t tempMessageID = 0;

		tempMessageSize = htonl(sizeof(tempMessageID) + messageSize);
		Write(&tempMessageSize, sizeof(tempMessageSize));

		tempMessageID = htonl(packetId);
		Write(&tempMessageID, sizeof(tempMessageID));

		if (messageSize > 0)
		{
			auto pos = GetEmpty();
			packet.SerializeToArray(pos, messageSize);
			Crypt::Convert(pos, messageSize);

			CompleteWrite(messageSize);
		}

		return true;
	}

	PacketInfo NetworkBuffer::ByteToPacket()
	{
		char* packet = GetData();
		int packetSize = GetDataSize();

		//데이터가 패킷최소사이즈보다 큰 경우인지 체크
		if (packetSize >= g_iPacketHeaderSize)
		{
			int messageSize = ntohl(*(uint64_t*)(packet)) - sizeof(u_long);
			int messageID = ntohl(*(uint64_t*)(packet + sizeof(u_long)));

			//데이터 사이즈 예외 체크
			if (messageSize >= 0 && messageSize <= packetSize - g_iPacketHeaderSize)
			{
				//읽기 처리
				CompleteRead(messageSize + g_iPacketHeaderSize);

				//TODO받기 완료 처리
				//Crypt::Convert(packet + g_iPacketHeaderSize, messageSize);

				//받기 완료 처리
				return std::forward_as_tuple(messageID, packet + g_iPacketHeaderSize, messageSize);
			}
		}

		return std::forward_as_tuple(0, nullptr, 0);;
	}

	bool NetworkBuffer::ReadyToRecv(WSABUF& wsabuf)
	{
		//버퍼가 없으면 생성
		if (m_buffer == nullptr)
		{
			m_writeSize = 0;
			m_readSize = 0;
			m_bufferSize = DEFAULT_CAPACITY_SIZE;
			m_buffer = new char[m_bufferSize];
		}

		//읽기와 쓰기가 같은지 체크
		if (m_readSize == m_writeSize)
		{
			//버퍼 축소
			if (m_bufferSize > DEFAULT_CAPACITY_SIZE)
			{
				if (m_buffer != nullptr)
				{
					delete[] m_buffer;
					m_buffer = nullptr;
				}

				m_bufferSize = DEFAULT_CAPACITY_SIZE;
				m_buffer = new char[m_bufferSize];
			}

			//읽기,쓰기 초기화
			m_writeSize = 0;
			m_readSize = 0;
		}

		//빈공간 체크
		int emptySize = GetEmptySize();
		if (emptySize < MIN_CAPACITY_SIZE)
		{
			if (emptySize + m_readSize >= MIN_CAPACITY_SIZE)
			{
				//재정렬만 함
				memmove(m_buffer, m_buffer + m_readSize, m_writeSize - m_readSize);
				m_writeSize -= m_readSize;
				m_readSize = 0;
			}
			else
			{
				//최대 사이즈를 넘어가는지 체크
				if (m_bufferSize >= MAX_CAPACITY_SIZE) return false;

				//새버퍼를 생성하여 바꿔치기
				auto temp = m_buffer;

				m_bufferSize += DEFAULT_CAPACITY_SIZE;
				m_buffer = new char[m_bufferSize];
				memmove(m_buffer, temp + m_readSize, m_writeSize - m_readSize);
				m_writeSize -= m_readSize;
				m_readSize = 0;

				if (temp != nullptr)
				{
					delete[] temp;
					temp = nullptr;
				}
			}
		}

		wsabuf.buf = GetEmpty();
		wsabuf.len = GetEmptySize();

		if (wsabuf.len <= 0) return false;

		return true;
	}
}
