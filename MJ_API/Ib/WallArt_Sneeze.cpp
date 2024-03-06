#include "WallArt_Sneeze.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>

AWallArt_Sneeze::AWallArt_Sneeze()
{
}

AWallArt_Sneeze::~AWallArt_Sneeze()
{
}


void AWallArt_Sneeze::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("!$anm_00.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!$anm_00.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetPosition({ 60, 60 });
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "!$anm_00.png", 0, 0, 0.0f, true);
		CurRenderer->CreateAnimation("Sneeze", "!$anm_00.png", {0, 3, 6, 0}, 0.3f, false);
		CurRenderer->ChangeAnimation("Idle");

		// 플레이어와 충돌체랜더
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetScale({ 50, 50 });
		CurCreateCollsions->SetPosition({ 0,30 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

	}

}

void AWallArt_Sneeze::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions[0]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			//StateChange("Talk");
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("어린아이");
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			//StateChange("Ilde");
			Dialogue->SetActive(false);
		}
	}

}

