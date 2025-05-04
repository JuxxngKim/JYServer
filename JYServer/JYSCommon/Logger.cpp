#include "ProjectJY.h"
#include "Logger.h"
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/async.h>

namespace jy
{
	bool Logger::Init(spdlog::level::level_enum logLevel,
		const std::string& baseLogDir,
		const std::string& executableName)
	{
		if (m_isInitialized) return true;

		const std::string logPattern = "[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [threadID:%t] %v";
		const size_t queueSize = 3000;
		const size_t threadCount = 1;

		try
		{
			static bool threadPoolInitialized = false;
			if (!threadPoolInitialized)
			{
				spdlog::init_thread_pool(queueSize, threadCount);
				threadPoolInitialized = true;
			}

			std::vector<spdlog::sink_ptr> sinks;

			auto consoleSink = NEW(spdlog::sinks::stdout_color_sink_mt);
			sinks.push_back(consoleSink);

			std::string dateStr;
			std::string timestampStr;
			std::filesystem::path logFilePath;

			try
			{
				auto now = std::chrono::system_clock::now();
				const auto* kstZone = std::chrono::locate_zone("Asia/Seoul");
				std::chrono::zoned_time kstNow{kstZone, now};
				auto kstLocalTime = kstNow.get_local_time();
				auto kstLocalSeconds = std::chrono::floor<std::chrono::seconds>(kstLocalTime);

				dateStr = std::format("{:%y%m%d}", kstLocalSeconds);
				std::string timeStr = std::format("{:%H%M%S}", kstLocalSeconds);

				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
				std::string msStr = std::format("{:03}", ms.count());
				timestampStr = timeStr + msStr;

				std::filesystem::path logDirectory = std::filesystem::path(baseLogDir) / dateStr;
				std::filesystem::create_directories(logDirectory);
				std::string logFilename = executableName + "-" + timestampStr + ".log";
				logFilePath = logDirectory / logFilename; // 파일 경로 저장

			}
			catch (const std::exception& timeEx)
			{
				std::cerr << "Error getting KST time or formatting: " << timeEx.what() << std::endl;
				throw std::runtime_error("Failed to process KST time for log file path.");
			}

			auto fileSink = NEW(spdlog::sinks::basic_file_sink_mt, logFilePath.string(), false);
			sinks.push_back(fileSink);

			if (sinks.empty())
			{
				std::cerr << "Warning: No sinks specified for logger. Adding default console sink." << std::endl;
				auto defaultConsoleSink = NEW(spdlog::sinks::stdout_color_sink_mt);
				sinks.push_back(defaultConsoleSink);
			}

			m_logger = NEW(spdlog::async_logger, "app_logger", begin(sinks), end(sinks),
				spdlog::thread_pool(), spdlog::async_overflow_policy::block);

			m_logger->set_level(logLevel);
			m_logger->set_pattern(logPattern); // 비동기 로거도 패턴 설정 동일

			spdlog::register_logger(m_logger); // 비동기 로거도 등록 가능

			m_isInitialized = true;
			return true;
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			std::cerr << "Logger initialization failed (spdlog): " << ex.what() << std::endl;
			m_isInitialized = false;
			m_logger.reset();
		}
		catch (const std::filesystem::filesystem_error& fs_ex)
		{
			std::cerr << "Logger initialization failed (filesystem): " << fs_ex.what() << std::endl;
			m_isInitialized = false;
			m_logger.reset();
		}
		catch (const std::exception& e)
		{
			std::cerr << "Logger initialization failed (std): " << e.what() << std::endl;
			m_isInitialized = false;
			m_logger.reset();
		}
		catch (...)
		{
			std::cerr << "Logger initialization failed (unknown exception)." << std::endl;
			m_isInitialized = false;
			m_logger.reset();
		}

		return false;
	}

}