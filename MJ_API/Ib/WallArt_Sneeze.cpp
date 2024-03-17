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
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("!$anm_00.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		Renderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		Renderer->SetImage("!$anm_00.png");
		Renderer->AutoImageScale();
		Renderer->CreateAnimation("Idle", "!$anm_00.png", 0, 0, 0.0f, true);
		Renderer->CreateAnimation("Sneeze", "!$anm_00.png", {0, 3, 6, 0}, 0.3f, false);
		Renderer->ChangeAnimation("Idle");

		// �÷��̾�� �浹ü����
		UCollision* CurCollision = nullptr;

		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 50, 50 });
		CurCollision->SetPosition({ 0,30 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

		//�� ���� �ִϸ��̼� �ϴ� �ݸ���
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

	// �浹 �� �ִϸ��̼� ����
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
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			AActor* Owner = Result[0]->GetOwner();

			Player = dynamic_cast<APlayer*>(Owner);

			if (nullptr == Player)
			{
				MsgBoxAssert("�÷��̾ �ƴմϴ�.");
			}

			// Űüũ�� ������ �÷��̾�� �������� ���ϴ� ���°� ��.
			Player->StateChange(EPlayState::Event);

			// Űüũ�� ������ �÷��̾�� �������� ���ϴ� ���°� ��.
			// �׸��� �ٸ� ���͵鵵 �����Ǵ� ���·� ������ֱ�.
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("[��ħ�ϴ³���]");

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
			return;
		}


	}

}
