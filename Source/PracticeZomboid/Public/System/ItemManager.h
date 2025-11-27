// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data/ItemTableData.h"
#include "ItemManager.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEZOMBOID_API UItemManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	
	FItemTableData GenerateItem(int32 InDataId);
private:
	int64 GetNextUid();

private:
	int64 NextUid = 0;

public:

	void MoveItemToInventory(FItemTableData InItem);

};
