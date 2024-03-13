// Fill out your copyright notice in the Description page of Project Settings.


#include "BiomiMetasound.h"
#include <imgui.h> // This header is required to make use of Dear ImGui

// Sets default values
ABiomiMetasound::ABiomiMetasound()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Initialize the AudioComponent and make it the root component
    Metasound = CreateDefaultSubobject<UAudioComponent>(TEXT("Metasound"));
    RootComponent = Metasound;
}

// Called when the game starts or when spawned
void ABiomiMetasound::BeginPlay()
{
    Super::BeginPlay();

    EnableInput(GetWorld()->GetFirstPlayerController());

    Metasound->Play();
}

// Called every frame
void ABiomiMetasound::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const FString Label = GetActorLabel();

    ImGui::Begin(TCHAR_TO_ANSI(*Label), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    
    // Assuming 'AdditionalOperands 2' is a parameter name you have defined in your Metasound
    float Frequency = 440.0f;
    ImGui::SliderFloat("Frequency", &Frequency, 0.0f, 990.0f);
    Metasound->SetFloatParameter(FName("AdditionalOperands 2"), Frequency);
}


