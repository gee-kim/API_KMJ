#include "WallArt_Sea.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include "Helper.h"
#include "Player.h"

AWallArt_Sea::AWallArt_Sea()
{
}

AWallArt_Sea::~AWallArt_Sea()
{
}

void AWallArt_Sea::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �÷��̾�� �浹ü����

		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetPosition(GetActorLocation());
		Collision->SetScale({ 50, 30 });
		Collision->SetColType(ECollisionType::Rect);

	}

}


void AWallArt_Sea::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

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
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("[������ ? ?]");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Player->StateChange(EPlayState::Idle);
			Dialogue->SetActive(false);
		}
	}

}