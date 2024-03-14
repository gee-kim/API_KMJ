#include "Gallery_Window.h"
#include "Helper.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>

AGallery_Window::AGallery_Window()
{
}

AGallery_Window::~AGallery_Window()
{
}


void AGallery_Window::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("!$w_00.png", 3, 4);
		UEngineResourcesManager::GetInst().CuttingImage("!$w_01.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art_Back);
		CurRenderer->SetImage("!$w_00.png");
		CurRenderer->AutoImageScale();
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Window_1Floor", "!$w_00.png", 1, 1, 0.0f, true);
		CurRenderer->ChangeAnimation("Window_1Floor");


	}

}


void AGallery_Window::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	//if (nullptr == Dialogue)
	//{
	//	MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
	//	return;
	//}
	////std::vector<UCollision*> Result;

	//if (true == Collisions->CollisionCheck(CollisionOrder::Player, Result))
	//{
	//	//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
	//	//Ű�� �����ٸ� Textbox�� ��µǰ� �����
	//	if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
	//	{
	//		
	//		Dialogue->SetActive(true);
	//		Dialogue->CharTextBoxRendererOn();
	//		Dialogue->SetText("�� �� �ǿ�� �ñ�......");
	//	}
	//	else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
	//	{
	//		Dialogue->SetActive(false);
	//	}
	//}

}