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


	BGMPlayer = UEngineSound::SoundPlay("La_Follia.ogg");
	BGMPlayer.Off();
	BGMPlayer.Loop();


	BodyCollision = CreateCollision(CollisionOrder::Characters);
	BodyCollision->SetScale({ 200,100 });
	BodyCollision->SetColType(ECollisionType::Rect);

}

void ANextLevel::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	PlayTime -= _DeltaTime;

	if (PlayTime <= 0)
	{
		BGMPlayer.On();
	}


	std::vector<UCollision*> Result;


	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		BGMSound = UEngineSound::SoundPlay("stairs.ogg");
		BGMPlayer.Off();
		GEngine->CreateLevel<USecondGalleryLevel>("Second_Gallery");
		GEngine->ChangeLevel("Second_Gallery");
	}

}
