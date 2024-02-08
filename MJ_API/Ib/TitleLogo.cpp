#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
}

ATitleLogo::~ATitleLogo()
{
}

void ATitleLogo::BeginPlay()
{
	AActor::BeginPlay();

	UImageRenderer* Renderer = CreateImageRenderer();

	Renderer->SetImage("Title0.png");
	//이미지 위치 지정해주자
	//스크린 위치 200, 50에 있는 상태야..
	Renderer->SetPosition({644, 362 });
	Renderer->SetScale( {1288, 724});

}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}
