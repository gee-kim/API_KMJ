#include "GalleryLevel.h"
#include "Player.h"
#include "BackGroundMap.h"
#include "Dialogue.h"
#include "CharFace.h"
#include "GalleryButler.h"
#include "Gallery_Window.h"
#include "Poster.h"
#include "LeftBigArt.h"
#include "RightBigArt.h"
#include "WallArt_Sea.h"
#include "GallerySign.h"
#include "WallArt_Lines.h"
#include "WallArt_Sneeze.h"
#include "Mom.h"
#include "Dad.h"
#include "FadeIntro.h"
#include "NextLevel.h"
#include "PhoneMan.h"
#include "PonyTail.h"
#include "BlueHair.h"
#include "BrownHair.h"
#include "OldLady.h"
#include "PinkWomen.h"
#include "WindowMan.h"
#include "Exit.h"

#include "WallArt_Sleep.h"
#include "WallArt_Dots.h"
#include "BelowSign.h"
#include "WallArt_White.h"
#include "WallArt_Mount.h"
#include "WallArt_Piano.h"


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

	ANextLevel* NextLevel = SpawnActor<ANextLevel>();
	NextLevel->SetActorLocation({ 1100,200 });
	
	//���� ���̴� ���̶�, �浹�� �� �־��ش�.
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("galleryandArts_(1).png");
	Map->SetColMapImage("gallery_colmap.png");

	FVector ImageScale = Map->GetImageScale();

	AFadeIntro* FadeIntro = SpawnActor<AFadeIntro>();
	//FadeIntro->SetActorLocation({})


	// �÷��̾� ���� �������ش�.
	// ���ͷ����̼� �ʶ� Ȯ���غ��� �������ֱ�
	NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 470, 680 });
	NewPlayer->SetImageScale(ImageScale);
	// �÷��̾�� �̺�Ʈ�����϶��� �ƹ��͵� ���Ѵ�.
	NewPlayer->StateChange(EPlayState::Event);

	//�������� �ִ� �ݸ����� �浹���� �� �ߴ� ���̾�α�
	NewDialogue = SpawnActor<ADialogue>();
	NewDialogue->SetActorLocation({ 640, 620 });

	AExit* Exit = SpawnActor<AExit>();
	Exit->SetActorLocation({ 430, 620 });
	Exit->SetDialogue(NewDialogue);

	CharFace = SpawnActor<ACharFace>();
	CharFace->SetActorLocation({ 145, 570 });

	//�������ʿ� ������ ��ġ�ϰ� �ݸ����� ����ϴ� ��ü��
	{
		IbMom = SpawnActor<AMom>();
		IbMom->SetActorLocation({ 470,610 });
		IbMom->SetDialogue(NewDialogue);
		IbMom->SetCharFace(CharFace);
		//IbMom->StateChange(EPlayState::Event);

		IbDad = SpawnActor<ADad>();
		IbDad->SetActorLocation({ 470,570 });
		IbDad->SetDialogue(NewDialogue);
		IbDad->SetCharFace(CharFace);
		//IbDad->StateChange(EPlayState::Event);

		AGallery_Window* GalleryWindow = SpawnActor<AGallery_Window>();
		GalleryWindow->SetActorLocation({ 600, 430 });
		//GalleryWindow->SetDialogue(NewDialogue);

		AGalleryButler* NewButler = SpawnActor<AGalleryButler>();
		NewButler->SetActorLocation({ 840,460 });
		NewButler->SetDialogue(NewDialogue);

		APoster* NewPoster = SpawnActor<APoster>();
		NewPoster->SetActorLocation({ 950, 440 });
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



		AWallArt_Sneeze* Sneeze = SpawnActor<AWallArt_Sneeze>();
		//Sneeze->SetActorLocation({ 660, 660 });
		Sneeze->SetActorLocation({ 1895, 1305 });
		Sneeze->SetDialogue(NewDialogue);
		Sneeze->SetRenderOff();

		APhoneMan* PhoneMan = SpawnActor<APhoneMan>();
		PhoneMan->SetActorLocation({ 1470,620 });
		PhoneMan->SetDialogue(NewDialogue);

		APonyTail* PonyTail = SpawnActor<APonyTail>();
		PonyTail->SetActorLocation({ 1470,650 });
		PonyTail->SetDialogue(NewDialogue);

		ABlueHair* BlueHair = SpawnActor<ABlueHair>();
		BlueHair->SetActorLocation({ 1800,780 });
		BlueHair->SetDialogue(NewDialogue);

		ABrownHair* BrownHair = SpawnActor<ABrownHair>();
		BrownHair->SetActorLocation({ 1680,780 });
		BrownHair->SetDialogue(NewDialogue);

		AOldLady* OldLady = SpawnActor<AOldLady>();
		OldLady->SetActorLocation({ 1890,620 });
		OldLady->SetDialogue(NewDialogue);

		APinkWomen* PinkWomen = SpawnActor<APinkWomen>();
		PinkWomen->SetActorLocation({ 1580,445 });
		PinkWomen->SetDialogue(NewDialogue);

		AWindowMan* WindowMan = SpawnActor<AWindowMan>();
		WindowMan->SetActorLocation({ 600, 400 });
		WindowMan->SetDialogue(NewDialogue);




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

	StateChange(EEventState::PlayerControll);
	NewPlayer->StateChange(EPlayState::Idle);
	IbMom->StateChange(EPlayState::Idle);
	IbDad->StateChange(EPlayState::Idle);

}


void UGalleryLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

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

void UGalleryLevel::StateChange(EEventState _State)
{
	switch (_State)
	{
	case EEventState::StartEvent:
		break;
	case EEventState::PlayerControll:
		break;
	default:
		break;
	}

	CurState = _State;
}

void UGalleryLevel::StateUpdate(float _DeltaTime)
{
	switch (CurState)
	{
	case EEventState::StartEvent:
		StartEvent(_DeltaTime);
		break;
	case EEventState::PlayerControll:
		break;
	default:
		break;
	}
}

void UGalleryLevel::StartEvent(float _DeltaTime)

{
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


	SetCameraPos(CameraPos);


	// �뺻
	// ���� �����ʿ��� �̺��� �ٶ� �� ���
	Script.push_back("��. �����߳�\n......�̺�� �̼��� ó�� �ͺ���?");//���� ��¦ ����ǥ��
	Script.push_back("���� ���� �� ��\n'�Ը��׳�'��� ����� ����ȸ�ε�......");//���� ��¦ ���� ǥ��
	Script.push_back("�׸� ���� �����̶�簡......\n���� ����ִ� ��ǰ���� �ִ� �� �����ϱ�");//���� ��¦ ����ǥ��
	Script.push_back("�и� �̺굵 ��հ� �� �� ���� �ž�");//���� Ȱ¦ ���� ǥ��
	//�ƺ� �ڵ��� ���
	Script.push_back("�����ϰ� �ñ�?");//�ƺ� ��¦ ���� ǥ��
	Script.push_back("�׷�\n�׸��� �������� �޾ư���");//���� ��¦ ����ǥ��

	////���� �ƺ� �ɾ�ͼ� ����Ʈ�� ������ ����.
	////���Ŀ� �̺굵 ���� ������ ���� ������ ����.
	////�̺갡 ������ ���������� ���Ƽ���, ������ �̺긦 ���� �� ��
	Script.push_back("��? ���� ���� �ְڴٰ�?\n����, �̺굵 ��......��¿ �� ����");//���� ��¦ ��Ȳǥ��
	Script.push_back("�̼��� �ȿ����� ������ �ؾ��Ѵ�??\n�˰���?");//���� ��ȣ�� ǥ��
	Script.push_back("......��, �ʶ�� ���� ������");//���� ��¦ ����ǥ��
	Script.push_back("�ٸ� ��������� ���� ��ġ�� �ʵ��� �����Ϸ�");//���� ��¦ ����ǥ��
	//���� ���� ����. �̺� �����ð�

	// ������ ĳ���Ͱ� �����ΰɾ�� �ȴ�.

	if (CurEventState == EStartEventState::Walk)
	{
		IbMom->SetAnimation("Move_Right");
		IbDad->SetAnimation("Move_Right");
		NewPlayer->SetAnimation("Move_Right");

		IbMom->AddActorLocation(FVector::Right * 60.0f * _DeltaTime);
		IbDad->AddActorLocation(FVector::Right * 60.0f * _DeltaTime);
		NewPlayer->AddActorLocation(FVector::Right * 60.0f * _DeltaTime);

		WalkTime -= _DeltaTime;
		if (0.0f >= WalkTime)
		{
			IbMom->SetAnimation("Idle_Right");
			IbDad->SetAnimation("Idle_Right");
			NewPlayer->SetAnimation("Idle_Right");
			CurEventState = EStartEventState::MomTalk;
		}
	}

	if (CurEventState == EStartEventState::MomTalk)
	{
		DelayTime -= _DeltaTime;
		if (0.0 >= DelayTime)
		{
			IbMom->SetAnimation("Idle_Down");

			if (true != MomSoundPlayed)
			{
				BGMSound = UEngineSound::SoundPlay("put_00.ogg");
				BGMSound.SetVolume(0.2f);
				MomSoundPlayed = true;

				NewDialogue->SetActive(true);
				CharFace->SetActive(true);
				NewDialogue->SetText(Script[CurTextIndex]);
				NewDialogue->CharTextBoxRendererOn();
				CharFace->SetMomSmileFace();
			}

		}

		if (true == UEngineInput::IsDown(VK_SPACE) && true == NewDialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex == 2)
			{
				CharFace->SetMomSmileFace();
			}

			if (CurTextIndex == 3)
			{
				CharFace->SetMomBigSmileFace();
			}


			if (CurTextIndex >= 4)
			{
				CurEventState = EStartEventState::DadTalk;
				NewDialogue->SetActive(false);
				CharFace->SetActive(false);

				return;
			}

			NewDialogue->SetText(Script[CurTextIndex]);

		}

	}


	if (CurEventState == EStartEventState::DadTalk)
	{
		DelayTime -= _DeltaTime;
		if (0.0 >= DelayTime)
		{
			IbDad->SetAnimation("Idle_Down");

			if (true != DadSoundPlayed)
			{
				BGMSound = UEngineSound::SoundPlay("put_00.ogg");
				BGMSound.SetVolume(0.2f);
				DadSoundPlayed = true;

				NewDialogue->SetActive(true);
				CharFace->SetActive(true);
				NewDialogue->SetText(Script[CurTextIndex]);
				NewDialogue->CharTextBoxRendererOn();
				CharFace->SetDadSmileFace();
			}
		}


		if (true == UEngineInput::IsDown(VK_SPACE) && true == NewDialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex == 5)
			{
				IbMom->SetAnimation("Idle_Up");
				CharFace->SetMomSmileFace();
			}


			if (CurTextIndex >= 6)
			{
				CurEventState = EStartEventState::WalktoFront;
				NewDialogue->SetActive(false);
				CharFace->SetActive(false);
				return;
			}

			NewDialogue->SetText(Script[CurTextIndex]);

		}
	}

	if (CurEventState == EStartEventState::WalktoFront)
	{
		IbMom->SetAnimation("Move_Right");
		IbDad->SetAnimation("Move_Right");
		NewPlayer->SetAnimation("Move_Right");

		IbMom->AddActorLocation(FVector::Right * 80.0f * _DeltaTime);
		IbDad->AddActorLocation(FVector::Right * 77.0f * _DeltaTime);
		NewPlayer->AddActorLocation(FVector::Right * 50.0f * _DeltaTime);

		FrontWalkTime -= _DeltaTime;
		if (0.0f >= FrontWalkTime)
		{
			IbMom->SetAnimation("Idle_Right");
			IbDad->SetAnimation("Idle_Right");
			NewPlayer->SetAnimation("Idle_Right");
			CurEventState = EStartEventState::WalktoDesk;
		}
	}

	if (CurEventState == EStartEventState::WalktoDesk)
	{
		IbMom->SetAnimation("Move_Up");
		IbDad->SetAnimation("Move_Right");
		NewPlayer->SetAnimation("Move_Up");

		IbMom->AddActorLocation(FVector::Up * 40.0f * _DeltaTime);
		IbDad->AddActorLocation(FVector::Right * 50.0f * _DeltaTime);
		NewPlayer->AddActorLocation(FVector::Up * 68.0f * _DeltaTime);

		UpWalkTime -= _DeltaTime;
		if (0.0f >= UpWalkTime)
		{
			IbMom->SetAnimation("Idle_Up");
			IbDad->SetAnimation("Idle_Up");
			NewPlayer->SetAnimation("Idle_Up");
			CurEventState = EStartEventState::IbTalk;
		}
	}

	if (CurEventState == EStartEventState::IbTalk)
	{
		DelayTime -= _DeltaTime;
		if (0.0 >= DelayTime)
		{
			NewPlayer->SetAnimation("Idle_Right");
			IbMom->SetAnimation("Idle_Left");

			if (true != IbSoundPlayed)
			{
				BGMSound = UEngineSound::SoundPlay("put_00.ogg");
				BGMSound.SetVolume(0.2f);
				IbSoundPlayed = true;

			NewDialogue->SetActive(true);
			CharFace->SetActive(true);
			NewDialogue->SetText(Script[CurTextIndex]);
			NewDialogue->CharTextBoxRendererOn();
			CharFace->SetMomUpsetFace();
			}

		}

		if (true == UEngineInput::IsDown(VK_SPACE) && true == NewDialogue->IsActive())
		{
			++CurTextIndex;


			if (CurTextIndex >= 8)
			{
				CharFace->SetMomSmileFace();
			}


			if (CurTextIndex >= 10)
			{
				IbMom->SetAnimation("Idle_Up");
				CurEventState = EStartEventState::End;
				NewDialogue->SetActive(false);
				CharFace->SetActive(false);

				return;
			}

			NewDialogue->SetText(Script[CurTextIndex]);

		}
	}

	if (CurEventState == EStartEventState::End)
	{
		NewPlayer->StateChange(EPlayState::Idle);
		IbMom->StateChange(EPlayState::Idle);
		IbDad->StateChange(EPlayState::Idle);
		StateChange(EEventState::PlayerControll);
	}

}