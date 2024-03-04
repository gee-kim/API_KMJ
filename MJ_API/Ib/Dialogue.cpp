#include "Dialogue.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "Windows.h"


ADialogue::ADialogue()
{
}

ADialogue::~ADialogue()
{
}


void ADialogue::SetText(std::string _Text, float _Value /*= 20*/, Color8Bit _Color /*= Color8Bit::White*/)
{
	TextRenderer->ActiveOn();
	TextRenderer->SetText(_Text);
	TextRenderer->SetTextSize(_Value);
	TextRenderer->SetTextColor(_Color);
	TextRenderer->SetFont("°íµñ");
}

void ADialogue::CharTextBoxRendererOn()
{
	SetActive(true);
	CharTextBoxRenderer->ActiveOn();
	ArtTextBoxRenderer->ActiveOff();
}

void ADialogue::ArtTextBoxRendererOn()
{
	SetActive(true);
	CharTextBoxRenderer->ActiveOff();
	ArtTextBoxRenderer->ActiveOn();
}

void ADialogue::BeginPlay()
{
	AActor::BeginPlay();
	
	CharTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	CharTextBoxRenderer->SetImage("msw_00.png");
	CharTextBoxRenderer->SetTransform({ {0, 0}, { 1280, 164 } });
	CharTextBoxRenderer->CameraEffectOff();

	ArtTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	ArtTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
	ArtTextBoxRenderer->SetImage("msw_02.png");
	ArtTextBoxRenderer->CameraEffectOff();
	ArtTextBoxRenderer->ActiveOff();

	TextRenderer = CreateImageRenderer(PlayRenderOrder::Text);
	TextRenderer->CameraEffectOff();
	TextRenderer->ActiveOff();

	SetActive(false);
	
}

void ADialogue::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	

}

