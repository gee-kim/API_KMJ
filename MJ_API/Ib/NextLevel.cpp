#include "NextLevel.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "SecondGalleryLevel.h"

ANextLevel::ANextLevel()
{
}

ANextLevel::~ANextLevel()
{
}



void ANextLevel::BeginPlay()
{
	AActor::BeginPlay();

	BodyCollision = CreateCollision(CollisionOrder::Characters);
	BodyCollision->SetPosition({ 0, 0 });
	BodyCollision->SetScale({ 50,100 });
	BodyCollision->SetColType(ECollisionType::Rect);

}

void ANextLevel::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;


	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		GEngine->CreateLevel<USecondGalleryLevel>("Second_Gallery");
		GEngine->ChangeLevel("Second_Gallery");

	}

}
