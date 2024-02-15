#include "TitleLevel.h"
#include "TitleLogo.h"
#include "BackTitle.h"
#include "EngineCore/EngineCore.h"

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	ATitleLogo* Logo = SpawnActor<ATitleLogo>();
	Logo->SetActorLocation({ 0, 0 });

	ABackTitle* Back = SpawnActor<ABackTitle>();
	Back->SetActorLocation({ 0, 0 });

	int a = 0;
}

void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	
	
	if (UEngineInput::IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("Play");
	}

}

void UTitleLevel::LevelStart(ULevel* _Level)
{
	int a = 0;
}
void UTitleLevel::LevelEnd(ULevel* _Level)
{
	int a = 0;
}