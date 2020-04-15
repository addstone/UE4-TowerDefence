
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

//屏幕移动
struct STONETOOLCLASS_API FScreenMoveUnit
{
	//监听屏幕的移动
	bool ListenScreenMove(APlayerController* PlayerController, const float &ScreenMoveSpeed);

protected:
	/*
	获取当前的移动状态
	@param PlayerController 玩家控制
	@return 返回当前捕捉到的状态
	*/
	EScreenMoveState CursorMove(const APlayerController* PlayerController);

	/*
	是当前的Pawn随着鼠标移动
	@param PlayerController 玩家控制
	@param ScreenMoveState 移动的状态
	@param ScreenMoveSpeed 屏幕移动的速度
	@return 返回当前是否移动成功
	*/
	bool MoveDirection(APlayerController* PlayerController, EScreenMoveState ScreenMoveState, const float &ScreenMoveSpeed);
};