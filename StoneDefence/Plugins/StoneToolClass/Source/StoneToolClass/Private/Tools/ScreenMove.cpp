#include "Tools/ScreenMove.h"
#include "GameFramework/PlayerController.h"
#include "Math/UnrealMathUtility.h"

bool FScreenMoveUnit::ListenScreenMove(APlayerController* PlayerController, const float &ScreenMoveSpeed)
{
	return MoveDirection(PlayerController, CursorMove(PlayerController), ScreenMoveSpeed);
}

EScreenMoveState FScreenMoveUnit::CursorMove(const APlayerController* PlayerController)
{
	if (PlayerController)
	{
		//屏幕尺寸
		int32 SizeX = INDEX_NONE;
		int32 SizeY = INDEX_NONE;

		//鼠标的位置
		float MousePositionX = INDEX_NONE;
		float MousePositionY = INDEX_NONE;

		//获取屏幕尺寸
		PlayerController->GetViewportSize(SizeX, SizeY);

		//获取鼠标的位置
		PlayerController->GetMousePosition(MousePositionX, MousePositionY);

		if (MousePositionX >= 0 && MousePositionX <= SizeX && MousePositionY >= 0 && MousePositionY <= SizeY)
		{
			if (FMath::IsNearlyEqual(MousePositionX, 0.0f, 5.0f) && FMath::IsNearlyEqual(MousePositionY, 0.0f, 5.0f))
			{
				return EScreenMoveState::Screen_LeftAndUp; //左上
			}
			else if (FMath::IsNearlyEqual(MousePositionX, 0.0f, 5.0f) && FMath::IsNearlyEqual(MousePositionY, SizeY, 5.0f))
			{
				return EScreenMoveState::Screen_LeftAndDown; //左下
			}
			else if (FMath::IsNearlyEqual(MousePositionX, SizeX, 5.0f) && FMath::IsNearlyEqual(MousePositionY, 0.0f, 5.0f))
			{
				return EScreenMoveState::Screen_RightAndUp; //右上
			}
			else if (FMath::IsNearlyEqual(MousePositionX, SizeX, 5.0f) && FMath::IsNearlyEqual(MousePositionY, SizeY, 5.0f))
			{
				return EScreenMoveState::Screen_RightAndDown; //右下
			}
			else if (FMath::IsNearlyEqual(MousePositionX, 0.0f, 5.0f))
			{
				return EScreenMoveState::Screen_Left; //左
			}
			else if (FMath::IsNearlyEqual(MousePositionX, SizeX, 5.0f))
			{
				return EScreenMoveState::Screen_Right; //右
			}
			else if (FMath::IsNearlyEqual(MousePositionY, 0.0f, 5.0f))
			{
				return EScreenMoveState::Screen_Up; //上
			}
			else if (FMath::IsNearlyEqual(MousePositionY, SizeY, 5.0f))
			{
				return EScreenMoveState::Screen_Down; //下
			}
		}
	}
	
	return EScreenMoveState::Screen_None;
}

bool FScreenMoveUnit::MoveDirection(APlayerController* PlayerController, EScreenMoveState ScreenMoveState, const float &ScreenMoveSpeed)
{
	FVector OffsetVector = FVector::ZeroVector;

	if (PlayerController && PlayerController->GetPawn())
	{
		switch (ScreenMoveState)
		{
		case Screen_Up:
			OffsetVector = FVector(-ScreenMoveSpeed, 0.0f, 0.0f);
			break;
		case Screen_Down:
			OffsetVector = FVector(ScreenMoveSpeed, 0.0f, 0.0f);
			break;
		case Screen_Right:
			OffsetVector = FVector(0.0f, -ScreenMoveSpeed, 0.0f);
			break;
		case Screen_Left:
			OffsetVector = FVector(0.0f, ScreenMoveSpeed, 0.0f);
			break;
		case Screen_RightAndUp:
			OffsetVector = FVector(-ScreenMoveSpeed, -ScreenMoveSpeed, 0.0f);
			break;
		case Screen_RightAndDown:
			OffsetVector = FVector(ScreenMoveSpeed, -ScreenMoveSpeed, 0.0f);
			break;
		case Screen_LeftAndUp:
			OffsetVector = FVector(-ScreenMoveSpeed, ScreenMoveSpeed, 0.0f);
			break;
		case Screen_LeftAndDown:
			OffsetVector = FVector(ScreenMoveSpeed, ScreenMoveSpeed, 0.0f);
			break;
		}

		PlayerController->GetPawn()->AddActorWorldOffset(OffsetVector);
	}

	return OffsetVector != FVector::ZeroVector;
}

