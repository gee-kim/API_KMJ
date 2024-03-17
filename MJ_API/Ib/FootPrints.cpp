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

		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("FootPrint.png", 7, 2);

		UImageRenderer* CurRenderer = nullptr;

		// ȭ�鿡 ��Ʈ �̹������� �� �ִϸ��̼� ����

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

		//  ���̾�α� �����ϴ� �ݸ���
		Collision = CreateCollision(CollisionOrder::Art);
		Collision->SetScale({ 40, 40 });
		Collision->SetPosition({ 500,40 });
		Collision->SetColType(ECollisionType::Rect);

	}

	//Script.push_back("���� �ڿ��� Ǫ�� ��ü�� �帣�� �ִ�......");
	//Script.push_back("[����� ���]�� �˷��ٲ�......");

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
			MsgBoxAssert("�÷��̾ �ƴմϴ�.");
		}

		// 1. �÷��̾� ������ ������ ���� ����
		Player->StateChange(EPlayState::Sink);
		BGMPlayer.Off();

		// 2. �Ķ��� �̹������� ����ֱ�
		Renderers[4]->ActiveOn();
		
		FadeTime += _DeltaTime;
		if (0.5 >= FadeTime)
		{
		Renderers[4]->SetAlpha(FadeTime);
		Renderers[5]->ActiveOn();

		}

		// 3. ������ ȭ������ ����

		DelayTime += _DeltaTime;
		if (1.0 >= DelayTime)
		{
			Renderers[5]->SetAlpha(DelayTime);
		}
		else if (1.0 <= DelayTime)
		{
			Dialogue->SetActive(true);
			Dialogue->AllTextBoxRendererOff();
			Dialogue->SetText("���� �̺�� ���� ���ɱ��?... \n\n  The End......",30.0f);

		}


	}


}