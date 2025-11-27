// Fill out your copyright notice in the Description page of Project Settings.


#include "System/GameManager.h"

bool UGameManager::GetIsRestart()
{
	bool curValue = IsRestart;

	IsRestart = true;

	return curValue;
}
