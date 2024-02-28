#include "BackTitle.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"

ABackTitle::ABackTitle()
{
}

ABackTitle::~ABackTitle()
{
}

void ABackTitle::BeginPlay()
{
	AActor::BeginPlay();

	//랜더러 생성하고 애니메이션 넣어야하는데?
	Renderer1 = CreateImageRenderer(-1);
	Renderer1->SetImage("BackTitle1.png");
	Renderer2 = CreateImageRenderer(-1);
	Renderer2->SetImage("BackTitle1.png");
	Renderer1->SetTransform({ {800,365}, {270, 720} });
	Renderer2->SetTransform({ {1100,365}, {310, 720} });
	//Renderer->CreateAnimation("BackFlow", "Title1.png", 0, 12, 1.0f, true);
	//Renderer->ChangeAnimation("BackFlow");

}

void ABackTitle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	UWindowImage* Image1 = Renderer1->GetImage();
	UWindowImage* Image2 = Renderer2->GetImage();
	//Deltatime 29 되면 다시 0으로 셋팅되게?
	AnimationTime += _DeltaTime * 10.0f;

	FTransform Trans1 = FTransform(FVector(0.0f + AnimationTime, 0.0f), FVector(300.0f, 720.0f));
	FTransform Trans2 = FTransform(FVector(0.0f + AnimationTime, 0.0f), FVector(300.0f, 720.0f));
	
	Image1->SetCuttingTransform(Trans1, 0);
	Image2->SetCuttingTransform(Trans2, 0);

	if (AnimationTime >= 2979)
	{
		AnimationTime = 0;
	}


	int a = 0;
}