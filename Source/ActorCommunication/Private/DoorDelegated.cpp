// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorDelegated.h"
#include "Boss.h"

void ADoorDelegated::BeginPlay()
{
	Super::BeginPlay();

	if (Target != nullptr)
	{
		Target->OnStageClear.AddDynamic(this, &ADoorDelegated::OnStageClear);
	}
}
