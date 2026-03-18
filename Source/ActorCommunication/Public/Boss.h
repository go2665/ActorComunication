// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boss.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStageClear);

UCLASS()
class ACTORCOMMUNICATION_API ABoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoss();

	UPROPERTY(BlueprintAssignable, Category = "Boss Event")
	FOnStageClear OnStageClear;

protected:
	// Track if hit event already occurred
	bool bIsAlive = true;;

	// Override NotifyHit to receive hit events at actor level
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
