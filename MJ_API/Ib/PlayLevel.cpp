#include "PlayLevel.h"
#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include "BackGroundMap.h"

UPlayLevel::UPlayLevel()
{
}

UPlayLevel::~UPlayLevel()
{
}


void UPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();
	
	ABackGroundMap* Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("all_001.png");
	//Map->SetColMapImage("all_001_Col.png");
	Map->SwitchDebug();

	APlayer* NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 200, 200 });

	
}

void UPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UPlayLevel::LevelStart(ULevel* _Level)
{
	ULevel::LevelStart(_Level);

	int a = 0;
}

void UPlayLevel::LevelEnd(ULevel* _Level)
{
	ULevel::LevelEnd(_Level);

	int a = 0;
}