#include "ArtSign.h"
#include "Player.h"

AArtSign::AArtSign()
{
}

AArtSign::~AArtSign()
{
}

//그림 팻말에 콜리젼 생성
void AArtSign::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 플레이어와 충돌체랜더
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 50, 50 });
		//Collisions->SetPosition({ 620,520 });
		Collision->SetColType(ECollisionType::Rect);
	}

}

void AArtSign::Tick(float _DeltaTime)
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
		AActor* Owner = Result[0]->GetOwner();

		Player = dynamic_cast<APlayer*>(Owner);

		if (nullptr == Player)
		{
			MsgBoxAssert("플레이어가 아닙니다.");
		}

		// 키체크가 들어오면 플레이어는 움직이지 못하는 상태가 됨.

		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			Player->StateChange(EPlayState::Event);
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("'???의 세계'", 20.0f, Color8Bit::Magenta);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
		}
	}
}
