#include <EngineCore\EngineCore.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include "ThirdGalleryLevel.h"
#include "GrayScreen.h"
#include "Player.h"
#include "BackGroundMap.h"
#include "NextFourthGallery.h"
#include "Dialogue.h"
#include "WindowAnimation.h"
#include "Poster.h"
#include "LeftBigArt.h"
#include "RightBigArt.h"
#include "WallArt_Sea.h"
#include "GallerySign.h"
#include "WallArt_Lines.h"
#include "WallArt_Sneeze.h"

#include "WallArt_Sleep.h"
#include "WallArt_Dots.h"
#include "BelowSign.h"
#include "WallArt_White.h"
#include "WallArt_Mount.h"
#include "WallArt_Piano.h"
#include "NoExit.h"
#include "OceanSign.h"

UThirdGalleryLevel::UThirdGalleryLevel()
{
}

UThirdGalleryLevel::~UThirdGalleryLevel()
{
}

void UThirdGalleryLevel::BeginPlay()
{
	ULevel::BeginPlay();

	//BGMPlayer = UEngineSound::SoundPlay("La_Follia.ogg");
	//BGMPlayer.Off();
	//BGMPlayer.Loop();

	//���� ���̴� ���̶�, �浹�� �� �־��ش�.
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("galleryandArts_(1).png");
	Map->SetColMapImage("Third_Gallery_colmap.png");

	ANextFourthGallery* NextGallery = SpawnActor<ANextFourthGallery>();
	NextGallery->SetActorLocation({ 1100,200 });

	FVector ImageScale = Map->GetImageScale();

	AGrayScreen* GrayScreen = SpawnActor<AGrayScreen>();
	GrayScreen->SetActorLocation({ 500,0 });

	// �÷��̾� ���� �������ش�.
	// ���ͷ����̼� �ʶ� Ȯ���غ��� �������ֱ�
	NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 1078,419 });
	NewPlayer->SetImageScale(ImageScale);
	// �÷��̾�� �̺�Ʈ�����϶��� �ƹ��͵� ���Ѵ�.
	

	//�������� �ִ� �ݸ����� �浹���� �� �ߴ� ���̾�α�
	ADialogue* NewDialogue = SpawnActor<ADialogue>();
	NewDialogue->SetActorLocation({ 640, 620 });

	//�������ʿ� ������ ��ġ�ϰ� �ݸ����� ����ϴ� ��ü��
	{

		ANoExit* Exit = SpawnActor<ANoExit>();
		Exit->SetActorLocation({ 430, 620 });
		Exit->SetDialogue(NewDialogue);

		AWindowAnimation* Window = SpawnActor<AWindowAnimation>();
		Window->SetActorLocation({ 600, 430 });
		Window->SetDialogue(NewDialogue);

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
		RightBig->SetActorLocation({ 2675, 1225 });
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
		
		AWallArt_Sleep* Sleep = SpawnActor<AWallArt_Sleep>();
		Sleep->SetActorLocation({ 2760, 520 });
		Sleep->SetDialogue(NewDialogue);

		AWallArt_Dots* Dots = SpawnActor<AWallArt_Dots>();
		Dots->SetActorLocation({ 2570, 520 });
		Dots->SetDialogue(NewDialogue);

		AWallArt_Mount* Mountain = SpawnActor<AWallArt_Mount>();
		Mountain->SetActorLocation({ 2075, 1335 });
		Mountain->SetDialogue(NewDialogue);

		AWallArt_White* White = SpawnActor<AWallArt_White>();
		White->SetActorLocation({ 2275, 1335 });
		White->SetDialogue(NewDialogue);

		ABelowSign* BelowSign = SpawnActor<ABelowSign>();
		BelowSign->SetActorLocation({ 2700, 1075 });
		BelowSign->SetDialogue(NewDialogue);

		AWallArt_Piano* Piano = SpawnActor<AWallArt_Piano>();
		Piano->SetActorLocation({ 1675, 300 });
		Piano->SetDialogue(NewDialogue);

		AOceanSign* OceanSign = SpawnActor<AOceanSign>();
		OceanSign->SetActorLocation({ 1675, 750 });
		OceanSign->SetDialogue(NewDialogue);

	}


	//ī�޶��� ��ġ�� 
	//�÷��̾��� ��ġ���� ������ ũ���� Half��ŭ x,y ������ �̵��� ��ġ
	//�÷��̾��� ��ġ
	//������ ũ��

	FVector PlayerLocation = NewPlayer->GetTransform().GetPosition();
	UEngineWindow& Window = GEngine->MainWindow;
	FVector ScreenSize = Window.GetWindowScale();
	FVector CameraPos;
	CameraPos.X = PlayerLocation.X - ScreenSize.hX();
	CameraPos.Y = PlayerLocation.Y - ScreenSize.hY();


	// ī�޶� ��ġ �ʿ��� ������ �ʰ� �������ֱ�

	if (0.0 >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	if (0.0 >= CameraPos.Y)
	{
		CameraPos.Y = 0.0f;
	}


	// ���̹��� ũ�� ����(RightBottom)���� ���� �� ī�޶��� ��ġ��
	// �̹���ũ�� - ������ ȭ�� ��ŭ�̴�.
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


void UThirdGalleryLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}

void UThirdGalleryLevel::LevelStart(ULevel* _Level)
{
	ULevel::LevelStart(_Level);

	int a = 0;
}

void UThirdGalleryLevel::LevelEnd(ULevel* _Level)
{
	ULevel::LevelEnd(_Level);

	int a = 0;
}
