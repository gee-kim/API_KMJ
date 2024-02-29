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
	// 랜더러의 사이즈만큼 for문 돌면서 인덱스번호가 1인 이미지를 셋팅해주기
	for (size_t i = 0; i < Renderers.size(); i++)
	{
		//
		Renderers[i]->SetImageIndex(1);
	}
	// 인덱스번호가 0번인 이미지로 초기 셋팅
	Renderers[_Index]->SetImageIndex(0);
}

void ATitleMenu::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	// Up, Down키로 이미지 위아래로 선택하기
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