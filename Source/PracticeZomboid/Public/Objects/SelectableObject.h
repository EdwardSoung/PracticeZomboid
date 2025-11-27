// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/Enums.h"
#include "Data/ItemTableData.h"
#include "SelectableObject.generated.h"

UCLASS()
class PRACTICEZOMBOID_API ASelectableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASelectableObject();

	bool CanSelect(AActor* Player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetAvailableItemIds();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TrySelectable(bool bIsSelected, AActor* Player);
	void TrySelect(AActor* Player);

	void SetAvailableType(TArray<EItemGroup> InType)
	{
		AvailableTypes = InType;
	}
	void GenerateItems();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
	TArray<EItemGroup> AvailableTypes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<int32> AvailableItemIds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<FItemTableData> GeneratedItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	float SelectableDistance = 200.0f;
};
