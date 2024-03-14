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
	// Voice 1
	float Frequency_V1 = 440.0f;
	float BinauralBeatFreq_V1 = 40.0f;
	float MIX_L_R_V1 = 0.548f;
	float Boost_V1 = 0.0f;
	// Delay
	float Attack_Time_V1 = 1.0f;
	float Decay_Time_V1 = 1.0f;
	float Attack_Curve_V1 = 1.0f;
	float Decay_Curve_V1 = 1.0f;

	// Voice 2
	float Frequency_V2 = 440.0f;
	float BinauralBeatFreq_V2 = 40.0f;
	float MIX_L_R_V2 = 0.548f;
	float Boost_V2 = 0.0f;
	// Delay
	float Attack_Time_V2 = 1.0f;
	float Decay_Time_V2 = 1.0f;
	float Attack_Curve_V2 = 1.0f;
	float Decay_Curve_V2 = 1.0f;

	// MIX
	float Gain_0 = 1.0f;
	float Gain_1_1 = 0.0f;
};
