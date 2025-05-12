#pragma once

namespace jy
{
	class Logger : public Singleton<Logger>
	{
	private:
		PTR<spdlog::logger> m_logger;
		std::string m_loggerName{};
		std::string m_logFilePath{};
		bool m_isInitialized{ false };

	public:
		Logger() = default;
		virtual ~Logger() = default;
		void Exit();

	public:
		bool Init(spdlog::level::level_enum logLevel, const std::string& baseLogDir, const std::string& executableName);

        template<typename... Args>
        void Trace(spdlog::format_string_t<Args...> fmt, Args &&... args)
        {
            if (m_logger) { m_logger->trace(fmt, std::forward<Args>(args)...); }
        }
        template<typename... Args>
        void Debug(spdlog::format_string_t<Args...> fmt, Args &&... args)
        {
            if (m_logger) { m_logger->debug(fmt, std::forward<Args>(args)...); }
        }
        template<typename... Args>
        void Info(spdlog::format_string_t<Args...> fmt, Args &&... args)
        {
            if (m_logger) { m_logger->info(fmt, std::forward<Args>(args)...); }
        }
        template<typename... Args>
        void Warn(spdlog::format_string_t<Args...> fmt, Args &&... args)
        {
            if (m_logger) { m_logger->warn(fmt, std::forward<Args>(args)...); }
        }
        template<typename... Args>
        void Error(spdlog::format_string_t<Args...> fmt, Args &&... args)
        {
            if (m_logger) { m_logger->error(fmt, std::forward<Args>(args)...); }
        }
        template<typename... Args>
        void Critical(spdlog::format_string_t<Args...> fmt, Args &&... args)
        {
            if (m_logger) { m_logger->critical(fmt, std::forward<Args>(args)...); }
        }
	};
}

//#define S_LOG_TRACE(fmt, ...)    Logger::GetInstance().Trace(fmt, ##__VA_ARGS__)
//#define S_LOG_DEBUG(fmt, ...)    Logger::GetInstance().Debug(fmt, ##__VA_ARGS__)
//#define S_LOG_INFO(fmt, ...)     Logger::GetInstance().Info(fmt, ##__VA_ARGS__)
//#define S_LOG_WARN(fmt, ...)     Logger::GetInstance().Warn(fmt, ##__VA_ARGS__)
//#define S_LOG_ERROR(fmt, ...)    Logger::GetInstance().Error(fmt, ##__VA_ARGS__)
//#define S_LOG_CRITICAL(fmt, ...) Logger::GetInstance().Critical(fmt, ##__VA_ARGS__)

#ifndef JY_TEXT
#define JY_TEXT(str) str
#endif

#define S_LOG_DEBUG(hostID, accountUID, fmt, ...) \
    { { Logger::GetInstance().Debug(JY_TEXT("hostID:{} accountUID:{} " fmt), hostID, accountUID, ##__VA_ARGS__); } }

#define S_LOG_INFO(hostID, accountUID, fmt, ...) \
    { { Logger::GetInstance().Info(JY_TEXT("hostID:{} accountUID:{} " fmt), hostID, accountUID, ##__VA_ARGS__); } }

#define S_LOG_WARN(hostID, accountUID, fmt, ...) \
    { { Logger::GetInstance().Warn(JY_TEXT("hostID:{} accountUID:{} " fmt), hostID, accountUID, ##__VA_ARGS__); } }

// S_LOG_ERROR는 __FUNCTION__ (현재 함수 이름)을 추가
#define S_LOG_ERROR(hostID, accountUID, fmt, ...) \
    { { Logger::GetInstance().Error(JY_TEXT("hostID:{} accountUID:{} [{}] " fmt), hostID, accountUID, static_cast<const char*>(__FUNCTION__), ##__VA_ARGS__); } }

#define S_LOG_CRITICAL(hostID, accountUID, fmt, ...) \
    { { Logger::GetInstance().Critical(JY_TEXT("hostID:{} accountUID:{} [{}] " fmt), hostID, accountUID, static_cast<const char*>(__FUNCTION__), ##__VA_ARGS__); } }
