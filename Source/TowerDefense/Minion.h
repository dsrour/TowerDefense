

#pragma once

#include "GameFramework/Character.h"
#include "MinionController.h"
#include "Minion.generated.h"


/**
 *  Defines the class for a minion NPC.
 */
UCLASS(config=Game)
class AMinion : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Behavior)
	class UBehaviorTree* MinionBehavior;
	
};
