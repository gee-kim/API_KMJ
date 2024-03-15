#include "BluePaint.h"
#include "Player.h"
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

		UImageRenderer* CurRenderer = nullptr;

		// 화면에 아트 이미지랜더 및 애니메이션 생성
		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("BluePaint.png");
		CurRenderer->AutoImageScale();
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("BlueLetter.png");
		CurRenderer->AutoImageScale();
		Renderers.push_back(CurRenderer);
		// 글자는 충돌 이벤트 이후 on해주기
		CurRenderer->ActiveOff();

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("FirstLetter", "!letters.png", 9, 9, 0.3f, true);
		CurRenderer->ChangeAnimation("FirstLetter");
		CurRenderer->SetPosition({ -200, 150 });
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("SecondLetter", "!letters.png", 10, 10, 0.3f, true);
		CurRenderer->ChangeAnimation("SecondLetter");
		CurRenderer->SetPosition({ -110, 200 });
		Renderers.push_back(CurRenderer);


		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("ThirdLetter", "!letters.png", 11, 11, 0.3f, true);
		CurRenderer->ChangeAnimation("ThirdLetter");
		CurRenderer->SetPosition({ 20, 100 });
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("FourthLetter", "!letters.png", 21, 21, 0.3f, true);
		CurRenderer->ChangeAnimation("FourthLetter");
		CurRenderer->SetPosition({ 170, 150 });
		Renderers.push_back(CurRenderer);


		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("FifthLetter", "!letters.png", 9, 9, 0.3f, true);
		CurRenderer->ChangeAnimation("FifthLetter");
		CurRenderer->SetPosition({ 260, 100 });
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!letters.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("SixthLetter", "!letters.png", 22, 22, 0.3f, true);
		CurRenderer->ChangeAnimation("SixthLetter");
		CurRenderer->SetPosition({ 370, 180 });
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("BlueImages.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("SixthLetter", "!letters.png", 22, 22, 0.3f, true);
		CurRenderer->ChangeAnimation("SixthLetter");
		CurRenderer->SetPosition({ 370, 180 });
		Renderers.push_back(CurRenderer);
		

		//CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		//CurRenderer->CreateAnimation("SixthLetter", "!letters.png", 22, 22, 0.3f, true);
		//CurRenderer->ChangeAnimation("SixthLetter");
		//Renderers.push_back(CurRenderer);


		//  다이얼로그 생성하는 콜리젼
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 40, 40 });
		Collision->SetColType(ECollisionType::Rect);

		

	}

	Script.push_back("액자 뒤에서 푸른 액체가 흐르고 있다......");
	Script.push_back("[비밀의 장소]를 알려줄께......");

	//StateChange(EPlayState::Event);
}

void ABluePaint::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	//StateUpdate(_DeltaTime);

}

