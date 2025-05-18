﻿#pragma once

using HostID_t = int32_t;
using Int64Key = int64_t;
using ActorID_t = Int64Key;
//using JsonDoc = rapidjson::GenericDocument<rapidjson::UTF8<>, rapidjson::CrtAllocator>;

namespace jy
{
	class ConcurrentActorRef;

	using AccountUID_t = Int64Key;
	using FieldUID_t = Int64Key;
	using Mailbox_t = ConcurrentActorRef;
	using ObjectID_t = int32_t;
	using HeroUID_t = Int64Key;
	using ItemUID_t = Int64Key;
	using LogKey = Int64Key;
	using LogType = int32_t;
	using PetUID_t = Int64Key;
	using PetTID_t = int32_t;
	using ShopTID_t = int32_t;
	using ShopGoodsTID_t = int32_t;
	using GuildID_t = int32_t;
	using TagID_t = int32_t;
	using GuildSkillID_t = int32_t;
	using GachaTID_t = int32_t;
	using ModuleID_t = int64_t;
	using DrawGroupID_t = int32_t;
	using DrawListID_t = int32_t;
	using CeilingTID_t = int32_t;
	using ConversionTID_t = int32_t;
	using CombinationTID_t = int32_t;
	using SkillID_t = int32_t;
	using EventMainTID_t = int32_t;
	using MissionTID_t = int32_t;
	using AccountBuffID_t = int32_t;
	using StageID_t = int32_t;
	using Seq_t = int32_t;
	using CostumeID_t = int32_t;
	constexpr StageID_t InvalidStageID = 0;
	constexpr Seq_t InvalidSeq = 0;
}