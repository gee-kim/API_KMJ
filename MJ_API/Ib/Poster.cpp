#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include "Helper.h"
#include "Poster.h"

APoster::APoster()
{
}

APoster::~APoster()
{
}


void APoster::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �÷��̾�� �浹ü����
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetPosition(GetActorLocation());
		CurCreateCollsions->SetScale({ 100, 50 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

	}

}


void APoster::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions[0]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			//StateChange("Talk");
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("�Ը��׳����� �����ʹ�.");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			//StateChange("Ilde");
			Dialogue->SetActive(false);
		}
	}

}