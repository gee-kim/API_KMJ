#include "Dialog.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"


ADialog::ADialog()
{
}

ADialog::~ADialog()
{
}

void ADialog::BeginPlay()
{
	AActor::BeginPlay();

	TextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialog);
	TextBoxRenderer->SetImage("msw_02.png");
	TextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
	TextBoxRenderer->CameraEffectOff();

	
	TextRenderer = CreateImageRenderer(PlayRenderOrder::Text);
	TextRenderer -> SetText("이브 텍스트 문구입니당");
	TextRenderer->CameraEffectOff();
	//텍스트 사이즈,폰트, 색깔 체크 필요..
	TextRenderer->SetTextSize(20);
	TextRenderer->SetTextColor({255,255,255,0 });
	TextRenderer->SetFont("고딕");
	//TextRenderer->SetPosition({ 440,635 });
	
	SetActive(false);
}

void ADialog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

