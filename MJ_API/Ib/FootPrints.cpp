#include "FootPrints.h"
#include "Player.h"
#include "ThirdGalleryLevel.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

AFootPrints::AFootPrints()
{
}

AFootPrints::~AFootPrints()
{
}

void AFootPrints::BeginPlay()
{
	AActor::BeginPlay();
	{

		BGMPlayer = UEngineSound::SoundPlay("footsteps.ogg");
		BGMPlayer.Loop();
		BGMPlayer.SetVolume(0.5f);

		// 이미지컷팅하기(애니메이션용)
		UEngineResourcesManager::GetInst().CuttingImage("FootPrint.png", 7, 2);

		UImageRenderer* CurRenderer = nullptr;

		// 화면에 아트 이미지랜더 및 애니메이션 생성

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("FootPrint.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("BlueFootPrint", "FootPrint.png", 9, 9, 0.0f, true);
		CurRenderer->ChangeAnimation("BlueFootPrint");
		CurRenderer->SetPosition({ -100,50 });
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("FootPrint.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("BlueFootPrint", "FootPrint.png", 2, 2, 0.0f, true);
		CurRenderer->ChangeAnimation("BlueFootPrint");
		CurRenderer->SetPosition({ 120,120 });
		Renderers.push_back(CurRenderer);

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("FootPrint.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("BlueFootPrint", "FootPrint.png", 8, 8, 0.0f, true);
		CurRenderer->ChangeAnimation("BlueFootPrint");
		CurRenderer->SetPosition({ 270,-20 });
		Renderers.push_back(CurRenderer);


		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("FootPrint.png");
		CurRenderer->AutoImageScale();
		CurRenderer->CreateAnimation("BlueFootPrint", "FootPrint.png", 11, 11, 0.0f, true);
		CurRenderer->ChangeAnimation("BlueFootPrint");
		CurRenderer->SetPosition({500,0 });
		Renderers.push_back(CurRenderer);


		CurRenderer = CreateImageRenderer(PlayRenderOrder::BlueScreen);
		CurRenderer->SetImage("BlueScreen.png");
		CurRenderer->AutoImageScale();
		CurRenderer->SetAlpha(0.5);
		ScreenScale = GEngine->MainWindow.GetWindowScale();
		CurRenderer->SetTransform({ {ScreenScale.Half2D()} , ScreenScale });
		CurRenderer->ActiveOff();
		Renderers.push_back(CurRenderer);
		
		CurRenderer = CreateImageRenderer(PlayRenderOrder::BlackScreen);
		CurRenderer->SetImage("IntroBackGround.png");
		CurRenderer->AutoImageScale();
		CurRenderer->SetPosition({ 500,100 });
		CurRenderer->ActiveOff();
		Renderers.push_back(CurRenderer);

		//  다이얼로그 생성하는 콜리젼
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 40, 40 });
		Collision->SetPosition({ 500,40 });
		Collision->SetColType(ECollisionType::Rect);

	}

	//Script.push_back("액자 뒤에서 푸른 액체가 흐르고 있다......");
	//Script.push_back("[비밀의 장소]를 알려줄께......");

	//StateChange(EPlayState::Event);
}

void AFootPrints::Tick(float _DeltaTime)
{

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

		// 1. 플레이어 밑으로 빠지는 듯한 연출
		Player->StateChange(EPlayState::Sink);
		BGMPlayer.Off();

		// 2. 파란색 이미지랜더 띄어주기
		Renderers[4]->ActiveOn();
		
		FadeTime += _DeltaTime;
		if (0.5 >= FadeTime)
		{
		Renderers[4]->SetAlpha(FadeTime);
		Renderers[5]->ActiveOn();

		}

		// 3. 검정색 화면으로 덮기

		DelayTime += _DeltaTime;
		if (1.0 >= DelayTime)
		{
			Renderers[5]->SetAlpha(DelayTime);
		}
		else if (1.0 <= DelayTime)
		{
			Dialogue->SetActive(true);
			Dialogue->AllTextBoxRendererOff();
			Dialogue->SetText("과연 이브는 어디로 간걸까요?... \n\n  The End......",30.0f);

		}


	}


}