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
	//��ũ�� ��ġ 200, 50�� �ִ� ���¾�..
	Renderer->SetPosition({644, 362 });
	Renderer->SetScale( {1288, 724});

}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}
