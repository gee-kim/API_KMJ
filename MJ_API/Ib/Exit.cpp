#include "Exit.h"
#include "Helper.h"
#include "Player.h"
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EnginePlatform\EngineInput.h>

AExit::AExit()
{
}

AExit::~AExit()
{
}


void AExit::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 플레이어와 충돌체랜더
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 20, 120 });
		Collision->SetColType(ECollisionType::Rect);

	}

}


void AExit::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}


	if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
	{
		// 충돌 시에 발생하는 이벤트
		// 플레이어와 충돌이 일어나면 Dialogue 출력, 플레이어 상태 멈춤
		// 키 입력 받고 Dialogue 해제, 플레이어 
		AActor* Owner = Result[0]->GetOwner();

		Player = dynamic_cast<APlayer*>(Owner);

		if (nullptr == Player)
		{
			MsgBoxAssert("플레이어가 아닙니다.");
		}

		// 충돌이 일어나면 플레이어는 움직이지 못하는 상태가 됨.
		Player->StateChange(EPlayState::Event);

		Dialogue->SetActive(true);
		Dialogue->CharTextBoxRendererOn();
		Dialogue->SetText("혼자서 나가면 안돼");

		if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->AddActorLocation(FVector::Right * 5.0f);
			Player->StateChange(EPlayState::Idle);

		}
	}


}