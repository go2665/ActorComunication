// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetInteractor.h"
#include "InteractCPP.h"

// Sets default values
ATargetInteractor::ATargetInteractor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATargetInteractor::TestInteraction()
{
	for (AActor* Target : InteractionTargets)
	{		
		if (Target && Target->Implements<UInteractCPP>())	// Target이 InteractCPP 인터페이스를 구현했는지 확인
		{
			IInteractCPP::Execute_InteractCPP(Target);		// 블루프린트로 구현된 InteractCPP까지 실행 가능
		}
	}
}

