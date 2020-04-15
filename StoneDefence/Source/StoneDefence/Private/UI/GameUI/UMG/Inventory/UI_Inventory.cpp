// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_Inventory.h"
#include "UI/GameUI/UMG/Inventory/UI_InventorySlot.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"

void UUI_Inventory::NativeConstruct()
{
	Super::NativeConstruct();

	LoyoutInventorySlot(3, 7);
}

void UUI_Inventory::LoyoutInventorySlot(int32 ColumnNumber, int32 RowNumber)
{
	if (InventorySlotClass)
	{
		for (int32 MyRow = 0; MyRow < RowNumber; MyRow++)
		{
			//排序物品栏
			for (int32 MyColume = 0; MyColume < ColumnNumber; MyColume++)
			{
				UUI_InventorySlot* SlotWidget = CreateWidget<UUI_InventorySlot>(GetWorld(), InventorySlotClass);
				if (SlotWidget)
				{
					//将UMG添加进去
					UUniformGridSlot* GridSlot = SlotArrayInventory->AddChildToUniformGrid(SlotWidget);
					if (GridSlot)
					{
						GridSlot->SetColumn(MyColume);
						GridSlot->SetRow(MyRow);
						GridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
						GridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
					}

					InventorySlotArray.Add(SlotWidget);
				}
			}
		}
	}
}
