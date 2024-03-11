#include "FadeIntro.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include "Helper.h"


AFadeIntro::AFadeIntro()
{
}

AFadeIntro::~AFadeIntro()
{
}


void AFadeIntro::BeginPlay()
{

	AActor::BeginPlay();
	
		FadeImage = CreateImageRenderer(PlayRenderOrder::Fade);
		//setalpha �� �ٲ��༭ fade ȿ�� �־��ֱ�
		FadeImage->SetImage("IntroBackGround.png");
		FadeImage->AutoImageScale();
		ImageScale = GEngine->MainWindow.GetWindowScale();
		FadeImage->SetTransform({ {640,690} , ImageScale });
	
}

void AFadeIntro::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);

	FadeTime -= _Deltatime;
	FadeImage->SetAlpha(FadeTime);


}
