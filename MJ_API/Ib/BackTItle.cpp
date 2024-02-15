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

	//������ �����ϰ� �ִϸ��̼� �־���ϴµ�?
	UImageRenderer* Renderer = CreateImageRenderer(1);

	Renderer->SetImage("Title1.png");
	Renderer->SetTransform({ {0,0}, {1020, 720} }); 
	Renderer->CreateAnimation("BackFlow", "Title1.png", 0, 12, 1.0f, true);
	Renderer->ChangeAnimation("BackFlow");

}

void ABackTitle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	int a = 0;
}