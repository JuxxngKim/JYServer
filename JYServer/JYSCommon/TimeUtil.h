﻿#pragma once
#include <iomanip>
#include "SDateTime.h"

namespace util
{
	class TimeUtil : public Singleton<TimeUtil>
	{
	private:
		std::atomic<int64_t> m_diffSec;

	public:
		TimeUtil();
		virtual ~TimeUtil() = default;

		//////////////////
		// 기본 적으로 서버에서는 KST를 사용하도록한다.
		/////////////////

		void ChangeTime(const uint16_t& year, const uint16_t& month, const uint16_t& day, const uint16_t& hour, const uint16_t& minute, const uint16_t& second);
		void ResetTimeGap();
		int64_t FindTimeGap();

		SDateTime FindSystemKSTDate() const;
		SDateTime FindKSTDate() const;
		int64_t FindTickKSTMs(const int64_t& spanMs = 0) const;
		int64_t FindKSTMs() const;
		int64_t FindKSTMs(const int64_t& spanMs) const;
		int64_t FindIntervalSeconds(const SDateTime& start, const SDateTime& end) const;
		int32_t FindCompareTimeMs(const int64_t& t1, const int64_t& t2) const;
		bool NeedToDailyRenewal(const int64_t& befMs, const int64_t& curMs, const int32_t& resetHour);
		bool NeedToWeeklyRenewal(const int64_t& befMs, const int64_t& curMs, const int32_t& resetHour, const int32_t& resetDayOfWeek);
		bool NeedToMonthlyRenewal(const int64_t& befMs, const int64_t& curMs, const int32_t& resetHour, const int32_t& resetDay);
		SDateTime AddHourSDateTimeToKSTDate(const SDateTime& time, const int32_t& addHour) const;
		SDateTime AddDaySDateTimeToKSTDate(const SDateTime& time, const int32_t& addDay) const;
		SDateTime ConvertSDateTimeFromString(const std::string& timeString) const;
		SDateTime ConvertKSTDateFromISO8601(const std::string& timeString) const;
		SDateTime ConvertKSTDateFromISO8601WithMS(const std::string& timeString) const;
		bool IsInPeriod(const SDateTime& time1, const SDateTime& time2, const SDateTime& pivotTime) const;
		SDateTime AddSecondsSDateTimeToKSTDate(const SDateTime& time, const int64_t& addSeconds) const;
		SDateTime AddMinutesSDateTimeToKSTDate(const SDateTime& time, const int64_t& addMinutes) const;
		SDateTime FindAfterSecondsSDateTimeToKSTDate(const int64_t& afterSeconds) const;
		static std::string ToString(const SDateTime& time);
		static std::string SystemTimeToString(const _SYSTEMTIME& time);
		static std::string ToISO8601Format(const SDateTime& time);
		int64_t ConvertSDateTimeToKSTTimeMs(const SDateTime& time) const;
		SDateTime ConvertKSTTimeMsToSDateTime(const int64_t& timeMilli) const;
		int64_t FindDailyRenewalUTCTimeMS(const int32_t& resetHour) const;
		SDateTime FindTimeAfterRepeatedSeconds(const SDateTime& start, const int64_t& seconds) const;
		SDateTime FindDateTimeByDayAndHour(const SDateTime& curDateTime, const int32_t& dayOfWeek, const int32_t& hour) const;
		SDateTime FindNextDateTimeByDayAndHour(const SDateTime& curDateTime, const int32_t& dayOfWeek, const int32_t& hour) const;
		SDateTime FindNextDateTimeByHour(const SDateTime& curDateTime, const int32_t& hour) const;
		SDateTime MakeScheduleTime(const SDateTime& defaultDateTime, const int32_t& addDay, const SDateTime& settingTime) const;
		int64_t ConvertKSTMsToUTCMs(const int64_t& time) const;
		int64_t ConvertUTCMsToKSTMs(const int64_t& time) const;
		SDateTime FindLastDailyResetTime(const int32_t& resetHour) const;
		SDateTime FindLastWeeklyResetTime(const int32_t& resetDay, const int32_t& resetHour) const;
		SDateTime FindLastMonthlyResetTime(const int32_t& resetDay, const int32_t& resetHour) const;
		SDateTime FindNextDailyResetTime(const int64_t& curMs, const int32_t& resetHour) const;
		SDateTime FindNextWeeklyResetTime(const int64_t& curMs, const int32_t& resetHour, const int32_t& resetDayOfWeek) const;
		SDateTime FindNextMonthlyResetTime(const int64_t& curMs, const int32_t& resetHour, const int32_t& resetDay) const;
		SDateTime FindNextDailyResetTime(const SDateTime& lastUpdateTime, const int32_t& resetHour) const;
		SDateTime FindNextWeeklyResetTime(const SDateTime& lastUpdateTime, const int32_t& resetDayOfWeek, const int32_t& resetHour) const;
		SDateTime FindNextMonthlyResetTime(const SDateTime& lastUpdateTime, const int32_t& resetDay, const int32_t& resetHour) const;
		SDateTime FindLastDailyResetTime(const SDateTime& lastUpdateTime, const int32_t& resetHour) const;
		SDateTime FindLastWeeklyResetTime(const SDateTime& lastUpdateTime, const int32_t& resetDayOfWeek, const int32_t& resetHour) const;
		SDateTime FindMinDateTime() const;
		SDateTime FindMaxDateTime() const;
		int32_t FindDayAfterNextResetHour(const int64_t& befMs, const int64_t& curMs, const int32_t& resetHour) const;

	private:
		int64_t FindKSTTime_t() const;
		SDateTime ConvertTmToSDateTime(const std::tm& tm, const int32_t& milliSec) const;

		//////////////////
		// UTC 함수들은 클라이언트에 시간 값을 보내줄 때에만 사용하도록 한다.
		// 이외의 시간 계산은 모두 KST로 하자
		/////////////////
	public:
		int64_t FindUTCMs() const;
		int64_t FindUTCMs(const int64_t& spanMs) const;
		int64_t FindCorrectIntervalSeconds(const SDateTime& start, const SDateTime& end) const;
		int64_t FindCorrectIntervalDays(const SDateTime& start, const SDateTime& end) const;
		int64_t FindCorrectIntervalWeeklys(const SDateTime& start, const SDateTime& end) const;
		int64_t ConvertSDateTimeToUTCTimeMs(const SDateTime& time) const;
		SDateTime ConvertKSTDateTimeToUTCDateTime(const SDateTime& kstDateTime) const;

	private:
		int64_t FindUTCTime_t() const;
		int64_t FindEpochTime(const SDateTime& time) const;


	public:
		friend std::ostream& operator<<(std::ostream& os, TimeUtil* time)
		{
			if (time == nullptr) return os;

			auto curTime = time->FindKSTDate();
			os << curTime.Year << "-"
				<< std::setfill('0') << std::setw(2) << curTime.Month << "-"
				<< std::setfill('0') << std::setw(2) << curTime.Day << " "
				<< std::setfill('0') << std::setw(2) << curTime.Hour << ":"
				<< std::setfill('0') << std::setw(2) << curTime.Minute << ":"
				<< std::setfill('0') << std::setw(2) << curTime.Second;

			return os;
		}
	};
}