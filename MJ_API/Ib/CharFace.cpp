#include "CharFace.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include "Windows.h"
#include <EngineCore/EngineResourcesManager.h>

ACharFace::ACharFace()
{
}

ACharFace::~ACharFace()
{
}


void ACharFace::SetMomSmileFace()
{
	MomSmileFace->ActiveOn();
	MomUpsetFace->ActiveOff();
	MomBigSmileFace->ActiveOff();
	MomAngryFace->ActiveOff();
	DadSmileFace->ActiveOff();

}

void ACharFace::SetDadSmileFace()
{
	MomSmileFace->ActiveOff();
	MomUpsetFace->ActiveOff();
	MomBigSmileFace->ActiveOff();
	MomAngryFace->ActiveOff();
	DadSmileFace->ActiveOn();

}

void ACharFace::SetMomBigSmileFace()
{
	MomSmileFace->ActiveOff();
	MomUpsetFace->ActiveOff();
	MomBigSmileFace->ActiveOn();
	MomAngryFace->ActiveOff();
	DadSmileFace->ActiveOff();

}
void ACharFace::SetMomAngryFace()
{
	MomSmileFace->ActiveOff();
	MomUpsetFace->ActiveOff();
	MomBigSmileFace->ActiveOff();
	MomAngryFace->ActiveOn();
	DadSmileFace->ActiveOff();

}
void ACharFace::SetMomUpsetFace()
{
	MomSmileFace->ActiveOff();
	MomUpsetFace->ActiveOn();
	MomBigSmileFace->ActiveOff();
	MomAngryFace->ActiveOff();
	DadSmileFace->ActiveOff();

}


void ACharFace::BeginPlay()
{
	AActor::BeginPlay();


	MomSmileFace = CreateImageRenderer(PlayRenderOrder::Dialogue);
	MomSmileFace->SetImage("mo_00.png");
	MomSmileFace->AutoImageScale();
	MomSmileFace->CameraEffectOff();
	MomSmileFace->ActiveOff();

	MomUpsetFace = CreateImageRenderer(PlayRenderOrder::Dialogue);
	MomUpsetFace->SetImage("mo_08.png");
	MomUpsetFace->AutoImageScale();
	MomUpsetFace->CameraEffectOff();
	MomUpsetFace->ActiveOff();

	MomBigSmileFace = CreateImageRenderer(PlayRenderOrder::Dialogue);
	MomBigSmileFace->SetImage("mo_01.png");
	MomBigSmileFace->AutoImageScale();
	MomBigSmileFace->CameraEffectOff();
	MomBigSmileFace->ActiveOff();

	MomAngryFace = CreateImageRenderer(PlayRenderOrder::Dialogue);
	MomAngryFace->SetImage("mo_02.png");
	MomAngryFace->AutoImageScale();
	MomAngryFace->CameraEffectOff();
	MomAngryFace->ActiveOff();

	DadSmileFace = CreateImageRenderer(PlayRenderOrder::Dialogue);
	DadSmileFace->SetImage("f_01.png");
	DadSmileFace->AutoImageScale();
	DadSmileFace->SetPosition({ -22,0 });
	DadSmileFace->CameraEffectOff();
	DadSmileFace->ActiveOff();


	SetActive(false);

}

void ACharFace::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}
