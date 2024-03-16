#include "FourthGalleryLevel.h"
#include "Player.h"
#include "Dialogue.h"
#include "FadeIntro.h"
#include "BluePaint.h"
#include "GrayScreen.h"
#include "ArtSign.h"
#include "NextFifrhGallery.h"

#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>

UFourthGalleryLevel::UFourthGalleryLevel()
{
}

UFourthGalleryLevel::~UFourthGalleryLevel()
{
}


void UFourthGalleryLevel::BeginPlay()
{
	ULevel::BeginPlay();

	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("second_gallery_map.png");
	Map->SetColMapImage("second_gallery_colmap.png");

	FVector MapScale = Map->GetImageScale();

	AFadeIntro* FadeIntro = SpawnActor<AFadeIntro>();
	FadeIntro->SetFadeTime(1.0f);

	AGrayScreen* GrayScreen = SpawnActor<AGrayScreen>();
	GrayScreen->SetActorLocation({ 200,0 });

	ANextFifrhGallery* NextFifth = SpawnActor<ANextFifrhGallery>();
	NextFifth->SetActorLocation({ 645,910 });

	NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 650,760 });
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

	AArtSign* MainArt = SpawnActor<AArtSign>();
	MainArt->SetActorLocation({ 630,430 });
	MainArt->SetDialogue(NewDialog);

	ABluePaint* Paint = SpawnActor<ABluePaint>();
	Paint->SetActorLocation({ 540,453 });
	Paint->SetDialogue(NewDialog);

}

void UFourthGalleryLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	
}
