#include "PonyTail.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

APonyTail::APonyTail()
{
}

APonyTail::~APonyTail()
{
}


void APonyTail::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_00.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Characters);
		CurRenderer->SetImage("$mob_00.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetPosition({ 60, 60 });
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "$mob_00.png", 0, 0, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");

		// �÷��̾�� �浹ü����
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 50, 50 });
		Collision->SetPosition({ 0,50 });
		Collision->SetColType(ECollisionType::Rect);

	}

	Texts.push_back("�� ��ǰ, �� ������ ���� ���� �;���!");
	Texts.push_back("���� å���� ���� �Ŷ��� ���� �ٸ���......\n\n   �����Ⱑ ����...... ���� �Ҹ�����......����!");

}


void APonyTail::Tick(float _DeltaTime)
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

			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText(Texts[CurTextIndex]);

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Texts.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				Player->StateChange(EPlayState::Idle);
				return;
			}

			Dialogue->SetText(Texts[CurTextIndex]);

		}

	}

}