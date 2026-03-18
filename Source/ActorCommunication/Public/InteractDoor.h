// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "InteractCPP.h"
#include "InteractDoor.generated.h"

/**
 * 
 */
UCLASS()
class ACTORCOMMUNICATION_API AInteractDoor : public ADoor, public IInteractCPP
{
	GENERATED_BODY()
	
public:
	virtual void InteractCPP_Implementation() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteraction();
};
