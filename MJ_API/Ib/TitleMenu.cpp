#include "TitleMenu.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include <EngineCore/EngineResourcesManager.h>

ATitleMenu::ATitleMenu()
{
}

ATitleMenu::~ATitleMenu()
{
}


void ATitleMenu::BeginPlay()
{
	AActor::BeginPlay();
	{
		UEngineResourcesManager::GetInst().CuttingImage("Command_0.png", 1, 2);
		UEngineResourcesManager::GetInst().CuttingImage("Command_1.png", 1, 2);
		UEngineResourcesManager::GetInst().CuttingImage("Command_2.png", 1, 2);
		UEngineResourcesManager::GetInst().CuttingImage("Command_3.png", 1, 2);

		UImageRenderer* CurCreateRenderer = nullptr;

		CurCreateRenderer = CreateImageRenderer(PlayRenderOrder::Text);
		CurCreateRenderer->SetImage("Command_0.png");
		CurCreateRenderer->SetTransform({ {300,450 }, {300,50 } });
		Renderers.push_back(CurCreateRenderer);

		CurCreateRenderer = CreateImageRenderer(PlayRenderOrder::Text);
		CurCreateRenderer->SetImage("Command_1.png");
		CurCreateRenderer->SetTransform({ {330,500 }, {300,50 } });
		Renderers.push_back(CurCreateRenderer);
		CurCreateRenderer = CreateImageRenderer(PlayRenderOrder::Text);
		CurCreateRenderer->SetImage("Command_2.png");
		CurCreateRenderer->SetTransform({ {360,550 }, {300,50 } });
		Renderers.push_back(CurCreateRenderer);
		CurCreateRenderer = CreateImageRenderer(PlayRenderOrder::Text);
		CurCreateRenderer->SetImage("Command_3.png");
		CurCreateRenderer->SetTransform({ {390,600 }, {300,50 } });
		Renderers.push_back(CurCreateRenderer);

		//Renderer->CreateAnimation("UnClick", "Command_0.png", 1, 1, 0.0f, true);
		//Renderer->CreateAnimation("Click", "Command_0.png", 0, 0, 0.0f, true);
		SelectChange(0);
	}


}

void ATitleMenu::SelectChange(int _Index)
{
	// �������� �����ŭ for�� ���鼭 �ε�����ȣ�� 1�� �̹����� �������ֱ�
	for (size_t i = 0; i < Renderers.size(); i++)
	{
		//
		Renderers[i]->SetImageIndex(1);
	}
	// �ε�����ȣ�� 0���� �̹����� �ʱ� ����
	Renderers[_Index]->SetImageIndex(0);
}

void ATitleMenu::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	// Up, DownŰ�� �̹��� ���Ʒ��� �����ϱ�
	if (UEngineInput::IsDown(VK_UP))
	{
		--SelectIndex;

		if (SelectIndex <= 0)
		{
			SelectIndex = 0;
		}
		SelectChange(SelectIndex);
	}

	if (UEngineInput::IsDown(VK_DOWN))
	{
		++SelectIndex;

		if (SelectIndex >= 3)
		{
			SelectIndex = 3;
		}
		SelectChange(SelectIndex);
	}

	if (UEngineInput::IsDown(VK_SPACE))
	{
		switch (SelectIndex)
		{
		case 0:
			GEngine->ChangeLevel("Gallery");
		case 1:
			break;
		case 2:
			break;
		case 3:
			GEngine->MainWindow.Off();

		default:
			break;
		}
	}

}