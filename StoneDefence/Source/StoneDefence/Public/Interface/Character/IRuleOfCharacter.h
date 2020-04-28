#pragma once

#include "CoreMinimal.h"
#include "../StoneDefenceType.h"


class IRuleOfCharacter
{
public:
	//�Ƿ�����
	virtual bool IsDeath() = 0;
	//��ȡ����ֵ
	virtual float GetHealth() = 0;
	//��ȡ�������ֵ
	virtual float GetMaxHealth() = 0;
	//�Ƿ�Ϊһ������
	virtual bool IsTeam() = 0;

	virtual EGameCharacterType::Type GetType() = 0;
};