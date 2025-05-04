#include "ProjectJY.h"
#include "AdventureServerApp.h"

namespace jy
{
	AdventureServerApp::AdventureServerApp()
	{
	}

	AdventureServerApp::~AdventureServerApp()
	{
	}

	void AdventureServerApp::Start()
	{
		if (!InitLogger()) return;

		RunLoop();
	}

	bool AdventureServerApp::RunLoop()
	{
		while (true)
		{

		}

		return true;
	}

	bool AdventureServerApp::InitLogger()
	{
		const auto& logLevel = spdlog::level::debug;
		const auto& dir = "../log";
		const auto& name = "JYAdventure";
		const bool result = Logger::GetInstance().Init(logLevel, dir, name);
		if (!result) return false;

		S_LOG_INFO("Logger Init");
		S_LOG_INFO("Login AccountUID: {}",123);
		return true;
	}
}
