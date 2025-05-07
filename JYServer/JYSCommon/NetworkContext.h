#pragma once

namespace jy
{
	using NetworkCallback = std::function<void(HostID_t, int, const PTR<google::protobuf::Message>&)>;

	const int		MAX_SERIALIZER_COUNT = 4;	// 시리얼라이저 쓰레드 갯수
	const int		MAX_WORKER_COUNT = 4;		// 워커 쓰레드 갯수

	const HostID_t	MIN_HOST_ID = 1;
	const HostID_t	MAX_HOST_ID = 2000000000;
	const int64_t	UPDATE_HOST_INTERVAL_MS = 5000;		// 워커 쓰레드 갯수

	const int		MIN_CAPACITY_SIZE = 8 * 1024; //사용가능한 최소 사이즈
	const int		DEFAULT_CAPACITY_SIZE = MIN_CAPACITY_SIZE * 2; //버퍼 생성 혹은 늘릴때 사이즈
	const int		MAX_CAPACITY_SIZE = 1024 * 1024; // 1MB 패킷제한

	const int		MAX_ACCEPT_COUNT = 100;

	const int		MAX_ADDRESS_SIZE = (sizeof(SOCKADDR_IN) + 16) * 2;

	namespace ENetworkHost
	{
		enum Type
		{
			None = 0,
			Connecter,
			Listener,
			Accepter,
		};
	}

	namespace ENetworkTask
	{
		enum Type
		{
			None = 0,
			Connect,
			Accept,
			Receive,
			Send,
		};
	};

	namespace ENetworkEvent
	{
		enum Type
		{
			None = 0,
			Task,
			Connect,
			Listen,
			Accept,
			Send,
			Close,
		};
	};

	namespace ESerialize
	{
		enum Type
		{
			None = 0,
			Started,
			Completed,
		};
	}
}