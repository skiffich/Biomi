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
    
    if (ImGui::CollapsingHeader("Voice 1"))
    {
        ImGui::SliderFloat("Fundamental_Frequency_V1", &Frequency_V1, 0.0f, 990.0f);
        Metasound->SetFloatParameter(FName("Fundamental_Frequency_V1"), Frequency_V1); // Assuming 'Fundamental_Frequency_V1' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Binaural_Beat_Freq_V1", &BinauralBeatFreq_V1, -40.0f, 40.0f);
        Metasound->SetFloatParameter(FName("Binaural_Beat_Freq_V1"), BinauralBeatFreq_V1); // Assuming 'Binaural_Beat_Freq_V1' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("MIX_L_R_V1", &MIX_L_R_V1, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("MIX_L_R_V1"), MIX_L_R_V1); // Assuming 'MIX_L_R_V1' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Boost_V1", &Boost_V1, 0.0f, 5.0f);
        Metasound->SetFloatParameter(FName("Boost_V1"), Boost_V1); // Assuming 'Boost_V1' is a parameter name you have defined in your Metasound

        if (ImGui::TreeNode("Delay"))
        {
            ImGui::SliderFloat("Attack_Time_V1", &Attack_Time_V1, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Attack_Time_V1"), Attack_Time_V1); // Assuming 'Attack_Time_V1' is a parameter name you have defined in your Metasound

            ImGui::SliderFloat("Decay Time", &Decay_Time_V1, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Decay_Time_V1"), Decay_Time_V1); // Assuming 'Decay_Time_V1' is a parameter name you have defined in your Metasound

            ImGui::SliderFloat("Attack Curve", &Attack_Curve_V1, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Attack_Curve_V1"), Attack_Curve_V1); // Assuming 'Attack_Curve_V1' is a parameter name you have defined in your Metasound

            ImGui::SliderFloat("Decay Curve", &Decay_Curve_V1, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Decay_Curve_V2"), Decay_Curve_V1); // Assuming 'Decay_Curve_V2' is a parameter name you have defined in your Metasound

            ImGui::TreePop(); // End tree node
        }

        ImGui::Separator();
        ImGui::TreePop(); // End tree node
    }

    if (ImGui::CollapsingHeader("Voice 2"))
    {
        ImGui::SliderFloat("Fundamental_Frequency_V2", &Frequency_V2, 0.0f, 990.0f);
        Metasound->SetFloatParameter(FName("Fundamental_Frequency_V2"), Frequency_V2); // Assuming 'Fundamental_Frequency_V2' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Binaural_Beat_Freq_V2", &BinauralBeatFreq_V2, -40.0f, 40.0f);
        Metasound->SetFloatParameter(FName("Binaural_Beat_Freq_V2"), BinauralBeatFreq_V2); // Assuming 'Binaural_Beat_Freq_V2' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("MIX_L_R_V2", &MIX_L_R_V2, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("MIX_L_R_V2"), MIX_L_R_V2); // Assuming 'MIX_L_R_V2' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Boost_V2", &Boost_V2, 0.0f, 5.0f);
        Metasound->SetFloatParameter(FName("Boost_V2"), Boost_V2); // Assuming 'Boost_V2' is a parameter name you have defined in your Metasound

        if (ImGui::TreeNode("Delay"))
        {
            ImGui::SliderFloat("Attack_Time_V2", &Attack_Time_V2, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Attack_Time_V2"), Attack_Time_V2); // Assuming 'Attack_Time_V2' is a parameter name you have defined in your Metasound

            ImGui::SliderFloat("Decay_Time_V2", &Decay_Time_V2, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Decay_Time_V2"), Decay_Time_V2); // Assuming 'Decay_Time_V2' is a parameter name you have defined in your Metasound

            ImGui::SliderFloat("Attack_Curve_V2", &Attack_Curve_V2, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Attack_Curve_V2"), Attack_Curve_V2); // Assuming 'Attack_Curve_V2' is a parameter name you have defined in your Metasound

            ImGui::SliderFloat("Decay_Curve_V2", &Decay_Curve_V2, 0.0f, 1.0f);
            Metasound->SetFloatParameter(FName("Decay_Curve_V2"), Decay_Curve_V2); // Assuming 'Decay_Curve_V2' is a parameter name you have defined in your Metasound

            ImGui::TreePop(); // End tree node
        }

        ImGui::Separator();
        ImGui::TreePop(); // End tree node
    }
    
    if (ImGui::TreeNode("MIX"))
    {
        ImGui::SliderFloat("Voice 1", &Gain_0, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Gain 0"), Gain_0); // Assuming 'AAttack Time' is a parameter name you have defined in your Metasound

        ImGui::SliderFloat("Voice 2", &Gain_1_1, 0.0f, 1.0f);
        Metasound->SetFloatParameter(FName("Gain 1 1"), Gain_1_1); // Assuming 'AAttack Time' is a parameter name you have defined in your Metasound

        ImGui::TreePop(); // End tree node
    }
}


