// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEZOMBOID_API UGameManager : public UGameInstance
{
	GENERATED_BODY()

public:
	bool GetIsRestart();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Table")
	TObjectPtr<UDataTable> ItemDataTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flags")
	bool IsRestart = false;
};
