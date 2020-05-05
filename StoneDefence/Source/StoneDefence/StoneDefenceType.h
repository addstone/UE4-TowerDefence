#pragma once

#include "CoreMinimal.h"
#include "StoneDefenceType.generated.h"

UENUM()
namespace EGameCharacterType
{
	enum Type
	{
		TOWER,
		MAIN_TOWER,
		MONSTER,
		BOSS_MONSTER,
		MAX
	};
}

UENUM(BlueprintType)
enum class EBulletType :uint8
{
	BULLET_DIRECT_LINE, //ÎÞÕÏ°­Ö±Ïß¹¥»÷
	BULLET_LINE,//·Ç¸ú×Ù
	BULLET_TRACK_LINE,//¸ú×Ù
	BULLET_RANGE,//·¶Î§ÉËº¦
	BULLET_CHAIN,
};