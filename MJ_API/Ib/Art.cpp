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
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;
	if (true == BodyCollision0->CollisionCheck(CollisionOrder::Player, Result))
	{
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			Dialogue->ArtTextBox();
			Dialogue->CreateText("0번 그림입니다");
			//CreateDialogue("Art", "0번 그림입니다");
			//CreateDialogue("Character", "0번 그림입니다");

			if (true == UEngineInput::IsDown(VK_SPACE))
			{
				Dialogue->SetActive(true);
				Dialogue->SwitchDebug();
			}
			// SetActive 디버그기능처럼 바꿔야 하나?..

		}

	}


	if (true == BodyCollision1->CollisionCheck(CollisionOrder::Player, Result))
	{
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			Dialogue->CharTextBox();
			Dialogue->CreateText("1번 캐릭터입니다");
			//CreateDialogue("Art", "0번 그림입니다");
			//CreateDialogue("Character", "0번 그림입니다");
			Dialogue->SetActive(true);
			// SetActive 디버그기능처럼 바꿔야 하나?..

		}

	}

}