#include "Intro.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include "Helper.h"

AIntro::AIntro()
{
}

AIntro::~AIntro()
{
}


void AIntro::BeginPlay()
{


	AActor::BeginPlay();
	{
		// ȭ�鿡 ������ ���� ����ֱ�
		BackGround = CreateImageRenderer(PlayRenderOrder::Map);
		//setalpha �� �ٲ��༭ fade ȿ�� �־��ֱ�
		BackGround->SetImage("IntroBackGround.png");
		BackGround->AutoImageScale();
		ImageScale = GEngine->MainWindow.GetWindowScale();
		BackGround->SetTransform({ ImageScale.Half2D(), ImageScale });
		//BackGround->SetAlpha()

		FadeImage = CreateImageRenderer(PlayRenderOrder::Fade);
		//setalpha �� �ٲ��༭ fade ȿ�� �־��ֱ�
		FadeImage->SetImage("IntroFadeImage.png");
		FadeImage->AutoImageScale();
		ImageScale = GEngine->MainWindow.GetWindowScale();
		FadeImage->SetTransform({ ImageScale.Half2D(), ImageScale });
		//BackG round->SetAlpha()
	}
	{
		Script.push_back("�ѳ��� ȸ���� �ϴ� �Ʒ�......");
		Script.push_back("�̺�� �׳��� �θ���� �̼������� ���� �־����ϴ�......");
		Script.push_back("'������ ����? �̺�'");
		Script.push_back("'�´�, �ռ����� ì���?\n        ���ݾ�, ���ϼ����� �����'");
		Script.push_back("'�ָӴ� �ȿ� �� ì�ܵ־� ��? �Ҿ������ �� �ȴ�'");
	
		

	}
	
}

void AIntro::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	BGMPlayer = UEngineSound::SoundPlay("Prologue.ogg");
	BGMPlayer.SetVolume(0.5f);
	BGMPlayer.Loop();

	FadeTime -= _DeltaTime;
	FadeImage->SetAlpha(FadeTime);

	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}
	if (FadeTime <= 0)
	{
		Dialogue->SetActive(true);
		Dialogue->AllTextBoxRendererOff();
		Dialogue->SetText(Script[CurTextIndex]);
	}
	
	
	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		++CurTextIndex;

		if (CurTextIndex >= Script.size())
		{
			BGMPlayer.Off();
			GEngine->ChangeLevel("Gallery");
			return;
		}

		Dialogue->SetText(Script[CurTextIndex]);
	}


}