// Fill out your copyright notice in the Description page of Project Settings.


#include "System/DataManager.h"
#include "System/GameManager.h"

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
			ItemMap.Add(row->DataId, *row);
		}
	}
}

TArray<FItemTableData> UDataManager::GetItemDataByGroup(EItemGroup InGroupType)
{

	if (ItemMap.IsEmpty())
		return TArray<FItemTableData>();

	TArray<FItemTableData> OutData;

	for (auto data : ItemMap)
	{
		if (data.Value.ItemGroup == InGroupType)
		{
			OutData.Add(data.Value);
		}
	}

	return OutData;
}

FItemTableData UDataManager::GetItemByDataId(int32 InDataId)
{
	if (ItemMap.IsEmpty())
	{
		return FItemTableData();
	}

	auto findItem = *ItemMap.Find(InDataId);
	return findItem;
}
