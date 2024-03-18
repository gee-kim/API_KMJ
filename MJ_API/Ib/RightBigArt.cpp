#include "RightBigArt.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

ARightBigArt::ARightBigArt()
{
}

ARightBigArt::~ARightBigArt()
{
}


void ARightBigArt::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("!$bigart_29.png", 3, 4);
		//576*960 (3*4)

		// 화면에 아트와 캐릭터들 이미지랜더
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Front);
		CurRenderer->SetImage("!$bigart_29.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "!$bigart_29.png", 0, 0, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");


		// 플레이어와 충돌체랜더
		Collisions = CreateCollision(CollisionOrder::Art);
		Collisions->SetScale({ 40, 20 });
		Collisions->SetPosition({ 50,120 });
		Collisions->SetColType(ECollisionType::Rect);

	}

	Script.push_back("[정신의 ? ? ? ]");
	Script.push_back("보기에 아름다운 그 모습은 너무 가까워지면 \n\n   다칠 수 ? ? ? ? 한 육체에서만 피어납니다.");

}


void ARightBigArt::Tick(float _DeltaTime)
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
			Dialogue->SetText(Script[CurTextIndex]);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Script.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				Player->StateChange(EPlayState::Idle);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);
		}
	}

}