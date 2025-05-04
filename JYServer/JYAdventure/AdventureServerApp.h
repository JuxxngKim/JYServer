#pragma once

namespace jy
{
	class AdventureServerApp
	{
	private:
		bool m_exit{ false };

	public:
		AdventureServerApp();
		virtual ~AdventureServerApp();
		void Start();

	private:
		bool RunLoop();
		bool InitLogger();
	};

}