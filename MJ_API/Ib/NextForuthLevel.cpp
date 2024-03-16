#include "NextFourthLevel.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "ThirdGalleryLevel.h"


ANextFourthLevel::ANextFourthLevel()
{
}

ANextFourthLevel::~ANextFourthLevel()
{
}



void ANextFourthLevel::BeginPlay()
{
	AActor::BeginPlay();

	BodyCollision = CreateCollision(CollisionOrder::Characters);
	BodyCollision->SetScale({ 200,100 });
	BodyCollision->SetColType(ECollisionType::Rect);

}

void ANextFourthLevel::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;


	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		GEngine->CreateLevel<UThirdGalleryLevel>("Third_Gallery");
		GEngine->ChangeLevel("Third_Gallery");

	}

}
