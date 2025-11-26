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
	UDataManager();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	TArray<FItemDataStruct> GetItemDataByGroup(EItemGroup InGroupType);
	FItemDataStruct GetItemByDataId(int32 InDataId);

	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UDataAssets> ItemDataAsset;

	TObjectPtr<UDataTable> Table = nullptr;
	TMap<int32, FItemTableData*> ItemMap;
};
