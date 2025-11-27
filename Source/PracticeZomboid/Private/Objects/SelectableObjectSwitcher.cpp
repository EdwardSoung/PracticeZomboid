// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/SelectableObjectSwitcher.h"
#include "Engine/StaticMeshActor.h"
#include "Objects/SelectableObject.h"

// Sets default values
ASelectableObjectSwitcher::ASelectableObjectSwitcher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASelectableObjectSwitcher::BeginPlay()
{
	Super::BeginPlay();
	
	Switch();
}

void ASelectableObjectSwitcher::Switch()
{
	if (SwitchActors.IsEmpty())
		return;

	for (auto actor : SwitchActors)
	{
		auto PrevMesh = actor->GetStaticMeshComponent()->GetStaticMesh();
		auto SelectableObject = GetWorld()->SpawnActor<ASelectableObject>(ASelectableObject::StaticClass(), actor->GetTransform());
		SelectableObject->SetAvailableType(AvailableTypes);
		SelectableObject->GenerateItems();

		actor->Destroy();
	}
}
