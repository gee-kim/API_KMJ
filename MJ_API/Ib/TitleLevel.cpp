#include "TitleLevel.h"
#include "TitleLogo.h"
#include "EngineCore/EngineCore.h"

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	int a = 0;
}

void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	
	ATitleLogo* Logo = SpawnActor<ATitleLogo>();
	

	if (EngineInput::IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("PlayLevel");
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