// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HallUI/UMG/UI_MainHall.h"
#include "UI/HallUI/UMG/UI_HallMenuSystem.h"
#include "Kismet/GameplayStatics.h"
#include "UI_SaveAndLoadSystem.h"
#include "UI_GameSettingsSystem.h"
#include "Tutoria/UI_TutoriaSystem.h"
#include "Components/SizeBox.h"
#include "Components/Button.h"

template<class T, class UserObject>
UserObject *CreateAssistWidget(T *ThisClass, UClass *AssistClass, USizeBox *WidgetArray)
{
	UserObject* UserObjectElement = nullptr;
	//���Ŷ������ж�
	if (0)
	{
		//���ŵ���
	}

	if (WidgetArray->GetChildAt(0))
	{
		if (WidgetArray->GetChildAt(0)->IsA(AssistClass))
		{
			//�ر�Border ����
			return UserObjectElement;
		}
		else
		{
			WidgetArray->ClearChildren();
		}
	}

	UserObjectElement = CreateWidget<UserObject>(ThisClass->GetWorld(), AssistClass);

	if (UserObjectElement)
	{
		if (WidgetArray->AddChild(UserObjectElement))
		{
		}
		else
		{
			UserObjectElement->RemoveFromParent();
		}
	}
	return UserObjectElement;
}

void UUI_MainHall::NativeConstruct()
{
	Super::NativeConstruct();

	if (HallMenuSystem)
	{
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::GameStart);
			HallMenuSystem->BindGameStart(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::SecretTerritory);
			HallMenuSystem->BindSecretTerritory(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::History);
			HallMenuSystem->BindHistory(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::GameSettings);
			HallMenuSystem->BindGameSettings(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::TutorialWebsite);
			HallMenuSystem->BindTutorialWebsite(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::Browser);
			HallMenuSystem->BindBrowser(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::SpecialContent);
			HallMenuSystem->BindSpecialContent(Delegate);
		}

		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::QuitGame);
			HallMenuSystem->BindQuit(Delegate);
		}
	}
}

void UUI_MainHall::GameStart()
{
	UGameplayStatics::OpenLevel(GetWorld(), "SelectLevel");
}

void UUI_MainHall::SecretTerritory()
{

}

void UUI_MainHall::History()
{
	CreateAssistWidget<UUI_MainHall, UUI_SaveAndLoadSystem>(this, SaveAndLoadSystemClass, BoxList);
}

void UUI_MainHall::GameSettings()
{
	CreateAssistWidget<UUI_MainHall, UUI_GameSettingsSystem>(this, GameSettingsSystemClass, BoxList);
}

void UUI_MainHall::TutorialWebsite()
{
	CreateAssistWidget<UUI_MainHall, UUI_TutoriaSystem>(this, TutoriaSystemClass, BoxList);
}

void UUI_MainHall::Browser()
{

}

void UUI_MainHall::SpecialContent()
{

}

void UUI_MainHall::QuitGame()
{

}
