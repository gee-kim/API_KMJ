#include "PonyTail.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

APonyTail::APonyTail()
{
}

APonyTail::~APonyTail()
{
}


void APonyTail::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_00.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Characters);
		CurRenderer->SetImage("$mob_00.png");
		CurRenderer->AutoImageScale();
		//CurRenderer->SetPosition({ 60, 60 });
		//CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Idle", "$mob_00.png", 0, 0, 0.0f, true);
		CurRenderer->ChangeAnimation("Idle");

		// 플레이어와 충돌체랜더
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 50, 50 });
		Collision->SetPosition({ 0,50 });
		Collision->SetColType(ECollisionType::Rect);

	}

	Texts.push_back("이 작품, 내 눈으로 직접 보고 싶었어!");
	Texts.push_back("역시 책에서 보는 거랑은 전혀 다르네......\n\n   분위기가 정말...... 무슨 소리인지......알지!");

}


void APonyTail::Tick(float _DeltaTime)
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
			Dialogue->SetText(Texts[CurTextIndex]);

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Texts.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				Player->StateChange(EPlayState::Idle);
				return;
			}

			Dialogue->SetText(Texts[CurTextIndex]);

		}

	}

}