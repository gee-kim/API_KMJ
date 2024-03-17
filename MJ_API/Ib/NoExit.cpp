#include "NoExit.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EnginePlatform\EngineInput.h>

ANoExit::ANoExit()
{
}

ANoExit::~ANoExit()
{
}


void ANoExit::BeginPlay()
{
	AActor::BeginPlay();

	{
		// �÷��̾�� �浹ü����
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 20, 120 });
		Collision->SetColType(ECollisionType::Rect);

	}

}


void ANoExit::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}



	if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
	{
		// �浹 �ÿ� �߻��ϴ� �̺�Ʈ
		// �÷��̾�� �浹�� �Ͼ�� Dialogue ���, �÷��̾� ���� ����
		// Ű �Է� �ް� Dialogue ����, �÷��̾� 
		AActor* Owner = Result[0]->GetOwner();

		Player = dynamic_cast<APlayer*>(Owner);

		if (nullptr == Player)
		{
			MsgBoxAssert("�÷��̾ �ƴմϴ�.");
		}

		// �浹�� �Ͼ�� �÷��̾�� �������� ���ϴ� ���°� ��.
		Player->StateChange(EPlayState::Event);

		Dialogue->SetActive(true);
		Dialogue->CharTextBoxRendererOn();
		Dialogue->SetText("..........���� ������ �ʾ�.");

		if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Player->AddActorLocation(FVector::Right * 5.0f);
			BGMSound = UEngineSound::SoundPlay("door_00.ogg");
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);

		}
	}


}