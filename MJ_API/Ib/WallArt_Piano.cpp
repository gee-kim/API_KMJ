#include "WallArt_Piano.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EnginePlatform\EngineInput.h>

AWallArt_Piano::AWallArt_Piano()
{
}

AWallArt_Piano::~AWallArt_Piano()
{
}


void AWallArt_Piano::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �÷��̾�� �浹ü����
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetScale({ 50, 50 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);
	}

}


void AWallArt_Piano::Tick(float _DeltaTime)
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
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("[���Ǿ��� ? ?]");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Player->StateChange(EPlayState::Idle);
			Dialogue->SetActive(false);
		}
	}

}