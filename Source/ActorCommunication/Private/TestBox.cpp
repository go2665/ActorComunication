// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBox.h"
#include "Boss.h"

// Sets default values
ATestBox::ATestBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATestBox::BeginPlay()
{
	Super::BeginPlay();

	if (Target != nullptr)
	{
		Target->OnStageClear.AddDynamic(this, &ATestBox::OnStageClear);
	}
}
