#include "GalleryLevel.h"
#include "Player.h"
#include "BackGroundMap.h"
#include "Dialogue.h"
#include "GalleryButler.h"
#include "Gallery_Window.h"
#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>


UGalleryLevel::UGalleryLevel()
{
}

UGalleryLevel::~UGalleryLevel()
{
}


void UGalleryLevel::BeginPlay()
{
	ULevel::BeginPlay();

	//눈에 보이는 맵이랑, 충돌용 맵 넣어준다.
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("gallery_map.png");
	Map->SetColMapImage("gallery_colmap.png");

	FVector ImageScale = Map->GetImageScale();


	// 플레이어 액터 생성해준다.
	// 액터로케이션 맵띄어서 확인해보고 조정해주기
	APlayer* NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 640, 660 });
	NewPlayer->SetImageScale(ImageScale);

	//갤러리에 있는 콜리젼과 충돌했을 때 뜨는 다이얼로그
	ADialogue* NewDialogue = SpawnActor<ADialogue>();
	NewDialogue->SetActorLocation({ 640, 635 });

	//갤러리맵에 실제로 위치하고 콜리젼을 담당하는 객체들
	{
	AGallery_Window* GalleryWindow = SpawnActor<AGallery_Window>();
	GalleryWindow->SetActorLocation({ 600, 400 });
	GalleryWindow->SetDialogue(NewDialogue);

	AGalleryButler* NewButler = SpawnActor<AGalleryButler>();
	NewButler->SetActorLocation({ 800,400 });
	NewButler->SetDialogue(NewDialogue);



	}


	// 카메라의 위치는 
	// 플레이어의 위치에서 윈도우 크기의 Half만큼 x,y 값으로 이동한 위치
	// 플레이어의 위치
	// 윈도우 크기

	FVector PlayerLocation = NewPlayer->GetTransform().GetPosition();
	UEngineWindow& Window = GEngine->MainWindow;
	FVector ScreenSize = Window.GetWindowScale();
	FVector CameraPos;
	CameraPos.X = PlayerLocation.X - ScreenSize.hX();
	CameraPos.Y = PlayerLocation.Y - ScreenSize.hY();

	SetCameraPos(CameraPos);

}

void UGalleryLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	BGMPlayer = UEngineSound::SoundPlay("La_Follia.ogg");
	BGMPlayer.Loop();

}

void UGalleryLevel::LevelStart(ULevel* _Level)
{
	ULevel::LevelStart(_Level);

	int a = 0;
}

void UGalleryLevel::LevelEnd(ULevel* _Level)
{
	ULevel::LevelEnd(_Level);

	int a = 0;
}