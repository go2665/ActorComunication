// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestBox.generated.h"

UCLASS()
class ACTORCOMMUNICATION_API ATestBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Delegated Event")
	void OnStageClear();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ABoss> Target = nullptr;
};
