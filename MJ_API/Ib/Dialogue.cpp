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

void ADialogue::CreateText()
{
	TextRenderer = CreateImageRenderer(PlayRenderOrder::Text);
	TextRenderer->SetText("�̺� �ؽ�Ʈ �����Դϴ�");
	TextRenderer->CameraEffectOff();
	//�ؽ�Ʈ ������,��Ʈ, ���� üũ �ʿ�..
	TextRenderer->SetTextSize(20);
	TextRenderer->SetTextColor({ 255,255,255,0 });
	TextRenderer->SetFont("���");
	//TextRenderer->SetPosition({ 440,635 });
}

void ADialogue::BeginPlay()
{
	AActor::BeginPlay();
	
	//CharTextBox();
	ArtTextBox();
	CreateText();
	
	SetActive(false);
		//TestPlayer�� �ִ� StateChange �ϴ� ��� ���� ���� ¥����
}

void ADialogue::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

