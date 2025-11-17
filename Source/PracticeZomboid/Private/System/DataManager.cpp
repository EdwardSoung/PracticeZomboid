// Fill out your copyright notice in the Description page of Project Settings.


#include "System/DataManager.h"

UDataManager::UDataManager()
{
	ItemDataAsset = Cast<UDataAssets>(StaticLoadObject(UDataAssets::StaticClass(), nullptr, TEXT("/Game/Data/ItemAsset")));
}

TArray<FItemDataStruct> UDataManager::GetItemDataByGroup(EItemGroup InGroupType)
{
	if (!ItemDataAsset)
		return TArray<FItemDataStruct>();

	TArray<FItemDataStruct> OutData;

	for (FItemDataStruct data : ItemDataAsset.Get()->Data)
	{
		if (data.ItemGroup == InGroupType)
		{
			OutData.Add(data);
		}
	}

	return OutData;
}

FItemDataStruct UDataManager::GetItemByDataId(int32 InDataId)
{
	if (!ItemDataAsset)
		return FItemDataStruct();

	FItemDataStruct OutData;

	for (FItemDataStruct data : ItemDataAsset.Get()->Data)
	{
		if (data.DataId == InDataId)
		{
			return OutData;			
		}
	}

	return FItemDataStruct();
}
