#include "FifthGalleryLevel.h"

#include "BackGroundMap.h"
#include "Dialogue.h"
#include "GallerySign.h"
#include "GrayScreen.h"
#include "LeftBigArt.h"
#include "Player.h"
#include "Poster.h"
#include "RightBigArt.h"
#include "WallArt_Lines.h"
#include "WallArt_Sea.h"
#include "WallArt_Sneeze.h"
#include "WindowAnimation.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>

UFifthGalleryLevel::UFifthGalleryLevel()
{
}

UFifthGalleryLevel::~UFifthGalleryLevel()
{
}

void UFifthGalleryLevel::BeginPlay()
{
	ULevel::BeginPlay();

	//BGMPlayer = UEngineSound::SoundPlay("La_Follia.ogg");
	//BGMPlayer.Off();
	//BGMPlayer.Loop();

	//눈에 보이는 맵이랑, 충돌용 맵 넣어준다.
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("galleryandArts_(1).png");
	Map->SetColMapImage("gallery_colmap.png");

	FVector ImageScale = Map->GetImageScale();

	AGrayScreen* GrayScreen = SpawnActor<AGrayScreen>();
	GrayScreen->SetActorLocation({ 500,0 });

	// 플레이어 액터 생성해준다.
	// 액터로케이션 맵띄어서 확인해보고 조정해주기
	NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 1078,419 });
	NewPlayer->SetImageScale(ImageScale);
	
	//갤러리에 있는 콜리젼과 충돌했을 때 뜨는 다이얼로그
	ADialogue* NewDialogue = SpawnActor<ADialogue>();
	NewDialogue->SetActorLocation({ 640, 620 });

	//갤러리맵에 실제로 위치하고 콜리젼을 담당하는 객체들
	{

		AWindowAnimation* Window = SpawnActor<AWindowAnimation>();
		Window->SetActorLocation({ 600, 430 });
		Window->SetDialogue(NewDialogue);
		Window->SetIsPlayedTrue();

		APoster* NewPoster = SpawnActor<APoster>();
		NewPoster->SetActorLocation({ 940, 440 });
		NewPoster->SetDialogue(NewDialogue);

		AGallerySign* NewSign = SpawnActor<AGallerySign>();
		NewSign->SetActorLocation({ 1240,540 });
		NewSign->SetDialogue(NewDialogue);

		ALeftBigArt* LeftBig = SpawnActor<ALeftBigArt>();
		LeftBig->SetActorLocation({ 1360, 1400 });
		LeftBig->SetDialogue(NewDialogue);

		ARightBigArt* RightBig = SpawnActor<ARightBigArt>();
		RightBig->SetActorLocation({ 2625, 1225 });
		RightBig->SetDialogue(NewDialogue);

		AWallArt_Sea* SeaArt = SpawnActor<AWallArt_Sea>();
		SeaArt->SetActorLocation({ 2180, 520 });
		SeaArt->SetDialogue(NewDialogue);

		AWallArt_Lines* Lines = SpawnActor<AWallArt_Lines>();
		Lines->SetActorLocation({ 2380, 520 });
		Lines->SetDialogue(NewDialogue);

		AWallArt_Sneeze* Sneeze = SpawnActor<AWallArt_Sneeze>();
		//Sneeze->SetActorLocation({ 660, 660 });
		Sneeze->SetActorLocation({ 1895, 1305 });
		Sneeze->SetDialogue(NewDialogue);
		Sneeze->SetRenderOff();

	}


	//카메라의 위치는 
	//플레이어의 위치에서 윈도우 크기의 Half만큼 x,y 값으로 이동한 위치
	//플레이어의 위치
	//윈도우 크기

	FVector PlayerLocation = NewPlayer->GetTransform().GetPosition();
	UEngineWindow& Window = GEngine->MainWindow;
	FVector ScreenSize = Window.GetWindowScale();
	FVector CameraPos;
	CameraPos.X = PlayerLocation.X - ScreenSize.hX();
	CameraPos.Y = PlayerLocation.Y - ScreenSize.hY();


	// 카메라 위치 맵에서 나가지 않게 지정해주기

	if (0.0 >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	if (0.0 >= CameraPos.Y)
	{
		CameraPos.Y = 0.0f;
	}


	// 맵이미지 크기 끝점(RightBottom)까지 갔을 때 카메라의 위치는
	// 이미지크기 - 윈도우 화면 만큼이다.
	if (CameraPos.X >= ImageScale.X - GEngine->MainWindow.GetWindowScale().X)
	{
		CameraPos.X = ImageScale.X - GEngine->MainWindow.GetWindowScale().X;
	}
	if (CameraPos.Y >= ImageScale.Y - GEngine->MainWindow.GetWindowScale().Y)
	{
		CameraPos.Y = ImageScale.Y - GEngine->MainWindow.GetWindowScale().Y;
	}

	SetCameraPos(CameraPos);

}


void UFifthGalleryLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}

void UFifthGalleryLevel::LevelStart(ULevel* _Level)
{
	ULevel::LevelStart(_Level);

	int a = 0;
}

void UFifthGalleryLevel::LevelEnd(ULevel* _Level)
{
	ULevel::LevelEnd(_Level);

	int a = 0;
}
