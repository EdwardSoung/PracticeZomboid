// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	None,
	Weapon,
	Gun
};

UENUM(BlueprintType)
enum class EItemGroup : uint8
{
	None,
	Weapon,
	Fruit,
	Food,
	Doughnut,
	Meat,
	Bullet,
	Cake,
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	None,
	BaseballBat,
	GolfClub,
	CookingKnife,
	Katana,
	PistolBlack,
	PistolGray,
	AppleGreen,
	AppleRed,
	Pear,
	Strawberry,
	Pumpkin,
	Orange,
	Bullet_Pistol,
	Hamburger,
	Pizza,
	FrenchFried,
	FriedEgg,
	Cake1,
};

UENUM(BlueprintType)
enum class EUIType : uint8
{
	InventoryPopup,
	FieldItemListPopup,
	ExitMenuPopup,
};