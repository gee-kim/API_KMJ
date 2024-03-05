#include "LeftBigArt.h"
#include "Helper.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

ALeftBigArt::ALeftBigArt()
{
}

ALeftBigArt::~ALeftBigArt()
{
}



void ALeftBigArt::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("!$bigart_30.png", 3, 4);
		//576*960 (3*4)

		// 화면에 아트와 캐릭터들 이미지랜더
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Front);
		CurRenderer->SetImage("!$bigart_30.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "!$bigart_30.png", 0, 0, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");


		// 플레이어와 충돌체랜더
		Collisions = CreateCollision(CollisionOrder::Art);
		Collisions->SetScale({ 20, 100 });
		Collisions->SetPosition({ 120,0 });
		Collisions->SetColType(ECollisionType::Rect);

	}

}


void ALeftBigArt::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions->CollisionCheck(CollisionOrder::Player, Result))
	{
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText("LeftBigArt 문구 입력필요");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
		}
	}

}