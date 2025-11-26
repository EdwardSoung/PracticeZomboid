// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Data/Enums.h"
#include "Data/StatStruct.h"
#include "ItemTableData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FItemTableData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int64 UID = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DataId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStatStruct Stat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Desc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Durability = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemGroup ItemGroup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SlotNumber = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMesh> WeaponMesh;
};
