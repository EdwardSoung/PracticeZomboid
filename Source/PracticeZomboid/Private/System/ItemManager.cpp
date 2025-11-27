// Fill out your copyright notice in the Description page of Project Settings.


#include "System/ItemManager.h"
#include "System/GameManager.h"
#include "System/DataManager.h"
#include "Kismet/GameplayStatics.h"



//원본 카피 아이템 생성
FItemTableData UItemManager::GenerateItem(int32 InDataId)
{
	auto ItemData = GetGameInstance()->GetSubsystem<UDataManager>()->GetItemByDataId(InDataId);
		
	ItemData.UID = GetNextUid();

	return ItemData;
}

int64 UItemManager::GetNextUid()
{
	int64 TargetUid = NextUid;

	NextUid++;

	return TargetUid;
}

void UItemManager::MoveItemToInventory(FItemTableData InItem)
{
	ACharacter* character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

}
