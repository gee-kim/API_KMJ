#include "PinkWomen.h"
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
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{

			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText("뭔가 빨려들어갈 것 같은 느낌이 들어서 조금은 무서울지도......");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
		}
	}

}