#include "ArtSign.h"
#include "Player.h"

AArtSign::AArtSign()
{
}

AArtSign::~AArtSign()
{
}

//�׸� �ָ��� �ݸ��� ����
void AArtSign::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �÷��̾�� �浹ü����
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
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
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
			MsgBoxAssert("�÷��̾ �ƴմϴ�.");
		}

		// Űüũ�� ������ �÷��̾�� �������� ���ϴ� ���°� ��.

		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			Player->StateChange(EPlayState::Event);
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("'???�� ����'", 20.0f, Color8Bit::Magenta);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			Player->StateChange(EPlayState::Idle);
		}
	}
}
