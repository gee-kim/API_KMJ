#include "LeftBigArt.h"
#include "Helper.h"
#include "Player.h"

#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

ALeftBigArt::ALeftBigArt()
{
}

ALeftBigArt::~ALeftBigArt()
{
}



void ALeftBigArt::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("!$bigart_30.png", 3, 4);
		//576*960 (3*4)

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Front);
		CurRenderer->SetImage("!$bigart_30.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "!$bigart_30.png", 0, 0, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");


		// �÷��̾�� �浹ü����
		Collisions = CreateCollision(CollisionOrder::Art);
		Collisions->SetScale({ 20, 40 });
		Collisions->SetPosition({ 120,0 });
		Collisions->SetColType(ECollisionType::Rect);

	}

}


void ALeftBigArt::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	if (true == Collisions->CollisionCheck(CollisionOrder::Player, Result))
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
			Dialogue->SetText("[? ? ?]");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Player->StateChange(EPlayState::Idle);
			Dialogue->SetActive(false);
		}
	}

}