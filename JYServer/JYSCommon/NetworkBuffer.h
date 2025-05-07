#pragma once

namespace jy
{
	using PacketInfo = std::tuple<int /*messageID*/, char* /*messageBuffer*/, int /*messageSize*/>;

	class NetworkBuffer
	{
	private:
		char* m_buffer;
		int32_t m_bufferSize;
		int32_t m_writeSize;
		int32_t m_readSize;

	public:
		NetworkBuffer();
		virtual ~NetworkBuffer();

		bool Write(void* src, int32_t srcSize);
		bool CompleteWrite(int size);

		bool Read(void* dest, int32_t destSize);
		bool CompleteRead(int32_t size);

		char* GetData();
		int32_t GetDataSize();

		char* GetEmpty();
		int32_t GetEmptySize();

		bool PacketToByte(int32_t packetId, google::protobuf::Message& packet);
		PacketInfo ByteToPacket();

		bool ReadyToRecv(WSABUF& wsabuf);
	};
}