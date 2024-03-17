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
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("!$w_02.png", 3, 4);

		// ȭ�鿡 ��Ʈ �̹������� �� �ִϸ��̼� ����
		Renderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		Renderer->SetImage("!$w_02.png");
		Renderer->AutoImageScale();
		Renderer->CreateAnimation("Window_Idle", "!$w_02.png", 0, 0, 0.0f, true);
		Renderer->CreateAnimation("Window_Pass", "!$w_02.png", { 1, 4, 7, 10, 0 }, 0.2f, false);
		Renderer->ChangeAnimation("Window_Idle");


		// �� ���� ��ġ�� �ݸ��� ����
		UCollision* CurCollision = nullptr;

		// â���� ��ġ�ϴ� ���̾�α� �����ϴ� �ݸ���
		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 100, 40 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

		//�� ���� �ִϸ��̼� �ϴ� �ݸ���
		CurCollision = CreateCollision(CollisionOrder::Art);
		CurCollision->SetScale({ 200, 40 });
		CurCollision->SetPosition({ 500, 130 });
		CurCollision->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCollision);

	}

	Script.push_back("�ٱ��� ������ ���......");

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

	// �浹 �� �ִϸ��̼� ����
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
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}


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

