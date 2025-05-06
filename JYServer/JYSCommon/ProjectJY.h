#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define NOMINMAX
#define WINSOCK_DEPRECATED_NO_WARNINGS
#define SPDLOG_USE_STD_FORMAT

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <utility>
#include <conio.h>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <format>
#include <stdexcept>
#include <spdlog/spdlog.h>

#include "Allocator.h"
#include "Singleton.h"
#include "Logger.h"

#include "../../../../Common/Tool/ProtocolGenerator/generated/protocol.pb.h"
