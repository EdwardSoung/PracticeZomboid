// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatStruct.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FStatStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Hp = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Attack = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Hunger = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Stamina = 0;
};