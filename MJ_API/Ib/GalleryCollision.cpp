#include "GalleryCollision.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"
#include <EngineCore/EngineResourcesManager.h>

AGalleryCollision::AGalleryCollision()
{
}

AGalleryCollision::~AGalleryCollision()
{
}

void AGalleryCollision::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �̹��������ϱ�(�ִϸ��̼ǿ�)
		UEngineResourcesManager::GetInst().CuttingImage("$mob_00.png", 3, 4);
		UEngineResourcesManager::GetInst().CuttingImage("$mob_01.png", 3, 4);
		UEngineResourcesManager::GetInst().CuttingImage("$mob_02.png", 3, 4);
		UEngineResourcesManager::GetInst().CuttingImage("$mob_03.png", 3, 4);
		UEngineResourcesManager::GetInst().CuttingImage("!$w_00.png", 3, 4);

		// ȭ�鿡 ��Ʈ�� ĳ���͵� �̹�������
		UImageRenderer* CurRenderer = nullptr;

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Characters);
		CurRenderer->SetImage("$mob_00.png");
		CurRenderer->SetTransform({ {0,60}, {48, 96} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Window_Man", "$mob_00.png", 2, 2, 0.0f, true);
		CurRenderer->ChangeAnimation("Window_Man");

		CurRenderer = CreateImageRenderer(PlayRenderOrder::Art);
		CurRenderer->SetImage("!$w_00.png");
		CurRenderer->SetTransform({ {0,20}, {80, 90} });
		Renderers.push_back(CurRenderer);
		CurRenderer->CreateAnimation("Window_1Floor", "!$w_00.png", 1, 1, 0.0f, true);
		CurRenderer->ChangeAnimation("Window_1Floor");

		// �÷��̾�� �浹ü����
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetScale({ 100, 100 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetPosition({ 2000, 0 });
		CurCreateCollsions->SetScale({ 100, 100 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetPosition({ 4000,0 });
		CurCreateCollsions->SetScale({ 100, 100 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetPosition({ 6000, 0 });
		CurCreateCollsions->SetScale({ 100, 100 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

	}

}


void AGalleryCollision::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	//if (true == Dialogue->IsActive())
	//{
	//	if (true == UEngineInput::IsDown(VK_SPACE))
	//	{
	//		Dialogue->SetActive(false);
	//	}
	//}

	std::vector<UCollision*> Result;

	if (true == Collisions[0]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			Dialogue->SetActive(true);
		}
		else if(true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			Dialogue->SetActive(false);
		}
	}

	if (true == Collisions[1]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			Dialogue->SetActive(true);

		}
	}

	if (true == Collisions[2]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			Dialogue->SetActive(true);

		}
	}

	if (true == Collisions[3]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			Dialogue->SetActive(true);

		}
	}



}