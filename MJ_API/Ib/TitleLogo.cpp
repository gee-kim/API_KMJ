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
	//�̹��� ��ġ ����������
	SetActorLocation({ 50, 50 });
	//��ũ�� ��ġ 200, 50�� �ִ� ���¾�..
	Renderer->SetPosition({590, 310 });
	Renderer->SetScale( {1280, 720});

}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}
