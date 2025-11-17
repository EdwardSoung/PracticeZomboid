// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data/ItemDataStruct.h"
#include "ItemManager.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEZOMBOID_API UItemManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	FItemDataStruct GenerateItem(int32 InDataId);

private:
	int64 GetNextUid();

private:
	int64 NextUid = 0;
};
