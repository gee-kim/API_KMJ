#include "RightBigArt.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

ARightBigArt::ARightBigArt()
{
}

ARightBigArt::~ARightBigArt()
{
}


void ARightBigArt::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("!$bigart_29.png", 3, 4);
		//576*960 (3*4)

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Front);
		CurRenderer->SetImage("!$bigart_29.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "!$bigart_29.png", 0, 0, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");


		// �÷��̾�� �浹ü����
		Collisions = CreateCollision(CollisionOrder::Art);
		Collisions->SetScale({ 40, 20 });
		Collisions->SetPosition({ 50,120 });
		Collisions->SetColType(ECollisionType::Rect);

	}

	Script.push_back("[������ ? ? ? ]");
	Script.push_back("���⿡ �Ƹ��ٿ� �� ����� �ʹ� ��������� \n\n   ��ĥ �� ? ? ? ? �� ��ü������ �Ǿ�ϴ�.");

}


void ARightBigArt::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

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
			Dialogue->SetText(Script[CurTextIndex]);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Script.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				Player->StateChange(EPlayState::Idle);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);
		}
	}

}