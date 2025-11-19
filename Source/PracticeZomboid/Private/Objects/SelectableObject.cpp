// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/SelectableObject.h"
#include "System/DataManager.h"
#include "System/ItemManager.h"
#include "Kismet/GameplayStatics.h"
#include "Algo/Find.h"

// Sets default values
ASelectableObject::ASelectableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object Mesh"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void ASelectableObject::BeginPlay()
{
	Super::BeginPlay();
	
	GenerateItems();
}

void ASelectableObject::GenerateItems()
{
	SetAvailableItemIds();

	//있는 아이템이면 개수를 추가해주는 형태로 랜덤 생성 했었는데 음...
	//없으면 생성하고
	//어떻게 생성하는게 나을지..?
	UItemManager* ItemManager = GetGameInstance()->GetSubsystem<UItemManager>();

	int32 genRate = 3000;

	for (int32 itemId : AvailableItemIds)
	{
		int32 rnd = FMath::RandRange(1, 10000);
		if (rnd <= genRate)
		{
			auto GenItem = ItemManager->GenerateItem(itemId);
			FItemDataStruct* Found = Algo::FindByPredicate(GeneratedItems, [itemId](const FItemDataStruct& Elem)
				{
					return Elem.DataId == itemId;
				});
			if (Found)
			{
				Found->Amount += GenItem.Amount;
			}
			else
			{
				GeneratedItems.Add(GenItem);
			}
		}
	}

}
void ASelectableObject::SetAvailableItemIds()
{
	UDataManager* DataManager = GetGameInstance()->GetSubsystem<UDataManager>();

	for (EItemGroup type : AvailableTypes)
	{
		auto Items = DataManager->GetItemDataByGroup(type);
		for (FItemDataStruct item : Items)
		{
			AvailableItemIds.Add(item.DataId);
		}
	}
}

// Called every frame
void ASelectableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASelectableObject::TrySelect(bool bIsSelected, AActor* Player)
{
	float distance = GetDistanceTo(Player);

	bool isRender = bIsSelected && distance < 200;
	StaticMesh->SetRenderCustomDepth(isRender);
}

