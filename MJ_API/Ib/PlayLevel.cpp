#include "PlayLevel.h"
#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>

UPlayLevel::UPlayLevel()
{
}

UPlayLevel::~UPlayLevel()
{
}


void UPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();
	{
		FVector WindowScale = GEngine->MainWindow.GetWindowScale();

		// 여기서 위치가 안정해졌다고 이녀석위치가 0,0인건 아니죠
		AActor* Back = SpawnActor<AActor>();
		UImageRenderer* Renderer = Back->CreateImageRenderer();
		Renderer->SetOrder(-10);
		// 
		Renderer->SetAlpha(100);
		Renderer->SetImage("all_001.png");
		Renderer->SetPosition(WindowScale.Half2D());
		Renderer->SetScale(WindowScale);
		Renderer->SetImageCuttingTransform({ { 0, 100 }, {100, 100} });
	}
	Player* NewPlayer = SpawnActor<Player>();
	NewPlayer->SetActorLocation({ 200, 200 });

	
}

void UPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}