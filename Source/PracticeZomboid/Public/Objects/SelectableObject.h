// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/Enums.h"
#include "Data/ItemDataStruct.h"
#include "SelectableObject.generated.h"

UCLASS()
class PRACTICEZOMBOID_API ASelectableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASelectableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GenerateItems();
	void SetAvailableItemIds();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
	TArray<EItemGroup> AvailableTypes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items");
	TArray<int32> AvailableItemIds;
};
