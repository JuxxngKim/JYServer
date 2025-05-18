#pragma once

namespace jy
{
	enum class EPlayerType
	{
		None,
		NewPlayer, // 신규
		NormalPlayer, // 일반
		ReturnPlayer, // 복귀
		Max,
	};

	enum class ELoginData
	{
		Player = 0,
		Hero,
		EquipItem,
		Max,
	};

	enum class ETraceMessageLevel
	{
		Disable = 0,
		HighLevel = 1,
		LowLevel = 2,
	};
} 