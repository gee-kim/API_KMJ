#include "Art.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"

AArt::AArt()
{
}

AArt::~AArt()
{
}

void AArt::BeginPlay()
{
	AActor::BeginPlay();

	{
		BodyCollision0 = CreateCollision(CollisionOrder::Art);
		BodyCollision0->SetScale({ 100, 100 });
		BodyCollision0->SetColType(ECollisionType::Rect);
	}

	{
		BodyCollision1 = CreateCollision(CollisionOrder::Art);
		BodyCollision1->SetPosition({ 200, 0 });
		BodyCollision1->SetScale({ 100, 100 });
		BodyCollision1->SetColType(ECollisionType::Rect);
	}

	{
		BodyCollision2 = CreateCollision(CollisionOrder::Art);
		BodyCollision2->SetPosition({ 400,0 });
		BodyCollision2->SetScale({ 100, 100 });
		BodyCollision2->SetColType(ECollisionType::Rect);
	}

	{
		BodyCollision3 = CreateCollision(CollisionOrder::Art);
		BodyCollision3->SetPosition({ 600, 0 });
		BodyCollision3->SetScale({ 100, 100 });
		BodyCollision3->SetColType(ECollisionType::Rect);
	}


}

void AArt::Tick(float _DeltaTime)
{
	if (nullptr == Dialog)
	{
		MsgBoxAssert("Dialog�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;
	if (true == BodyCollision2->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			Dialog->SetActive(true);
			// �ؽ�Ʈ�ڽ� ��� SetDialog()
			
		}

	}

}