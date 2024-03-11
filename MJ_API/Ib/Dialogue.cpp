#include "Dialogue.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "Windows.h"
#include <EngineCore/EngineResourcesManager.h>


ADialogue::ADialogue()
{
}

ADialogue::~ADialogue()
{
}


void ADialogue::SetText(std::string _Text, float _Value /*= 20*/, Color8Bit _Color /*= Color8Bit::White*/)
{
	Renderers[2]->ActiveOn();
	Renderers[2]->SetText(_Text);
	Renderers[2]->SetTextSize(_Value);
	Renderers[2]->SetTextColor(_Color);
	Renderers[2]->SetFont("°íµñ");
}

void ADialogue::CharTextBoxRendererOn()
{
	//SetActive(true);
	Renderers[0]->ActiveOn();
	Renderers[1]->ActiveOff();
}

void ADialogue::ArtTextBoxRendererOn()
{
	//SetActive(true);
	Renderers[0]->ActiveOff();
	Renderers[1]->ActiveOn();
}

void ADialogue::AllTextBoxRendererOff()
{
	Renderers[0]->ActiveOff();
	Renderers[1]->ActiveOff();
}
void ADialogue::SetMovingBoxPosition(FVector _Value)
{
	Renderers[3]->SetPosition(_Value);
}

void ADialogue::BeginPlay()
{
	AActor::BeginPlay();

	UEngineResourcesManager::GetInst().CuttingImage("moving.png", 5, 1);
	
	UImageRenderer* CharTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	CharTextBoxRenderer->SetImage("msw_02.png");
	CharTextBoxRenderer->SetTransform({ {0, 0}, { 1280, 164 } });
	CharTextBoxRenderer->CameraEffectOff();
	CharTextBoxRenderer->ActiveOff();
	Renderers.push_back(CharTextBoxRenderer);

	UImageRenderer*	ArtTextBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	ArtTextBoxRenderer->SetTransform({ {0,0}, {1280, 164} });
	ArtTextBoxRenderer->SetImage("msw_00.png");
	ArtTextBoxRenderer->CameraEffectOff();
	ArtTextBoxRenderer->ActiveOff();
	Renderers.push_back(ArtTextBoxRenderer);
	
	UImageRenderer* TextRenderer = CreateImageRenderer(PlayRenderOrder::Text);
	TextRenderer->SetPosition({ -50,0 });
	TextRenderer->CameraEffectOff();
	TextRenderer->ActiveOff();
	Renderers.push_back(TextRenderer);

	UImageRenderer* MovingBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	MovingBoxRenderer->SetImage("moving.png");
	MovingBoxRenderer->AutoImageScale();
	MovingBoxRenderer->SetPosition({ 0,80 });
	//MovingBoxRenderer->SetTransform({ {0, 0}, { 1280, 194 } });
	MovingBoxRenderer->CameraEffectOff();
	MovingBoxRenderer->ActiveOff();
	Renderers.push_back(MovingBoxRenderer);
	MovingBoxRenderer->CreateAnimation("Moving", "moving.png", 0, 3, 0.2, true);
	MovingBoxRenderer->ChangeAnimation("Moving");
	//UImageRenderer* MovingBoxRenderer = CreateImageRenderer(PlayRenderOrder::Dialogue);
	//MovingBoxRenderer->SetImage("");

	SetActive(false);
	
}

void ADialogue::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	

}
