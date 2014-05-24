

#include "TowerDefense.h"
#include "Minion.h"
#include "MinionController.h"

AMinion::AMinion(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	AIControllerClass = AMinionController::StaticClass();

	// Set size for collision capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	CharacterMovement->bOrientRotationToMovement = true; // Face in the direction we are moving..
	CharacterMovement->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	CharacterMovement->GravityScale = 2.f;
	CharacterMovement->AirControl = 0.80f;
	CharacterMovement->JumpZVelocity = 1000.f;
	CharacterMovement->GroundFriction = 3.f;
	CharacterMovement->MaxWalkSpeed = 600.f;
	CharacterMovement->MaxFlySpeed = 600.f;

}


