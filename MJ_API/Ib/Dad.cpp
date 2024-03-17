#include "Dad.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>

ADad::ADad()
{
}

ADad::~ADad()
{
}


void ADad::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$ibf_00.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������

		Renderer = CreateImageRenderer(PlayRenderOrder::Characters_Back);
		Renderer->SetImage("$ibf_00.png");
		Renderer->AutoImageScale();
		//������ ��ġ����
		//Renderer->SetTransform({ {0,60}, {48, 96} });
		Renderer->CreateAnimation("Idle", "$ibf_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Right", "$ibf_00.png", 7, 7, 0.1f, true);
		Renderer->CreateAnimation("Idle_Left", "$ibf_00.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Idle_Down", "$ibf_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Up", "$ibf_00.png", 10, 10, 0.5f, true);

		Renderer->CreateAnimation("Move_Down", "$ibf_00.png", 0, 2, 0.3f, true);
		Renderer->CreateAnimation("Move_Left", "$ibf_00.png", 3, 5, 0.5f, true);
		Renderer->CreateAnimation("Move_Right", "$ibf_00.png", 6, 8, 0.2f, true);
		Renderer->CreateAnimation("Move_Up", "$ibf_00.png", 9, 11, 0.5f, true);
		Renderer->ChangeAnimation("Idle_Right");

		// �÷��̾�� �浹ü����
		Collision = CreateCollision(CollisionOrder::Characters);
		Collision->SetScale({40,40});
		Collision->SetPosition({ 0,-40 });
		Collision->SetColType(ECollisionType::Rect);

	}

	Script.push_back("�ٸ� ����鿡�� ���ذ� �ȵǰ� ������ �����Ϸ� �̺�..?");
	//Script.push_back("'��������ǥ ������?'\n �ٹٲ��� �ǳ�?\n�����?");
	//Script.push_back("����° ���");

	StateChange(EPlayState::Event);

}

void ADad::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}

void ADad::Idle(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	if (nullptr == CharFace)
	{
		MsgBoxAssert("IbDad Face�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
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
			CharFace->SetDadSmileFace();
			Renderer->ChangeAnimation("Idle_Right");

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
				Renderer->ChangeAnimation("Idle_Up");
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);

		}

	}

}


void ADad::StateChange(EPlayState _State)
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

void ADad::StateUpdate(float _DeltaTime)
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

void ADad::Event(float _DeltaTime)
{
	int a = 0;
}
