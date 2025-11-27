// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopdownPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATopdownPlayer::ATopdownPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	SetRootComponent(CapsuleCollider);*/

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->TargetArmLength = 2000.0f;
	SpringArm->SetRelativeRotation(FQuat(FRotator(-50, 0, 0)));
	TopdownCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Topdown Camera"));
	TopdownCamera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(CapsuleCollider);

	/*Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	Mesh->SetupAttachment(CapsuleCollider);*/
}

// Called when the game starts or when spawned
void ATopdownPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopdownPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATopdownPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

