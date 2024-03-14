#include "Mom.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>


AMom::AMom()
{
}

AMom::~AMom()
{
}


void AMom::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$ibm_00.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������

		Renderer = CreateImageRenderer(PlayRenderOrder::Characters);
		Renderer->SetImage("$ibm_00.png");
		Renderer->AutoImageScale();
		//������ ��ġ����
		//Renderer->SetTransform({ {0,60}, {48, 96} });
		Renderer->CreateAnimation("Idle", "$ibm_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Right", "$ibm_00.png", 7, 7, 0.1f, true);
		Renderer->CreateAnimation("Idle_Left", "$ibm_00.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Idle_Down", "$ibm_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Up", "$ibm_00.png", 10, 10, 0.5f, true);

		Renderer->CreateAnimation("Move_Down", "$ibm_00.png", 0, 2, 0.3f, true);
		Renderer->CreateAnimation("Move_Left", "$ibm_00.png", 3, 5, 0.5f, true);
		Renderer->CreateAnimation("Move_Right", "$ibm_00.png", 6, 8, 0.2f, true);
		Renderer->CreateAnimation("Move_Up", "$ibm_00.png", 9, 11, 0.5f, true);
		Renderer->ChangeAnimation("Idle_Right");

		// �÷��̾�� �浹ü����
		Collision = CreateCollision(CollisionOrder::Characters);
		Collision->SetScale({ 50, 100 });
		Collision->SetColType(ECollisionType::CirCle);

	}

	Script.push_back("��հ� �����ϰ� �ִ� �̺�?");
	//Script.push_back("'��������ǥ ������?'\n �ٹٲ��� �ǳ�?\n�����?");
	//Script.push_back("����° ���");

	StateChange(EPlayState::Event);

}


void AMom::Tick(float _DeltaTime)
{
	
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


void AMom::StateChange(EPlayState _State)
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

void AMom::StateUpdate(float _DeltaTime)
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

void AMom::Event(float _DeltaTime)
{
   	int a = 0;
}

void AMom::Idle(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	if (nullptr == CharFace)
	{
		MsgBoxAssert("IbMom Face�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}


	if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
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
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText(Script[CurTextIndex]);
			CharFace->SetActive(true);
			CharFace->SetMomSmileFace();

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Script.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				CharFace->SetActive(false);
				Player->StateChange(EPlayState::Idle);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);

		}

	}
	
	int a = 0;
}
