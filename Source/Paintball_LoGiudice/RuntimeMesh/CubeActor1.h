// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"
#include "CubeActor1.generated.h"

UCLASS()
class PAINTBALL_LOGIUDICE_API ACubeActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeActor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//declare PostActorCreated, PostLoad, GenerateBoxMesh, and CreateBoxMesh functions.
	virtual void PostActorCreated() override;

	virtual void PostLoad() override;

	virtual void GenerateBoxMesh();
	virtual void CreateBoxMesh(FVector BoxRadius, TArray <FVector> & Vertices, TArray <int32> & Triangles, TArray <FVector> & Normals, TArray <FVector2D> & UVs, TArray <FRuntimeMeshTangent> & Tangents, TArray <FColor> & Colors);

//declare RuntimeMeshComonent pointer as mesh for Cube Actor.
private:
	UPROPERTY(VisibleAnywhere)
	URuntimeMeshComponent * mesh;
	
	
};
