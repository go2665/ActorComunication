// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Door.generated.h"

UCLASS()
class ACTORCOMMUNICATION_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Door components
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Door Components")
	TObjectPtr<UStaticMeshComponent> LeftDoor = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Door Components")
	TObjectPtr<UStaticMeshComponent> RightDoor = nullptr;
	
	// Door state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	bool bIsOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	float OpenDistance = 180.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	float AnimationDuration = 0.3f;

	FVector LeftDoorClosedPosition;
	FVector LeftDoorOpenPosition;
	FVector RightDoorClosedPosition;
	FVector RightDoorOpenPosition;

	float CurrentAnimationTime = 0.0f;
	bool bIsAnimating = false;

	FTimerHandle DoorAnimationTimerHandle;

	void UpdateDoorAnimation();

public:	
	// Door control functions
	UFUNCTION(BlueprintCallable, Category = "Door")
	void Open();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void Close();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void Toggle();
};
