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


void ADialog::CharTextBox()
{
	CharTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialog);
	CharTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });

	CharTextBoxRenderer->SetImage("msw_00.png");
}

void ADialog::ArtTextBox()
{
	ArtTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialog);
	ArtTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
	ArtTextBoxRenderer->SetImage("msw_02.png");
}

void ADialog::CreateText()
{
	TextRenderer = CreateImageRenderer(PlayRenderOrder::Text);
	TextRenderer->SetText("이브 텍스트 문구입니당");
	TextRenderer->CameraEffectOff();
	//텍스트 사이즈,폰트, 색깔 체크 필요..
	TextRenderer->SetTextSize(20);
	TextRenderer->SetTextColor({ 255,255,255,0 });
	TextRenderer->SetFont("고딕");
	//TextRenderer->SetPosition({ 440,635 });
}

void ADialog::BeginPlay()
{
	AActor::BeginPlay();
	
	
		SetActive(false);
		//TestPlayer에 있는 StateChange 하는 방식 보고 로직 짜보자
}

void ADialog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

