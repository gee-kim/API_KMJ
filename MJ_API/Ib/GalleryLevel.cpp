#include "GalleryLevel.h"
#include "Player.h"
#include "BackGroundMap.h"
#include "Dialog.h"
#include "Art.h"
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

	//���� ���̴� ���̶�, �浹�� �� �־��ش�.
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("gallery_map.png");
	Map->SetColMapImage("gallery_colmap.png");

	FVector ImageScale = Map->GetImageScale();


	// �÷��̾� ���� �������ش�.
	// ���ͷ����̼� �ʶ� Ȯ���غ��� �������ֱ�
	APlayer* NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 640, 660 });
	NewPlayer->SetImageScale(ImageScale);


	ADialog* NewDialog = SpawnActor<ADialog>();
	NewDialog->SetActorLocation({ 640, 635 });

	AArt* NewArt = SpawnActor<AArt>();
	NewArt->SetActorLocation({ 600,400 });
	NewArt->SetDialog(NewDialog);

	

	// ī�޶��� ��ġ�� 
	// �÷��̾��� ��ġ���� ������ ũ���� Half��ŭ x,y ������ �̵��� ��ġ
	// �÷��̾��� ��ġ
	// ������ ũ��

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