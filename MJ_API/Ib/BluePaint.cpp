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
		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("!letters.png", 12, 8);
		UEngineResourcesManager::GetInst().CuttingImage("FootPrint.png", 7, 2);

		UImageRenderer* CurRenderer = nullptr;

		// 화면에 아트 이미지랜더 및 애니메이션 생성
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
		// 글자는 충돌 이벤트 이후 on해주기
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("FootPrint.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("BlueFootPrint", "FootPrint.png", 10, 10, 0.3f, true);
		CurRenderer->ChangeAnimation("BlueFootPrint");
		CurRenderer->SetPosition({ 113,300 });
		Renderers.push_back(CurRenderer);
		CurRenderer->ActiveOff();


		//  다이얼로그 생성하는 콜리젼
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 40, 40 });
		Collision->SetColType(ECollisionType::Rect);

	}

	Script.push_back("액자 뒤에서 푸른 액체가 흐르고 있다......");
	Script.push_back("[비밀의 장소]를 알려줄께......");

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
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	if (State == EPlayState::None)
	{

		// 1. 플레이어와 콜리젼 체크 하면 첫번째 다이얼로그 띄어준다.
		if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
		{
			//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
			//키가 눌린다면 Textbox가 출력되게 만들기
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

	// 2. 바닥에 글자 띄어주기
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
			// 비지엠 사운드 넣어야 함.
			DelayTime = 0.2f;
		}
	}

	if (State == EPlayState::Talk)
	{
		// 3. 벽의 글자랑 두번째 다이얼로그 띄어준다.
		if (true == Collision->CollisionCheck(CollisionOrder::Player, Result))
		{
			//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
			//키가 눌린다면 Textbox가 출력되게 만들기
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