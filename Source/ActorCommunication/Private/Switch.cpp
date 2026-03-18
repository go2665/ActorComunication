// Fill out your copyright notice in the Description page of Project Settings.


#include "Switch.h"
#include "Door.h"

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASwitch::Use(AActor* InTarget)
{	
	if (ADoor* Door = Cast<ADoor>(InTarget))
	{
		Door->Toggle();
	}
}
