
#include "CoreMinimal.h"

enum EScreenMoveState
{
	Screen_None,
	Screen_Up,
	Screen_Down,
	Screen_Right,
	Screen_Left,
	Screen_RightAndUp,
	Screen_RightAndDown,
	Screen_LeftAndUp,
	Screen_LeftAndDown,
	Screen_Max
};

class APlayerController;

//��Ļ�ƶ�
struct STONETOOLCLASS_API FScreenMoveUnit
{
	//������Ļ���ƶ�
	bool ListenScreenMove(APlayerController* PlayerController, const float &ScreenMoveSpeed);

protected:
	/*
	��ȡ��ǰ���ƶ�״̬
	@param PlayerController ��ҿ���
	@return ���ص�ǰ��׽����״̬
	*/
	EScreenMoveState CursorMove(const APlayerController* PlayerController);

	/*
	�ǵ�ǰ��Pawn��������ƶ�
	@param PlayerController ��ҿ���
	@param ScreenMoveState �ƶ���״̬
	@param ScreenMoveSpeed ��Ļ�ƶ����ٶ�
	@return ���ص�ǰ�Ƿ��ƶ��ɹ�
	*/
	bool MoveDirection(APlayerController* PlayerController, EScreenMoveState ScreenMoveState, const float &ScreenMoveSpeed);
};