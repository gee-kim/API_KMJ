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
	
	{
		CharTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialog);
		CharTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
		CharTextBoxRenderer->CameraEffectOff();
		CharTextBoxRenderer->SetImage("msw_00.png");
	}	

	{
		ArtTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialog);
		ArtTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
		ArtTextBoxRenderer->CameraEffectOff();
		ArtTextBoxRenderer->SetImage("msw_02.png");
	}

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
		SetActive(false);
		//TestPlayer�� �ִ� StateChange �ϴ� ��� ���� ���� ¥����
}

void ADialog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

