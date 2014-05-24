

#include "TowerDefense.h"
#include "MinionController.h"
#include "Minion.h"
#include "TowerDefenseCharacter.h"

AMinionController::AMinionController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	this->BlackboardComp = PCIP.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));
	this->BehaviorComp = PCIP.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
}

void AMinionController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);
	AMinion* minion = Cast<AMinion>(InPawn);
	if (minion && minion->MinionBehavior)
	{
		BlackboardComp->InitializeBlackboard(minion->MinionBehavior->BlackboardAsset);

		EnemyKeyID = BlackboardComp->GetKeyID("Enemy");
		EnemyLocationID = BlackboardComp->GetKeyID("Destination");

		BehaviorComp->StartTree(minion->MinionBehavior);
	}
}

void AMinionController::SearchForEnemy()
{
	APawn* self = GetPawn();
	if (self == NULL)
	{
		return;
	}

	const FVector myLoc = self->GetActorLocation();
	float bestDistSquare = MAX_FLT;
	ATowerDefenseCharacter* bestPawn = NULL;

	for (FConstPawnIterator it = GetWorld()->GetPawnIterator(); it; ++it)
	{
		ATowerDefenseCharacter *testPawn = Cast<ATowerDefenseCharacter>(*it);
		if (testPawn)
		{
			const float distSq = FVector::Dist(testPawn->GetActorLocation(), myLoc);
			if (distSq < bestDistSquare)
			{
				bestDistSquare = distSq;
				bestPawn = testPawn;
			}
		}
	}

	if (bestPawn)
	{
		SetEnemy(bestPawn);
	}
}

void AMinionController::SetEnemy(class APawn *InPawn)
{
	BlackboardComp->SetValueAsObject(EnemyKeyID, InPawn);
	BlackboardComp->SetValueAsVector(EnemyLocationID, InPawn->GetActorLocation());
}
