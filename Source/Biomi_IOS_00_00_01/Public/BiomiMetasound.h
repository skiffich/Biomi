// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "BiomiMetasound.generated.h"

UCLASS()
class BIOMI_IOS_00_00_01_API ABiomiMetasound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABiomiMetasound();

protected:
	// Audio component for the Metasound
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	UAudioComponent* Metasound;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Function to toggle frequency
	void ToggleFrequency();

	bool bIsHighFrequency = false;
};
