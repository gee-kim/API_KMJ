#include "SecondGalleryArt.h"
#include "Player.h"
//#include <EnginePlatform/EngineSound.h>

ASecondGalleryArt::ASecondGalleryArt()
{
}

ASecondGalleryArt::~ASecondGalleryArt()
{
}

//그림 팻말에 콜리젼 생성
void ASecondGalleryArt::BeginPlay()
{
	AActor::BeginPlay();
	{

		// 플레이어와 충돌체랜더
		Collisions = CreateCollision(CollisionOrder::Art);
		Collisions->SetScale({ 50, 50 });
		//Collisions->SetPosition({ 620,520 });
		Collisions->SetColType(ECollisionType::Rect);

		BlackRenderer = CreateImageRenderer(PlayRenderOrder::Fade);
		BlackRenderer->SetImage("IntroBackGround.png");
		BlackRenderer->AutoImageScale();
		//ImageScale = GEngine->MainWindow.GetWindowScale();
		BlackRenderer->SetPosition({ 60, 150 });
		BlackRenderer->SetAlpha(0.5f);
		BlackRenderer->SetActive(false);

	}

}


void ASecondGalleryArt::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions->CollisionCheck(CollisionOrder::Player, Result))
	{
		AActor* Owner = Result[0]->GetOwner();

		Player = dynamic_cast<APlayer*>(Owner);

		if (nullptr == Player)
		{
			MsgBoxAssert("플레이어가 아닙니다.");
		}

		// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.

		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
		Player->StateChange(EPlayState::Event);
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("'???의 세계'", 20.0f, Color8Bit::Magenta);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			StateChange(ESecondEventState::StartEvent);
			Player->StateChange(EPlayState::Idle);
		}
	}

	StateUpdate(_DeltaTime);

}

void ASecondGalleryArt::StateChange(ESecondEventState _State)
{
	switch (_State)
	{
	case ESecondEventState::StartEvent:
		break;
	case ESecondEventState::PlayerControll:
			break;
	default:
		break;
	}

	CurState = _State;
}

void ASecondGalleryArt::StateUpdate(float _Deltatime)
{
	switch (CurState)
	{
	case ESecondEventState::StartEvent:
		StartEvent(_Deltatime);
		break;
	case ESecondEventState::PlayerControll:
		break;
	default:
		break;
	}
}

void ASecondGalleryArt::StartEvent(float _Deltatime)
{
	//여기서는 콜리젼 충돌이 일어난 이후 맵이 암전이 되는 이벤트가 발생
	//Renderer->SetImage("IntroBackGround.png");
	//Renderer->SetAlpha(0.5f);
	if (false == IsPlayed)
	{
		BGMPlayer.Off();
		BGMSound = UEngineSound::SoundPlay("light_01.ogg");
	}

	IsPlayed = true;

	Time += _Deltatime * 3.0f;

	int Count = Time;

	if (Count % 2)
	{
		BlackRenderer->SetActive(true);
	} else
	{
		BlackRenderer->SetActive(false);
	}

	if (6 <= Count)
	{
		StateChange(ESecondEventState::PlayerControll);
	}

}