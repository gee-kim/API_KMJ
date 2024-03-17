#include "WallArt_Sneeze.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>



AWallArt_Sneeze::AWallArt_Sneeze()
{
}

AWallArt_Sneeze::~AWallArt_Sneeze()
{
}


void AWallArt_Sneeze::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("!$anm_00.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더
		Renderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		Renderer->SetImage("!$anm_00.png");
		Renderer->AutoImageScale();
		Renderer->CreateAnimation("Idle", "!$anm_00.png", 0, 0, 0.0f, true);
		Renderer->CreateAnimation("Sneeze", "!$anm_00.png", {0, 3, 6, 0}, 0.3f, false);
		Renderer->ChangeAnimation("Idle");

		// 플레이어와 충돌체랜더
		UCollision* CurCollision = nullptr;

		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 50, 50 });
		CurCollision->SetPosition({ 0,30 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

		//맵 내에 애니메이션 하는 콜리젼
		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 200, 40 });
		CurCollision->SetPosition({ -180, -100 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

	}


}

void AWallArt_Sneeze::SetRenderOff()
{
	Collisions[1]->SetActive(false);
}

void AWallArt_Sneeze::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


void AWallArt_Sneeze::StateChange(EPlayState _State)
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

void AWallArt_Sneeze::StateUpdate(float _DeltaTime)
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

void AWallArt_Sneeze::Event(float _DeltaTime)
{

	// 충돌 후 애니메이션 생성
	if (true == Collisions[1]->CollisionCheck(CollisionOrder::Player, Result))
	{
		if (false == IsPlayed)
		{

			BGMSound = UEngineSound::SoundPlay("cough.ogg");
			Renderer->ChangeAnimation("Sneeze");
			IsPlayed = true;
			return;
		}
	}

}

void AWallArt_Sneeze::Idle(float _DeltaTime)
{

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
			Dialogue->SetText("[기침하는남자]");

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
			return;
		}


	}

}
