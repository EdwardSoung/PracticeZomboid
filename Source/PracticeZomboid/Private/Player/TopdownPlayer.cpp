// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopdownPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
//#include "NiagaraComponent.h"
#include "Player/InventoryComponent.h"

// Sets default values
ATopdownPlayer::ATopdownPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->TargetArmLength = 2000.0f;
	SpringArm->SetRelativeRotation(FQuat(FRotator(-50, 0, 0)));
	TopdownCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Topdown Camera"));
	TopdownCamera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(CapsuleCollider);

	auto CurrentMesh = GetMesh();
	PunchCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Punch"));
	PunchCollider->SetupAttachment(CurrentMesh);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon"));
	WeaponMesh->SetupAttachment(CurrentMesh);
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon"));
	GunMesh->AttachToComponent(CurrentMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Weapon"));

	GunFirePlace = CreateDefaultSubobject<USceneComponent>(TEXT("FirePlace"));	
	GunFirePlace->SetupAttachment(GunMesh);

	//GunMuzzle = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Muzzle Flash"));
	//GunMuzzle->Setup
	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
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

