// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "TimerManager.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create root scene component
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	// Create doors
	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftDoor"));
	LeftDoor->SetupAttachment(RootComponent);

	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoor"));
	RightDoor->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	// Store initial positions
	LeftDoorClosedPosition = LeftDoor->GetRelativeLocation();
	RightDoorClosedPosition = RightDoor->GetRelativeLocation();

	// Calculate open positions (sliding doors move along X axis)
	LeftDoorOpenPosition = LeftDoorClosedPosition + FVector(0.0f, OpenDistance, 0.0f);
	RightDoorOpenPosition = RightDoorClosedPosition + FVector(0.0f, -OpenDistance, 0.0f);
}

void ADoor::UpdateDoorAnimation()
{
	if (!bIsAnimating)
	{
		return;
	}

	CurrentAnimationTime += GetWorldTimerManager().GetTimerRate(DoorAnimationTimerHandle);
	float Alpha = FMath::Clamp(CurrentAnimationTime / AnimationDuration, 0.0f, 1.0f);

	// Smooth interpolation using ease in/out
	Alpha = FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2.0f);

	if (bIsOpen)
	{
		// Opening animation
		FVector NewLeftPosition = FMath::Lerp(LeftDoorClosedPosition, LeftDoorOpenPosition, Alpha);
		FVector NewRightPosition = FMath::Lerp(RightDoorClosedPosition, RightDoorOpenPosition, Alpha);

		LeftDoor->SetRelativeLocation(NewLeftPosition);
		RightDoor->SetRelativeLocation(NewRightPosition);
	}
	else
	{
		// Closing animation
		FVector NewLeftPosition = FMath::Lerp(LeftDoorOpenPosition, LeftDoorClosedPosition, Alpha);
		FVector NewRightPosition = FMath::Lerp(RightDoorOpenPosition, RightDoorClosedPosition, Alpha);

		LeftDoor->SetRelativeLocation(NewLeftPosition);
		RightDoor->SetRelativeLocation(NewRightPosition);
	}

	// Stop animating when complete
	if (Alpha >= 1.0f)
	{
		bIsAnimating = false;
		CurrentAnimationTime = 0.0f;
		GetWorldTimerManager().ClearTimer(DoorAnimationTimerHandle);
	}
}

void ADoor::Open()
{
	if (!bIsOpen && !bIsAnimating)
	{
		bIsOpen = true;
		bIsAnimating = true;
		CurrentAnimationTime = 0.0f;

		// Start timer for animation
		GetWorldTimerManager().SetTimer(
			DoorAnimationTimerHandle,
			this,
			&ADoor::UpdateDoorAnimation,
			0.01f,
			true
		);
	}
}

void ADoor::Close()
{
	if (bIsOpen && !bIsAnimating)
	{
		bIsOpen = false;
		bIsAnimating = true;
		CurrentAnimationTime = 0.0f;

		// Start timer for animation
		GetWorldTimerManager().SetTimer(
			DoorAnimationTimerHandle,
			this,
			&ADoor::UpdateDoorAnimation,
			0.01f,
			true
		);
	}
}

void ADoor::Toggle()
{
	if (bIsOpen)
	{
		Close();
	}
	else
	{
		Open();
	}
}

