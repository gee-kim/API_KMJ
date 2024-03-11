#include "GalleryLevel.h"
#include "Player.h"
#include "BackGroundMap.h"
#include "Dialogue.h"
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

		BGMPlayer = UEngineSound::SoundPlay("La_Follia.ogg");
		BGMPlayer.Off();
		BGMPlayer.Loop();

	//눈에 보이는 맵이랑, 충돌용 맵 넣어준다.
	Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("galleryandArts_(1).png");
	Map->SetColMapImage("gallery_colmap(1).png");

	FVector ImageScale = Map->GetImageScale();

	AFadeIntro* FadeIntro = SpawnActor<AFadeIntro>();
	//FadeIntro->SetActorLocation({})

	// 플레이어 액터 생성해준다.
	// 액터로케이션 맵띄어서 확인해보고 조정해주기
	NewPlayer = SpawnActor<APlayer>();
	NewPlayer->SetActorLocation({ 470, 690 });
	NewPlayer->SetImageScale(ImageScale);
	// 플레이어는 이벤트상태일때는 아무것도 안한다.
	NewPlayer->StateChange(EPlayState::Event);

	//갤러리에 있는 콜리젼과 충돌했을 때 뜨는 다이얼로그
	ADialogue* NewDialogue = SpawnActor<ADialogue>();
	NewDialogue->SetActorLocation({ 640, 620 });

	//갤러리맵에 실제로 위치하고 콜리젼을 담당하는 객체들
	{
		IbMom = SpawnActor<AMom>();
		IbMom->SetActorLocation({ 470,620 });
		IbMom->SetDialogue(NewDialogue);

		IbDad = SpawnActor<ADad>();
		IbDad->SetActorLocation({ 470,590 });
		IbDad->SetDialogue(NewDialogue);

		AGallery_Window* GalleryWindow = SpawnActor<AGallery_Window>();
		GalleryWindow->SetActorLocation({ 600, 400 });
		GalleryWindow->SetDialogue(NewDialogue);

		AGalleryButler* NewButler = SpawnActor<AGalleryButler>();
		NewButler->SetActorLocation({ 860,460 });
		NewButler->SetDialogue(NewDialogue);

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

	//StateChange(EEventState::PlayerControll);
	//NewPlayer->StateChange(EPlayState::Idle);


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
	PlayTime -= _DeltaTime;

	if (PlayTime <= 0)
	{
		BGMPlayer.On();
	}

	// 대본
	// 엄마 오른쪽에서 이브쪽 바라본 후 대사
	Script.push_back("자. 도착했네\n......이브는 미술관 처음 와보지?");//엄마 살짝 웃는표정
	Script.push_back("오늘 보러 온 건\n'게르테나'라는 사람의 전시회인데......");//엄마 입벌린 표정
	Script.push_back("그림 말고도 조각이라든가......\n여러 재미있는 작품들이 있는 것 같으니까");//엄마 살짝 웃는표정
	Script.push_back("분명 이브도 재밌게 볼 수 있을 거야");//엄마 활짝 웃는 표정
	//아빠 뒤돌고 대사
	Script.push_back("접수하고 올까?");//아빠 살짝 웃는 표정
	Script.push_back("그래\n그리고 전단지도 받아가자");//엄마 살짝 웃는표정

	//엄마 아빠 걸어나와서 프론트에 나란히 선다.
	//이후에 이브도 엄마 옆으로 가서 나란히 선다.
	//이브가 오른쪽 엄마쪽으로 돌아서고, 엄마도 이브를 돌아 본 후
	Script.push_back("응? 먼저 보고 있겠다고?\n정말, 이브도 참......어쩔 수 없네");//엄마 살짝 당황표정
	Script.push_back("미술관 안에서는 조용히 해야한다??\n알겠지?");//엄마 단호한 표정
	Script.push_back("......뭐, 너라면 걱정 없지만");//엄마 살짝 웃는표정
	Script.push_back("다른 사람들한테 민폐를 끼치지 않도록 주의하렴");//엄마 살짝 웃는표정
	//엄마 앞을 본다. 이브 자유시간

	// 세명의 캐릭터가 앞으로걸어가면 된다.

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
		IbMom->SetAnimation("Idle_Down");
		//BGMSound = UEngineSound::SoundPlay("put_00.ogg");

		//이브엄마랑 이브 아빠 스페이스키 눌러도 충돌일으키지 않아야 하는 상태로 만들기

		ADialogue* MomDialogue = SpawnActor<ADialogue>();
		IbMom->SetDialogue(MomDialogue);
		MomDialogue->SetActive(true, 1.0f);
		MomDialogue->SetActorLocation({ 640, 620 });
		MomDialogue->CharTextBoxRendererOn();
		MomDialogue->SetText(Script[CurTextIndex]);

		if (true == UEngineInput::IsDown(VK_SPACE)/* && true == MomDialogue->IsActive()*/)
		{
			++CurTextIndex;
			if (CurTextIndex >= 4)
			{
				MomDialogue->SetActive(false);
				CurEventState = EStartEventState::End;
				return;
			}
			MomDialogue->SetText(Script[CurTextIndex]);

		}


	}

	if (CurEventState == EStartEventState::End)
	{
		NewPlayer->StateChange(EPlayState::Idle);
		StateChange(EEventState::PlayerControll);
	}

}