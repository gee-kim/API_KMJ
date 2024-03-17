#include "NextThirdLevel.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "ThirdGalleryLevel.h"


ANextThirdLevel::ANextThirdLevel()
{
}

ANextThirdLevel::~ANextThirdLevel()
{
}



void ANextThirdLevel::BeginPlay()
{
	AActor::BeginPlay();

	BodyCollision = CreateCollision(CollisionOrder::Characters);
	BodyCollision->SetScale({ 200,100 });
	BodyCollision->SetColType(ECollisionType::Rect);

}

void ANextThirdLevel::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;


	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		BGMSound = UEngineSound::SoundPlay("stairs.ogg");
		GEngine->CreateLevel<UThirdGalleryLevel>("Third_Gallery");
		GEngine->ChangeLevel("Third_Gallery");

	}

}
