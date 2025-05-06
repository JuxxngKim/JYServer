#pragma once

#ifdef _DEBUG
#	pragma comment(lib, "spdlogd.lib")
#else
#	pragma comment(lib, "spdlog.lib")
#endif

#ifdef _DEBUG
#	pragma comment(lib, "libprotobufd.lib")
#else
#	pragma comment(lib, "libprotobuf.lib")
#endif

