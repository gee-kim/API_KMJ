#include "WindowAnimation.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

AWindowAnimation::AWindowAnimation()
{
}

AWindowAnimation::~AWindowAnimation()
{
}

void AWindowAnimation::SetIsPlayedTrue()
{
	IsPlayed = true;
}

void AWindowAnimation::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("!$w_02.png", 3, 4);

		// 화면에 아트 이미지랜더 및 애니메이션 생성
		Renderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		Renderer->SetImage("!$w_02.png");
		Renderer->AutoImageScale();
		Renderer->CreateAnimation("Window_Idle", "!$w_02.png", 0, 0, 0.0f, true);
		Renderer->CreateAnimation("Window_Pass", "!$w_02.png", { 1, 4, 7, 10, 0 }, 0.2f, false);
		Renderer->ChangeAnimation("Window_Idle");


		// 맵 내에 위치할 콜리젼 생성
		UCollision* CurCollision = nullptr;

		// 창문에 위치하는 다이얼로그 생성하는 콜리젼
		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 100, 40 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

		//맵 내에 애니메이션 하는 콜리젼
		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 200, 40 });
		CurCollision->SetPosition({ 500, 130 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

	}

	Script.push_back("바깥은 날씨가 흐려......");

	StateChange(EPlayState::Event);
}


void AWindowAnimation::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


void AWindowAnimation::StateChange(EPlayState _State)
{
	switch (_State)
	{
	case EPlayState::Idle:
		break;
	case EPlayState::Event:
		break;
	default:
		break;
	}


	State = _State;

}

void AWindowAnimation::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::Idle:
		Idle(_DeltaTime);
	case EPlayState::Event:
		Event(_DeltaTime);
	default:
		break;
	}


}

void AWindowAnimation::Event(float _DeltaTime)
{

	// 충돌 후 애니메이션 생성
	if (true == Collisions[1]->CollisionCheck(CollisionOrder::Player, Result))
	{
		if (false == IsPlayed)
		{
			BGMSound = UEngineSound::SoundPlay("flow.ogg");
			Renderer->ChangeAnimation("Window_Pass");
			IsPlayed = true;
			StateChange(EPlayState::Idle);
		}

	}

	int a = 0;
}

void AWindowAnimation::Idle(float _DeltaTime)
{

	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}


	if (true == Collisions[0]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			AActor* Owner = Result[0]->GetOwner();

			Player = dynamic_cast<APlayer*>(Owner);

			if (nullptr == Player)
			{
				MsgBoxAssert("플레이어가 아닙니다.");
			}

			// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.
			Player->StateChange(EPlayState::Event);

			// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.
			// 그리고 다른 액터들도 정지되는 상태로 만들어주기.
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText(Script[0]);

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
			return;
		}


	}

}

