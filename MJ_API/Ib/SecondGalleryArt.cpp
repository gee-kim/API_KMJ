#include "SecondGalleryArt.h"


ASecondGalleryArt::ASecondGalleryArt()
{
}

ASecondGalleryArt::~ASecondGalleryArt()
{
}

//�׸� �ָ��� �ݸ��� ����
void ASecondGalleryArt::BeginPlay()
{
	AActor::BeginPlay();
	{

		// �÷��̾�� �浹ü����
		Collisions = CreateCollision(CollisionOrder::Art);
		Collisions->SetScale({ 50, 50 });
		//Collisions->SetPosition({ 620,520 });
		Collisions->SetColType(ECollisionType::Rect);

		BlackRenderer = CreateImageRenderer(PlayRenderOrder::Fade);
		BlackRenderer->SetImage("IntroBackGround.png");
		BlackRenderer->AutoImageScale();
		//ImageScale = GEngine->MainWindow.GetWindowScale();
		BlackRenderer->SetPosition({ 50, 100 });
		BlackRenderer->SetAlpha(0.5f);
		BlackRenderer->SetActive(false);


	}

}


void ASecondGalleryArt::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText("'???�� ����'", 20.0f, Color8Bit::Magenta);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
			StateChange(ESecondEventState::StartEvent);
		}
	}

	StateUpdate(_DeltaTime);

}

void ASecondGalleryArt::StateChange(ESecondEventState _State)
{
	switch (_State)
	{
	case ESecondEventState::StartEvent:
		break;
	case ESecondEventState::PlayerControll:
		break;
	default:
		break;
	}

	CurState = _State;
}

void ASecondGalleryArt::StateUpdate(float _Deltatime)
{
	switch (CurState)
	{
	case ESecondEventState::StartEvent:
		StartEvent(_Deltatime);
		break;
	case ESecondEventState::PlayerControll:
		break;
	default:
		break;
	}
}

void ASecondGalleryArt::StartEvent(float _Deltatime)
{
	//���⼭�� �ݸ��� �浹�� �Ͼ ���� ���� ������ �Ǵ� �̺�Ʈ�� �߻�
	//Renderer->SetImage("IntroBackGround.png");
	//Renderer->SetAlpha(0.5f);

	Time += _Deltatime * 3.0f;

	int Count = Time;

	if (Count % 2)
	{
		BlackRenderer->SetActive(true);
	} else
	{
		BlackRenderer->SetActive(false);
	}

	if (6 <= Count)
	{
		StateChange(ESecondEventState::PlayerControll);
	}

}