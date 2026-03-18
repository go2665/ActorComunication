// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractTarget.h"

// Sets default values
AInteractTarget::AInteractTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AInteractTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractTarget::InteractCPP_Implementation()
{
	OnInteraction();
}
