// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data/DataAssets.h"
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

	TArray<FItemDataStruct> GetItemDataByGroup(EItemGroup InGroupType);

	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UDataAssets> ItemDataAsset;
};
