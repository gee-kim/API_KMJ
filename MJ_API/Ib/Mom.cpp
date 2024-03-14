#include "Mom.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>


AMom::AMom()
{
}

AMom::~AMom()
{
}


void AMom::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("$ibm_00.png", 3, 4);

		// 화면에 아트와 캐릭터들 이미지랜더

		Renderer = CreateImageRenderer(PlayRenderOrder::Characters);
		Renderer->SetImage("$ibm_00.png");
		Renderer->AutoImageScale();
		//액터의 위치기준
		//Renderer->SetTransform({ {0,60}, {48, 96} });
		Renderer->CreateAnimation("Idle", "$ibm_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Right", "$ibm_00.png", 7, 7, 0.1f, true);
		Renderer->CreateAnimation("Idle_Left", "$ibm_00.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Idle_Down", "$ibm_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Up", "$ibm_00.png", 10, 10, 0.5f, true);

		Renderer->CreateAnimation("Move_Down", "$ibm_00.png", 0, 2, 0.3f, true);
		Renderer->CreateAnimation("Move_Left", "$ibm_00.png", 3, 5, 0.5f, true);
		Renderer->CreateAnimation("Move_Right", "$ibm_00.png", 6, 8, 0.2f, true);
		Renderer->CreateAnimation("Move_Up", "$ibm_00.png", 9, 11, 0.5f, true);
		Renderer->ChangeAnimation("Idle_Right");

		// 플레이어와 충돌체랜더
		Collision = CreateCollision(CollisionOrder::Characters);
		Collision->SetScale({ 50, 100 });
		Collision->SetColType(ECollisionType::CirCle);

	}

	Script.push_back("재밌게 감상하고 있니 이브?");
	//Script.push_back("'작은따옴표 나오나?'\n 줄바꿈은 되나?\n띄어쓰기는?");
	//Script.push_back("세번째 대사");

	StateChange(EPlayState::Event);

}


void AMom::Tick(float _DeltaTime)
{
	
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


void AMom::StateChange(EPlayState _State)
{
	switch (_State)
	{
	case EPlayState::Idle:
		break;
	case EPlayState::Event:
		break;
	default:
		break;
	}


	State = _State;

}

void AMom::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::Idle:
		Idle(_DeltaTime);
	case EPlayState::Event:
		Event(_DeltaTime);
	default:
		break;
	}


}

void AMom::Event(float _DeltaTime)
{
   	int a = 0;
}

void AMom::Idle(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	if (nullptr == CharFace)
	{
		MsgBoxAssert("IbMom Face가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}


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
			
			// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.
			// 그리고 다른 액터들도 정지되는 상태로 만들어주기.
			Dialogue->SetActive(true);
			Dialogue->CharTextBoxRendererOn();
			Dialogue->SetText(Script[CurTextIndex]);
			CharFace->SetActive(true);
			CharFace->SetMomSmileFace();

		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Script.size())
			{
				CurTextIndex = 0;
				Dialogue->SetActive(false);
				CharFace->SetActive(false);
				Player->StateChange(EPlayState::Idle);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);

		}

	}
	
	int a = 0;
}
