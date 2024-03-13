// Fill out your copyright notice in the Description page of Project Settings.


#include "BiomiMetasound.h"

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

    // Ensure this actor can handle input.
    if (!InputComponent)
    {
        InputComponent = NewObject<UInputComponent>(this);
        if (InputComponent)
        {
            InputComponent->RegisterComponent();
            this->AddInstanceComponent(InputComponent);
        }
    }

    // Subscribe to Enter pressed
    if (InputComponent)
    {
        InputComponent->BindKey(EKeys::Enter, IE_Pressed, this, &ABiomiMetasound::ToggleFrequency);
    }

    Metasound->Play();
}

// Called every frame
void ABiomiMetasound::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Assuming 'AdditionalOperands 2' is a parameter name you have defined in your Metasound
    Metasound->SetFloatParameter(FName("AdditionalOperands 2"), bIsHighFrequency ? 440.0f : 100.0f);
}

void ABiomiMetasound::ToggleFrequency()
{
    bIsHighFrequency = !bIsHighFrequency;
    UE_LOG(LogTemp, Display, TEXT("%f"), bIsHighFrequency ? 440.0f : 100.0f);
}


