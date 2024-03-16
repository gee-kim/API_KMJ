#include "BluePaint.h"
#include "Player.h"
#include "ThirdGalleryLevel.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

ABluePaint::ABluePaint()
{
}

ABluePaint::~ABluePaint()
{
}



void ABluePaint::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("!letters.png", 12, 8);
		UEngineResourcesManager::GetInst().CuttingImage("FootPrint.png", 7, 2);

		UImageRenderer* CurRenderer = nullptr;

		// ȭ�鿡 ��Ʈ �̹������� �� �ִϸ��̼� ����
		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("BluePaint.png");
		CurRenderer->AutoImageScale();
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("FirstLetter", "!letters.png", 9, 9, 0.3f, true);
		CurRenderer->ChangeAnimation("FirstLetter");
		CurRenderer->SetPosition({ -200, 150 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("SecondLetter", "!letters.png", 10, 10, 0.3f, true);
		CurRenderer->ChangeAnimation("SecondLetter");
		CurRenderer->SetPosition({ -110, 200 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("ThirdLetter", "!letters.png", 11, 11, 0.3f, true);
		CurRenderer->ChangeAnimation("ThirdLetter");
		CurRenderer->SetPosition({ 20, 100 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("FourthLetter", "!letters.png", 21, 21, 0.3f, true);
		CurRenderer->ChangeAnimation("FourthLetter");
		CurRenderer->SetPosition({ 170, 150 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("FifthLetter", "!letters.png", 9, 9, 0.3f, true);
		CurRenderer->ChangeAnimation("FifthLetter");
		CurRenderer->SetPosition({ 260, 100 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("SixthLetter", "!letters.png", 22, 22, 0.3f, true);
		CurRenderer->ChangeAnimation("SixthLetter");
		CurRenderer->SetPosition({ 370, 180 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("BlueLetter.png");
		CurRenderer->AutoImageScale();
		Renderers.push_back(CurRenderer);
		// ���ڴ� �浹 �̺�Ʈ ���� on���ֱ�
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("FootPrint.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("BlueFootPrint", "FootPrint.png", 10, 10, 0.3f, true);
		CurRenderer->ChangeAnimation("BlueFootPrint");
		CurRenderer->SetPosition({ 113,300 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();


		//  ���̾�α� �����ϴ� �ݸ���
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 40, 40 });
		Collision->SetColType(ECollisionType::Rect);

	}

	Script.push_back("���� �ڿ��� Ǫ�� ��ü�� �帣�� �ִ�......");
	Script.push_back("[����� ���]�� �˷��ٲ�......");

	//StateChange(EPlayState::Event);
}

void ABluePaint::StateChange(EPlayState _State)
{
	switch (_State)
	{
	case EPlayState::None:
		break;
	case EPlayState::Event:
		break;
	default:
		break;
	}

	State = _State;
}


void ABluePaint::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	if (State == EPlayState::None)
	{

		// 1. �÷��̾�� �ݸ��� üũ �ϸ� ù��° ���̾�α� ����ش�.
		if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
		{
			//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
			//Ű�� �����ٸ� Textbox�� ��µǰ� �����
			if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
			{
				Dialogue->SetActive(true);
				Dialogue->ArtTextBoxRendererOn();
				Dialogue->SetText(Script[CurTextIndex]);
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
			{
				++CurTextIndex;

				Dialogue->SetActive(false);
				StateChange(EPlayState::Event);
				return;
			}
		}
	}

	// 2. �ٴڿ� ���� ����ֱ�
	if (State == EPlayState::Event)
	{
		DelayTime -= _DeltaTime;
		if (0.0 >= DelayTime)
		{
			++CurRenderIndex;

			if (CurRenderIndex >= 7)
			{
				Renderers[0]->ActiveOff();
			}

			if (CurRenderIndex >= 8)
			{
				StateChange(EPlayState::Talk);
				return;
			}

			Renderers[CurRenderIndex]->ActiveOn();
			// ������ ���� �־�� ��.
			DelayTime = 0.2f;
		}
	}

	if (State == EPlayState::Talk)
	{
		// 3. ���� ���ڶ� �ι�° ���̾�α� ����ش�.
		if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
		{
			//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
			//Ű�� �����ٸ� Textbox�� ��µǰ� �����
			if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
			{
				Dialogue->SetActive(true);
				Dialogue->ArtTextBoxRendererOn();
				Dialogue->SetText(Script[CurTextIndex]);
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
			{
				Renderers[CurRenderIndex]->ActiveOn();
				Dialogue->SetActive(false);
				//StateChange(EPlayState::None);
				return;
			}
		}
	}
}