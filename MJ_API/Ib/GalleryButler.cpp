#include "GalleryButler.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include <EngineCore/EngineResourcesManager.h>

AGalleryButler::AGalleryButler()
{
}

AGalleryButler::~AGalleryButler()
{
}

void AGalleryButler::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_03.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Characters);
		CurRenderer->SetImage("$mob_03.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetPosition({ 60, 60 });
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "$mob_03.png", 0, 2, 1.0f, true);
		CurRenderer->CreateAnimation("Talk", "$mob_03.png", 6, 8, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");

		// 플레이어와 충돌체랜더
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetPosition(GetActorLocation());
		CurCreateCollsions->SetScale({ 50, 100 });
		CurCreateCollsions->SetColType(ECollisionType::CirCle);
		Collisions.push_back(CurCreateCollsions);
			
	}

}

void AGalleryButler::StateChange()
{
	
}

void AGalleryButler::Tick(float _DeltaTime)
{
	//for문 돌면서 다 체크해줘야해
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
			Dialogue->SetText("이곳은 들어오면 안된단다~~");
		}
		else if(true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			//StateChange("Ilde");
			Dialogue->SetActive(false);
		}
	}



}