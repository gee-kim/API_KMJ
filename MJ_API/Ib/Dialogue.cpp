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

void ADialogue::CharTextBox()
{
	CharTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	CharTextBoxRenderer->SetImage("msw_00.png");
	CharTextBoxRenderer->SetTransform({ {0, 0}, { 1280, 164 } });
	CharTextBoxRenderer->CameraEffectOff();

}

void ADialogue::ArtTextBox()
{
	ArtTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	ArtTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
	ArtTextBoxRenderer->SetImage("msw_02.png");
	ArtTextBoxRenderer->CameraEffectOff();
}

void ADialogue::CreateTextBox(std::string Text)
{
	//switch(Text)
	//{
	//case(CollisionOrder::Art):
	//	break;
	//}
}

void ADialogue::CreateText(std::string Text)
{
	TextRenderer = CreateImageRenderer(PlayRenderOrder::Text);
	TextRenderer->SetText(Text);
	TextRenderer->CameraEffectOff();
	//텍스트 사이즈,폰트, 색깔 체크 필요..
	TextRenderer->SetTextSize(20);
	TextRenderer->SetTextColor({ 255,255,255,0 });
	TextRenderer->SetFont("고딕");
	//TextRenderer->SetPosition({ 440,635 });
}

void ADialogue::EndDialogue()
{
	SetActive(false);
}

void ADialogue::BeginPlay()
{
	AActor::BeginPlay();
	
	SetActive(false);
	
	//키
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			SetActive(false);
			return;
		}
		
		//TestPlayer에 있는 StateChange 하는 방식 보고 로직 짜보자
}

void ADialogue::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	

}

