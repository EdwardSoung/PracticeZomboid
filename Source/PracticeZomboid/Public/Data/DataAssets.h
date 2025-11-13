// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/ItemDataStruct.h"
#include "DataAssets.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEZOMBOID_API UDataAssets : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemDataStruct> Data;
};
