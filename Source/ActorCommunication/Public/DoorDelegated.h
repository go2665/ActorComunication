// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "DoorDelegated.generated.h"

/**
 * 
 */
UCLASS()
class ACTORCOMMUNICATION_API ADoorDelegated : public ADoor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Delegated Event")
	void OnStageClear();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ABoss> Target = nullptr;
};
