// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeActor.h"


// Sets default values
ACubeActor::ACubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject  <UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeActor::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateBoxMesh();
}

void ACubeActor::PostLoad()
{
	Super::PostLoad();
	GenerateBoxMesh();
}

void ACubeActor::GenerateBoxMesh()
{
	TArray < FVector > Vertices;
	TArray < FVector > Normals;
	TArray < FProcMeshTangent > Tangents;
	TArray < FVector2D > TextureCoordinates;
	TArray < int32 > Triangles;
	TArray < FColor > Colors;
	CreateBoxMesh(FVector(50, 50, 50), Vertices, Triangles, Normals, TextureCoordinates, Tangents, Colors); // Create the mesh section, specifying collision.  
	mesh->CreateMeshSection(0, Vertices, Triangles, Normals, TextureCoordinates, Colors, Tangents, true);

}

void ACubeActor::CreateBoxMesh(FVector BoxRadius, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents, TArray<FColor>& Colors)
{
	FVector BoxVerts[8];
	BoxVerts[0] = FVector(-BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
	BoxVerts[1] = FVector(BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
	BoxVerts[2] = FVector(BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);
	BoxVerts[3] = FVector(-BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);
	BoxVerts[4] = FVector(-BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[5] = FVector(BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[6] = FVector(BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[7] = FVector(-BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z); // Generate triangles (from quads). 
	Triangles.Reset();
	const int32 NumVerts = 24; // 6 faces x 4 verts per face 
	Colors.Reset();
	Colors.AddUninitialized(NumVerts);
	for (int i = 0; i < NumVerts / 3; i++) {
		Colors[i * 3] = FColor(255, 0, 0);
		Colors[i * 3 + 1] = FColor(0, 255, 0);
		Colors[i * 3 + 2] = FColor(0, 0, 255);
	}
	Vertices.Reset();
	Vertices.AddUninitialized(NumVerts);
	Normals.Reset();
	Normals.AddUninitialized(NumVerts);
	Tangents.Reset();
	Tangents.AddUninitialized(NumVerts);
	Vertices[0] = BoxVerts[0];
	Vertices[1] = BoxVerts[1];
	Vertices[2] = BoxVerts[2];
	Vertices[3] = BoxVerts[3];
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Normals[0] = Normals[1] = Normals[2] = Normals[3] = FVector(0, 0, 1);
	Tangents[0] = Tangents[1] = Tangents[2] = Tangents[3] = FProcMeshTangent(0.f, -1.f, 0.f);
	Vertices[4] = BoxVerts[4];
	Vertices[5] = BoxVerts[0];
	Vertices[6] = BoxVerts[3];
	Vertices[7] = BoxVerts[7];
	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(7);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7); //bottom 
	Normals[4] = Normals[5] = Normals[6] = Normals[7] = FVector(-1, 0, 0);
	Tangents[4] = Tangents[5] = Tangents[6] = Tangents[7] = FProcMeshTangent(0.f, -1.f, 0.f);
	Vertices[8] = BoxVerts[5];
	Vertices[9] = BoxVerts[1];
	Vertices[10] = BoxVerts[0];
	Vertices[11] = BoxVerts[4];
	Triangles.Add(8);
	Triangles.Add(9);
	Triangles.Add(11);

}

