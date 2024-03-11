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
		// 화면에 검정색 바탕 깔아주기
		BackGround = CreateImageRenderer(PlayRenderOrder::Map);
		//setalpha 값 바꿔줘서 fade 효과 넣어주기
		BackGround->SetImage("IntroBackGround.png");
		BackGround->AutoImageScale();
		ImageScale = GEngine->MainWindow.GetWindowScale();
		BackGround->SetTransform({ ImageScale.Half2D(), ImageScale });
		//BackGround->SetAlpha()

		FadeImage = CreateImageRenderer(PlayRenderOrder::Fade);
		//setalpha 값 바꿔줘서 fade 효과 넣어주기
		FadeImage->SetImage("IntroFadeImage.png");
		FadeImage->AutoImageScale();
		ImageScale = GEngine->MainWindow.GetWindowScale();
		FadeImage->SetTransform({ ImageScale.Half2D(), ImageScale });
		//BackG round->SetAlpha()
	}
	{
		Script.push_back("한낮의 회색빛 하늘 아래......");
		Script.push_back("이브와 그녀의 부모님은 미술관으로 가고 있었습니다......");
		Script.push_back("'잊은건 없니? 이브'");
		Script.push_back("'맞다, 손수건은 챙겼니?\n        있잖아, 생일선물로 줬던거'");
		Script.push_back("'주머니 안에 잘 챙겨둬야 해? 잃어버리면 안 된다'");
	
		

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
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
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