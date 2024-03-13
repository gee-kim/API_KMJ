#include "GalleryButler.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EnginePlatform\EngineInput.h>

AGalleryButler::AGalleryButler()
{
}

AGalleryButler::~AGalleryButler()
{
}

void AGalleryButler::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_03.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Characters);
		CurRenderer->SetImage("$mob_03.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetPosition({ 60, 60 });
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "$mob_03.png", 0, 2, 1.0f, true);
		CurRenderer->CreateAnimation("Talk", "$mob_03.png", 6, 8, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");

		// �÷��̾�� �浹ü����
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetScale({ 50, 50 });
		CurCreateCollsions->SetColType(ECollisionType::CirCle);
		Collisions.push_back(CurCreateCollsions);

	}

	Texts.push_back("�̰��� ������ �ȵȴܴ�? �Ϳ��� �����ư���.");
	Texts.push_back("'��������ǥ ������?'\n �ٹٲ��� �ǳ�?\n�����?");
	Texts.push_back("����° ���");

}


void AGalleryButler::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

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
				Player->StateChange(EPlayState::Idle);
				Dialogue->SetActive(false);
				return;
			}

			Dialogue->SetText(Texts[CurTextIndex]);

		}

	}

}