// Fill out your copyright notice in the Description page of Project Settings.

#include "FogActor.h"
#include "Engine.h"


// Sets default values				//initializing texture region for fog actor
AFogActor::AFogActor(): m_wholeTextureRegion(0, 0, 0, 0, m_textureSize, m_textureSize)

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFogActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFogActor::PostInitializeComponents()
{
}

void AFogActor::setSize(float s)
{
}

void AFogActor::revealSmoothCircle(const FVector2D & pos, float radius)
{
}

void AFogActor::UpdateTextureRegions(UTexture2D * Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D * Regions, uint32 SrcPitch, uint32 SrcBpp, uint8 * SrcData, bool bFreeData)
{
}

// Called every frame
void AFogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

