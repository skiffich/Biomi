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
    
    if (ImGui::CollapsingHeader("Voice"))
    {
        ImGui::SliderFloat("fundamental frequency", &Frequency, 0.0f, 990.0f);
        Metasound->SetFloatParameter(FName("AdditionalOperands 2"), Frequency); // Assuming 'AdditionalOperands 2' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Binaural Beat Freq", &BinauralBeatFreq, -40.0f, 40.0f);
        Metasound->SetFloatParameter(FName("AdditionalOperands"), BinauralBeatFreq); // Assuming 'AdditionalOperands' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("MIX L R", &MIX_L_R, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Gain 1"), MIX_L_R); // Assuming 'Gain 1' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Boost", &Boost, 0.0f, 5.0f);
        Metasound->SetFloatParameter(FName("AdditionalOperands 3"), Boost); // Assuming 'AdditionalOperands 3' is a parameter name you have defined in your Metasound
        
        ImGui::TreePop(); // End tree node
    }
    if (ImGui::TreeNode("Delay"))
    {
        ImGui::SliderFloat("Attack Time", &Attack_Time, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Attack Time"), Attack_Time); // Assuming 'AAttack Time' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Decay Time", &Decay_Time, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Decay Time"), Decay_Time); // Assuming 'AAttack Time' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Attack Curve", &Attack_Curve, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Attack Curve"), Attack_Curve); // Assuming 'Attack Curve' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Decay Curve", &Decay_Curve, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Decay Curve"), Decay_Curve); // Assuming 'Decay Curve' is a parameter name you have defined in your Metasound

        ImGui::TreePop(); // End tree node
    }
    if (ImGui::TreeNode("MIX"))
    {
        ImGui::SliderFloat("Gain 0", &Gain_0, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Gain 0"), Gain_0); // Assuming 'AAttack Time' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Decay Time", &Gain_1_1, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Gain 1 1"), Gain_1_1); // Assuming 'AAttack Time' is a parameter name you have defined in your Metasound

        ImGui::TreePop(); // End tree node
    }
}


