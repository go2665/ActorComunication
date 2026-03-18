// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetInteractor.generated.h"

UCLASS()
class ACTORCOMMUNICATION_API ATargetInteractor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetInteractor();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction Targets")
	TArray<AActor*> InteractionTargets;

	UFUNCTION(BlueprintCallable, Category = "Interaction Targets")
	void TestInteraction();
};
