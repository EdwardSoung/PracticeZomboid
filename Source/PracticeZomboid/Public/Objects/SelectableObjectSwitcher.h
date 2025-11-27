// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/Enums.h"
#include "SelectableObjectSwitcher.generated.h"

UCLASS()
class PRACTICEZOMBOID_API ASelectableObjectSwitcher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASelectableObjectSwitcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Switch();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Type")
	TArray<EItemGroup> AvailableTypes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Original")
	TArray<AStaticMeshActor*> SwitchActors;	
};
