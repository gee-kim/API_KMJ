#include "NextFourthGallery.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "FourthGalleryLevel.h"

ANextFourthGallery::ANextFourthGallery()
{

}

ANextFourthGallery::~ANextFourthGallery()
{

}

void ANextFourthGallery::BeginPlay()
{
	AActor::BeginPlay();

	BodyCollision = CreateCollision(CollisionOrder::Characters);
	BodyCollision->SetScale({ 200,100 });
	BodyCollision->SetColType(ECollisionType::Rect);

}

void ANextFourthGallery::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;


	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		BGMSound = UEngineSound::SoundPlay("stairs.ogg");
		GEngine->CreateLevel<UFourthGalleryLevel>("Fourth");
		GEngine->ChangeLevel("Fourth");

	}

}
