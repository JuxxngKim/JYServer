#pragma once

//MaxPacket
const int32_t			g_MaxPacketSize = 48 * 1024;
const int32_t			g_PacketHeaderSize = 8;
const int32_t			g_PacketBodySize = g_MaxPacketSize - g_PacketHeaderSize;
const int32_t			g_PacketDefaultSize = 1000;

const int32_t			NETWORK_ALIVE_MS = 15000;
const int32_t			NETWORK_TIMEOUT_MS = NETWORK_ALIVE_MS * 3;

//HeroDeck
const int32_t			g_iHeroInDeckCount = 4;
const int32_t			g_iHeroInRaidDeckCount = 8;
const int32_t			g_iMaxHeroDeckCount = 8;

const int32_t			g_iProbabilityMax = 1000000;
const int32_t			g_iMaxEnchantMaterialItem = 5;

//Sell Item
const int32_t			g_iMaxSellItemCount = 50;

//Friend
const int32_t			g_iMaxSendFriendCount = 50;									// 최대 친구 요청수
const int32_t			g_iMaxRecvFriendCount = 50;									// 최대 요청받기 가능한 친구수
const int32_t			g_iMaxFriendCount = 50;										// 최대 친구수
const int32_t			g_iLimitDelAtReqTimeHour = 24;								// 친구 삭제후 다시 요청 받을수 있는 시간(시)
const int32_t			g_iLimitRefusalAtReqTimeHour = 24;							// 친구 거절후 다시 요청 할수 있는 시간(시)
const int32_t			g_iDailyDeleteFriend = 10;									// 일일 친구 삭제 제한수
const int32_t			g_iFriendRefreshTime = 60;									// 친구 리스트 요청후 재 갱신 타임 (초)
const int32_t			g_iFriendRefreshTickTime = (g_iFriendRefreshTime * 1000);	// 친구 리스트 요청후 재 갱신 타임
const int32_t			g_iMaxRecommendFriendCount = 10;							// 추천 친구 최대 개수
const int32_t			g_iSplitFriendInfoPacketData = 50;							// 친구 패킷 데이터를 나눠서 보내 최대수
const int32_t			g_iRecvFriendPointSyncTimeTermSec = (10 * 60);				// 친구 우정포인트 받기 처리 로직 실행 주기 (초)
const int32_t			g_iFriendPointSendAllintervalSec = 10;						// 친구 우정포인트 보내기 패킷 연속 사용 딜레이(초)
const int32_t			g_iFriendOfflineRecommendIntervalMs = 1000 * 60;			// 오프라인 친구 추천 목록(ms)
const int32_t			g_iMaxFriendRecommendCount = 200;								// 오프라인 친구 추천 최대 갯수

//Arena
const int32_t			g_iArenaListRefreshChargedTerm = (10 * 60);					// 결투장 리스트 갱신 주기(초)
const int32_t			g_iArenaRankRefreshTickTime = (1 * 60 * 1000);				// 결투장 리스트 로드후 다시 로드해오는 시간
const int32_t			g_iArenaFriendRankRefreshTimeSecond = (1 * 60);					// 결투장 친구 리스트 로드후 다시 로드해오는 시간
const int32_t			g_iArenaPageViewCount = 50;									// 한페이지에 보여주는 개수
const int32_t			g_iArenaListRefreshCrystal = 100;							// 결투장 리스트 갱신시 비용
const int32_t			g_iArenaDefaultRakingValue = 9999999;						// 랭킹 디폴트 값
const int32_t			g_iArenaRefreshTickTime = (2 * 60 * 1000);						// 결투장 정보요청후 재 갱신 타임
const int32_t			g_iArenaDefaultRankScoreValue = 1000;						// 결투장 기본 점수
const int32_t			g_iArenaMatchRefreshChargedTerm = 1;						// 결투장 매칭 리스트 갱신 주기 (분)
const int32_t			g_iMaxArenaTournamentPresetCount = 5;						// 세나컵 프리셋 최대 개수

// vector reserve
const int32_t			g_iMaxProgressQuestCount = 5;
const int32_t			g_iMaxHeroAlbumExpertOptionCount = 5;
const int32_t			g_iMaxRelationAlbumCount = 30;
const int32_t			g_iMaxContentOpenCount = 100;
const int32_t			g_iMaxUnlimitedTowerRewardCount = 4;
const int32_t			g_iMaxWorld = 7;
const int32_t			g_iMaxPartyAdventureTicket = 10;
const int32_t			g_iMaxArenaRanking = 50;
const int32_t			g_iMaxArenaCompetitionMatchList = 5;
const int32_t			g_iMaxBlockPlayerList = 50;
const int32_t			g_iMaxHero = 35;
const int32_t			g_iMaxItem = 200;
const int32_t			g_iMaxMasteryGroup = 5;
const int32_t			g_iMaxContentClear = 20;
const int32_t			g_iMaxRandomShopGoodsCount = 7;
const int32_t			g_iMaxShopBuffList = 3;
const int32_t			g_iMaxShopCash = 5;
const int32_t			g_iMaxSql = 15;
const int32_t			g_iMaxHeroDeck = 20;
const int32_t			g_iMaxLBRate = 3;
const int32_t			g_iMaxGuildMember = 5;
const int32_t			g_iMaxQuestReward = 6;
const int32_t			g_iMaxRankingData = 50;
const int32_t			g_iMaxRandomBoxList = 100;
const int32_t			g_iMaxItemDecomposeReward = 8;
const int32_t			g_iMaxGoodsDetailGacha = 2;
const int32_t			g_iMaxEventFlyer = 3;
const int32_t			g_iMaxShopRandomGroupList = 40;
const int32_t			g_iMaxShopRandomProbabilityList = 65;
const int32_t			g_iMaxSelectBoxList = 30;
const int32_t			g_iMaxContentReward = 3;
const int32_t			g_iMaxPackageDetail = 3;
const int32_t			g_iMaxDeckBanList = 6;
const int32_t			g_iMaxLocalAddress = 2;
const int32_t			g_iMaxSkillSetting = 11;
const int32_t			g_iMaxGuildAchieve = 3;
const int32_t			g_iSqlOutputMaxLength = 1024 * 2;
const int32_t			g_iMaxSendBytes = 8000;
const int32_t			g_iRetryLoginCount = 10;
const int32_t			g_iRetryLoginTick = 1000;
const int32_t			g_iKickPlayerTick = 1000;
const int32_t			g_iWaitingRetryLogin = 2000;
const int32_t			g_iMaxShopMonthlyRewardList = 3;
const int32_t			g_iPenaltyCheckTick = 10000;
const int32_t			g_iMaxContentStateStack = 4;
const int32_t           g_iMaxRankingPage = 6;
const int32_t           g_iMaxRankingDisplayPage = 4;
const int32_t           g_iMaxRankingRewardCount = 4;
const int32_t           g_iGameToolReward = 1000;
const int32_t			g_maxWishPathSize = 2;
const int32_t			g_emptyWishPathIndex = -1;
const int32_t			g_iMaxEventTabList = 50;
const int32_t			g_iMaxRankingBuffSkillIDVec = 6;
const int32_t           g_iMaxAccountCombatPowerRankingPage = 20;


const int32_t		g_SqlOutputMaxLength = 1024 * 2;
const int32_t		g_SystemDBActorId = 0;
constexpr int32_t	g_MaxActorCount = 20'000;
constexpr int64_t	g_KoreaTimeZoneS = 32'400;
constexpr int64_t	g_KoreaTimeZoneMS = 32'400'000;
constexpr int32_t	g_LogicAlarmLimitMs = 500;
const int32_t		g_MaxLogicUnitPlayerCount = 4;
const int32_t		g_MaxBlcokDuplicatePacketCount = 100000;
const int32_t		g_LogicUpdateMs = 200;
const int32_t		g_PlayerFrequencyUpdateMs = 1000;
const int32_t		g_PlayerShortTermUpdateMs = 9'000;
const int32_t		g_PlayerLongTermUpdateMs = 30'000;
const int32_t		g_SkillEnchanceStar = 6;
const int32_t		g_PlayerLoadBalanceUpdateMs = 500;
const int32_t		g_MaxTargetSkillCount = 5;
const int32_t		g_MaxPlayer = 1;
const int32_t		g_MaxCharacterCount = 10;
const int32_t		g_MaxReserveSkillCount = 3;
const int32_t		g_TenThousandPercent = 10000;
const int32_t		g_MaxAdventurePlayerCount = 1000;
const int32_t		g_MaxGameDBPlayerCount = 2000;
const int32_t		g_MinSkillReinforceLevel = 0;
const int32_t		g_MaintenanceServerUpdateTimeMS = 30'000;
const int32_t		g_RollingMessageUpdateTimeMS = 10'000;
const int32_t		g_UpdateLogicServiceMetricUpdateTimeMS = 5000;
const int32_t		g_UpdateSingleServiceMetricUpdateTimeMS = 1000;
const int32_t		g_LogicServiceTickDurationBucket = 30;
const int32_t		g_SingleServiceTickDurationBucket = 10;
constexpr int32_t	g_LoginExpireUpdateTimeMS = 5 * 60 * 1000;
const std::string	g_LoginAwaiterTTL = "10";     // 서버 접속 대기 PID TTL(10초)
const int32_t		g_MaxDuplicatePacketCount = 10;

// Time
const int32_t		g_InitializeYearValue = 1900;
const int32_t		g_InitializeMonthValue = 1;
const int32_t		g_InitializeDayValue = 1;
const int32_t		g_MaxDayOfWeek = 7;
const int32_t		g_NetworkDelay = 200;
const int32_t		g_ServerReadyCheckTime = 1000;
const int32_t		g_ReloadDataSyncMs = 30'000;
const int32_t		g_CheckDBDisconnect = 5 * 1'000;
const int32_t		g_SecToMs = 1000;
const int32_t		g_oneDayHours = 24;
const int8_t		g_UTCToKSTOffset = 9;
const int32_t		g_secToDay = 86400;
const int32_t		g_secToWeek = 604800;
const int32_t		g_HoursPerDay = 24;
const int32_t		g_DaysPerWeek = 7;
const int32_t		g_ServerInfoSyncMs = 10'000;
constexpr int64_t	g_ServerShutdownCheckMinTimeMS = static_cast<int64_t>(g_ServerInfoSyncMs) * 2;
const int32_t		g_DefaultShutdownCheckTimeSec = 30;
const int32_t		g_biCurrentUserSyncMs = 60'000;
constexpr int32_t	g_A_MinuteSec = 60;		// 60 sec - 1 minute.
constexpr int32_t	g_SecsPerHour = 3600;
const int32_t		g_PlayerCountSyncMs = 5000;
const int32_t		g_AdventureServerAliveSyncMs = 1000;

// Name
constexpr int32_t g_DefaultUTF8CharacterLengh = 3;		// utf8 글자 길이
constexpr int32_t g_DefaultWideCharacterLengh = 2;		// wide 캐릭터 글자 길이

// Gateway
constexpr int32_t g_WaitingQueuePerPlayer = 50;
constexpr int32_t g_WaitingOrderUpdateTimeMs = 5'000; // 대기열 대기 순서 업데이트 주기
constexpr int32_t g_WaitingQueuePopupShowWaitingTimeMs = 10'000; // 대기열 팝업 보여줄때까지 기다리는 시간

// PreOrderSkill
constexpr int32_t g_MaxPreOrderSkillCount = 3;

// Chatting
constexpr int32_t g_ChattingUpdateTimeMs = 500;
constexpr int32_t g_MaxChattingStreamThreshold = 100'000;
constexpr int32_t g_MaxRedisReconnectCount = 10;
constexpr int32_t g_DefaultChattingListPerPage = 20;
constexpr int32_t g_ChatRedisReconnectTermMs = 30000; // 30초에 한번 재연결 시

// xigncode
constexpr int64_t g_XignCodeServiceEventIntervalMs = 10'000; // 10초
constexpr int32_t g_XignCodeDataExportCount = 20; // XignCodeService의 Prepare에서 XAXignCodeDataNoti의 데이터를 묶어보낼 수

// 순차점검
constexpr int32_t g_PairServerGap = 1000;	// 순차점검시 짝이 되는 서버의 ID와 Port는 1000 차이가 난다.

// 모험, 계정 랭킹
constexpr int32_t g_CommonRankingSyncTimeMs = 600'000;	// 모험 랭킹 갱신 주기 10분
constexpr int32_t g_CommonRankingUpdateTimeMs = 1'000; // 모험, 계정 랭킹 틱 업데이트 주기
constexpr int32_t g_MaxRankingRedisExpireDay = 90;		// 랭킹 레디스 만료 기간.(일)
constexpr int32_t g_MaxRankingRedisExpireSec = 7776000;		// 랭킹 레디스 만료 기간.(초)
constexpr int32_t g_CommonRankingLimit = 100;	// 랭킹 최대 캐싱 수
