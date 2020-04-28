#pragma once

#include "CoreMinimal.h"
#include "../StoneDefenceType.h"


class IRuleOfCharacter
{
public:
	//是否死亡
	virtual bool IsDeath() = 0;
	//获取生命值
	virtual float GetHealth() = 0;
	//获取最大生命值
	virtual float GetMaxHealth() = 0;
	//是否为一个队伍
	virtual bool IsTeam() = 0;

	virtual EGameCharacterType::Type GetType() = 0;
};