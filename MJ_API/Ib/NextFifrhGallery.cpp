#include "NextFifrhGallery.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "FifthGalleryLevel.h"


ANextFifrhGallery::ANextFifrhGallery()
{
}

ANextFifrhGallery::~ANextFifrhGallery()
{
}



void ANextFifrhGallery::BeginPlay()
{
	AActor::BeginPlay();

	BodyCollision = CreateCollision(CollisionOrder::Characters);
	BodyCollision->SetScale({ 200,100 });
	BodyCollision->SetColType(ECollisionType::Rect);

}

void ANextFifrhGallery::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;


	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		BGMSound = UEngineSound::SoundPlay("stairs.ogg");
		GEngine->CreateLevel<UFifthGalleryLevel>("Fifth_Gallery");
		GEngine->ChangeLevel("Fifth_Gallery");

	}

}
