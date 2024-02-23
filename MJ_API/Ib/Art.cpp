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
		BodyCollision = CreateCollision(CollisionOrder::Art);
		BodyCollision->SetScale({ 100, 100 });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	{
		BodyCollision = CreateCollision(CollisionOrder::Art);
		BodyCollision->SetPosition({ 200, 0 });
		BodyCollision->SetScale({ 100, 100 });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	{
		BodyCollision = CreateCollision(CollisionOrder::Art);
		BodyCollision->SetPosition({ 400,0 });
		BodyCollision->SetScale({ 100, 100 });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	{
		BodyCollision = CreateCollision(CollisionOrder::Art);
		BodyCollision->SetPosition({ 600, 0 });
		BodyCollision->SetScale({ 100, 100 });
		BodyCollision->SetColType(ECollisionType::Rect);
	}


}

void AArt::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;
	if (true == BodyCollision->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			// �ؽ�Ʈ�ڽ� ��� SetDialog()
		}

	}

}