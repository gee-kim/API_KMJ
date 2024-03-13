#include "BlueHair.h"
#include "Helper.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

ABlueHair::ABlueHair()
{
}

ABlueHair::~ABlueHair()
{
}


void ABlueHair::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_02.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Characters);
		CurRenderer->SetImage("$mob_02.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetPosition({ 60, 60 });
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "$mob_00.png", 5, 5, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");

		// �÷��̾�� �浹ü����
		Collision = CreateCollision(CollisionOrder::Characters);
		Collision->SetScale({ 50, 50 });
		Collision->SetColType(ECollisionType::Rect);

	}

	Script.push_back("���� �� �ٴ� �ٷ� �ؿ�\n   ������ ����Ⱑ ���ġ�� �ִ� �� ����......");
	Script.push_back("�̷� �� �����ϸ� ���� �� ������......");

}


void ABlueHair::Tick(float _DeltaTime)
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
			// Űüũ�� ������ �÷��̾�� �������� ���ϴ� ���°� ��.
			// �׸��� �ٸ� ���͵鵵 �����Ǵ� ���·� ������ֱ�.
			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText(Script[CurTextIndex]);

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Script.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);

		}

	}

}