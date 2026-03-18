// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractCPP.h"
#include "InteractTarget.generated.h"

UCLASS()
class ACTORCOMMUNICATION_API AInteractTarget : public AActor, public IInteractCPP
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void InteractCPP_Implementation() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteraction();

};
