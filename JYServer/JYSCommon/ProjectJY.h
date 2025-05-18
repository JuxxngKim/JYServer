#pragma once

#pragma warning(disable : 4819) //내용 : 현재 코드 페이지(949)에서 표시할 수 없는 문자가 파일에 들어 있습니다. 데이터가 손실되지 않게 하려면 해당 파일을 유니코드 형식으로 저장하십시오.
#pragma warning(disable : 4996)	//내용 : 'fopen' 대신 보안함수 사용할 것. 내비메시에서 발생.
#pragma warning(disable : 4503) //warning C4503: 'std::_Vector_alloc<std::_Vec_base_types<_Ty,_Alloc>>': 데코레이팅된 이름 길이를 초과했으므로 이름이 잘립니다.

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define NOMINMAX
#define WINSOCK_DEPRECATED_NO_WARNINGS
#define SPDLOG_USE_STD_FORMAT

#include "../../../../Common/Tool/ProtocolGenerator/generated/protocol.pb.h"

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <deque>
#include <utility>
#include <conio.h>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <format>
#include <regex>
#include <stdexcept>
#include <spdlog/spdlog.h>

#include "SDateTime.h"
#include "Allocator.h"
#include "Singleton.h"
#include "DefineEnum.h"
#include "DefineType.h"
#include "DefineConst.h"
#include "DefineMacro.h"
#include "TimeUtil.h"
#include "Logger.h"
#include "NetworkManager.h"