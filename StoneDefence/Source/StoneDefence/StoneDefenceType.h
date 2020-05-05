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
	BULLET_DIRECT_LINE, //���ϰ�ֱ�߹���
	BULLET_LINE,//�Ǹ���
	BULLET_TRACK_LINE,//����
	BULLET_RANGE,//��Χ�˺�
	BULLET_CHAIN,
};