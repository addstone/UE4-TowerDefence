#pragma once

#include "CoreMinimal.h"

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
};