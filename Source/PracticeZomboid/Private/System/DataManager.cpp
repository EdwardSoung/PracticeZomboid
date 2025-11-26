// Fill out your copyright notice in the Description page of Project Settings.


#include "System/DataManager.h"
#include "System/GameManager.h"

UDataManager::UDataManager()
{
	ItemDataAsset = Cast<UDataAssets>(StaticLoadObject(UDataAssets::StaticClass(), nullptr, TEXT("/Game/Data/ItemAsset")));
}
void UDataManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (auto instance = GetGameInstance())
	{
		if (auto manager = Cast<UGameManager>(instance))
		{
			Table = manager->ItemDataTable;
		}
	}

	if (Table)
	{
		TArray<FItemTableData*> Rows;
		Table->GetAllRows(TEXT("ItemData"), Rows);

		for (FItemTableData* row : Rows)
		{
			ItemMap.Add(row->DataId, row);
		}
	}
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
