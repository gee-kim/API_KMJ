#include "PinkWomen.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

APinkWomen::APinkWomen()
{
}

APinkWomen::~APinkWomen()
{
}


void APinkWomen::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_00.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더
		Renderer = CreateImageRenderer(PlayRenderOrder::Characters_Front);
		Renderer->SetImage("$mob_00.png");
		Renderer->AutoImageScale();
		Renderer->CreateAnimation("Idle", "$mob_00.png", 10, 10, 0.0f, true);
		Renderer->ChangeAnimation("Idle");


		// 플레이어와 충돌체랜더
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 50, 50 });
		Collision->SetColType(ECollisionType::Rect);

	}

}


void APinkWomen::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
	{

		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
		AActor* Owner = Result[0]->GetOwner();

		Player = dynamic_cast<APlayer*>(Owner);

		if (nullptr == Player)
		{
			MsgBoxAssert("플레이어가 아닙니다.");
		}

		// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.
		Player->StateChange(EPlayState::Event);

			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText("뭔가 빨려들어갈 것 같은 느낌이 들어서 조금은 무서울지도......");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
		}
	}

}