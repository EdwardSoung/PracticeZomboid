// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data/DataAssets.h"
#include "Data/ItemTableData.h"
#include "Data/Enums.h"
#include "DataManager.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEZOMBOID_API UDataManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	TArray<FItemTableData> GetItemDataByGroup(EItemGroup InGroupType);
	FItemTableData GetItemByDataId(int32 InDataId);

	
protected:

	TObjectPtr<UDataTable> Table = nullptr;
	TMap<int32, FItemTableData> ItemMap;
};
