

#pragma once

#include "GameFramework/AIController.h"
#include "MinionController.generated.h"

/**
 * 
 */
UCLASS()
class AMinionController : public AAIController
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(transient)
	TSubobjectPtr<class UBlackboardComponent> BlackboardComp;

	UPROPERTY(transient)
	TSubobjectPtr<class UBehaviorTreeComponent> BehaviorComp;

	virtual void Possess(class APawn *InPawn);

	void SetEnemy(class APawn *InPawn);

	UFUNCTION(BlueprintCallable, Category = Behavior)
	void SearchForEnemy();


protected:
	uint8 EnemyKeyID;
	uint8 EnemyLocationID;
};
