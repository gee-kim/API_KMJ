#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>

#include "SecondGalleryLevel.h"
#include "Player.h"
#include "Dialogue.h"
#include "SecondGalleryArt.h"
#include "FadeIntro.h"
#include "NextThirdLevel.h"



USecondGalleryLevel::USecondGalleryLevel()
{
}

USecondGalleryLevel::~USecondGalleryLevel()
{
}

void USecondGalleryLevel::BeginPlay()
{
	ULevel::BeginPlay();

	BGMPlayer = UEngineSound::SoundPlay("La_Follia.ogg");
	BGMPlayer.Off();
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("second_gallery_map.png");
	Map->SetColMapImage("second_gallery_colmap.png");
	
	FVector MapScale = Map->GetImageScale();


	AFadeIntro* FadeIntro = SpawnActor<AFadeIntro>();
	FadeIntro->SetFadeTime(1.5f);

	ANextThirdLevel* THirdLevel = SpawnActor<ANextThirdLevel>();
	THirdLevel->SetActorLocation({ 645,910 });


	NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 650,850 });
	NewPlayer->SetImageScale(MapScale);
	NewPlayer->SetAnimation("Idle_Up");

	FVector PlayerLocation = NewPlayer->GetActorLocation();
	UEngineWindow& Window = GEngine->MainWindow;
	FVector ScreenSize = Window.GetWindowScale();
	FVector CameraPos;
	CameraPos.X = PlayerLocation.X - ScreenSize.hX();
	CameraPos.Y = PlayerLocation.Y - ScreenSize.hY();

	SetCameraPos(CameraPos);

	ADialogue* NewDialog = SpawnActor<ADialogue>();
	NewDialog->SetActorLocation({ 640, 620 });

	ASecondGalleryArt* MainArt = SpawnActor<ASecondGalleryArt>();
	MainArt->SetActorLocation({ 630,430 });
	MainArt->SetDialogue(NewDialog);

}

void USecondGalleryLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}


void USecondGalleryLevel::LevelStart(ULevel* _Level)
{
	ULevel::LevelStart(_Level);

	int a = 0;
}

void USecondGalleryLevel::LevelEnd(ULevel* _Level)
{
	ULevel::LevelEnd(_Level);

	int a = 0;
}
