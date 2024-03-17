#include "PinkWomen.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

APinkWomen::APinkWomen()
{
}

APinkWomen::~APinkWomen()
{
}


void APinkWomen::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_00.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		Renderer = CreateImageRenderer(PlayRenderOrder::Characters_Front);
		Renderer->SetImage("$mob_00.png");
		Renderer->AutoImageScale();
		Renderer->CreateAnimation("Idle", "$mob_00.png", 10, 10, 0.0f, true);
		Renderer->ChangeAnimation("Idle");


		// �÷��̾�� �浹ü����
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 50, 50 });
		Collision->SetColType(ECollisionType::Rect);

	}

}


void APinkWomen::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
	{

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

			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText("���� ������ �� ���� ������ �� ������ ����������......");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
		}
	}

}