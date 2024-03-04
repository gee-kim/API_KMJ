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

	//�������� �ִ� �ݸ����� �浹���� �� �ߴ� ���̾�α�
	ADialogue* NewDialogue = SpawnActor<ADialogue>();
	NewDialogue->SetActorLocation({ 640, 635 });

	//�������ʿ� ������ ��ġ�ϰ� �ݸ����� ����ϴ� ��ü��
	{
	AGallery_Window* GalleryWindow = SpawnActor<AGallery_Window>();
	GalleryWindow->SetActorLocation({ 600, 400 });
	GalleryWindow->SetDialogue(NewDialogue);

	AGalleryButler* NewButler = SpawnActor<AGalleryButler>();
	NewButler->SetActorLocation({ 800,400 });
	NewButler->SetDialogue(NewDialogue);



	}


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