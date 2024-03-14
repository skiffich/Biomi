// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"
#include <imgui.h> // This header is required to make use of Dear ImGui.

// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// WARNING: Actor's only have labels in Development builds.
	// If needed in a production build, each ImgGuiActor will need
	// a different unique identifier for their ImgGui windows.
	const FString Label = GetActorLabel();

	ImGui::Begin(TCHAR_TO_ANSI(*Label), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::SliderFloat("Scale", &Scale, 0.1f, 5.0f);
	ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
	ImGui::End();

	// Update this actor's scale if the Scale variable has changed
	// by way of the ImGui slider.
	if (Scale != ScaleOld) {
		ScaleOld = Scale;
		SetActorScale3D(FVector3d{ Scale });
	}
}

