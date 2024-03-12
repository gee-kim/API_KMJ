#include "Dad.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>

ADad::ADad()
{
}

ADad::~ADad()
{
}


void ADad::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("$ibf_00.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더

		Renderer = CreateImageRenderer(PlayRenderOrder::Characters_Back);
		Renderer->SetImage("$ibf_00.png");
		Renderer->AutoImageScale();
		//액터의 위치기준
		//Renderer->SetTransform({ {0,60}, {48, 96} });
		Renderer->CreateAnimation("Idle", "$ibf_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Right", "$ibf_00.png", 7, 7, 0.1f, true);
		Renderer->CreateAnimation("Idle_Left", "$ibf_00.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Idle_Down", "$ibf_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Up", "$ibf_00.png", 10, 10, 0.5f, true);

		Renderer->CreateAnimation("Move_Down", "$ibf_00.png", 0, 2, 0.3f, true);
		Renderer->CreateAnimation("Move_Left", "$ibf_00.png", 3, 5, 0.5f, true);
		Renderer->CreateAnimation("Move_Right", "$ibf_00.png", 6, 8, 0.2f, true);
		Renderer->CreateAnimation("Move_Up", "$ibf_00.png", 9, 11, 0.5f, true);
		Renderer->ChangeAnimation("Idle_Right");

		// 플레이어와 충돌체랜더
		Collision = CreateCollision(CollisionOrder::Characters);
		Collision->SetScale({ 50, 100 });
		Collision->SetColType(ECollisionType::CirCle);

	}

	Script.push_back("다른 사람들에게 방해가 안되게 조용히 감상하렴 이브..?");
	//Script.push_back("'작은따옴표 나오나?'\n 줄바꿈은 되나?\n띄어쓰기는?");
	//Script.push_back("세번째 대사");

}


void ADad::Tick(float _DeltaTime)
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
			// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.
			// 그리고 다른 액터들도 정지되는 상태로 만들어주기.
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
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);

		}

	}

}