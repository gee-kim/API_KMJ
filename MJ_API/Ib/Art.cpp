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
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			// 텍스트박스 출력 SetDialog()
		}

	}

}