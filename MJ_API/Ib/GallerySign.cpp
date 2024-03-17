#include "GallerySign.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include "Helper.h"
#include "Player.h"

AGallerySign::AGallerySign()
{
}

AGallerySign::~AGallerySign()
{
}

void AGallerySign::BeginPlay()
{
	AActor::BeginPlay();
	{
		// �÷��̾�� �浹ü����
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetScale({ 40, 40 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

	}

	Script.push_back("[������� �Ը��׳����� ���迡]\n\n        ������ ? ? ? �ּż� �������� ����帳�ϴ�.");
	Script.push_back("���������� ���� [���̽� �Ը��׳���]��\n\n     ? ? �ϰ� �ֽ��ϴ�.");
	Script.push_back("�Ը��׳����� ���⿡ �׸��� �Ƹ��ٿ� ��ǰ����\n\n    �ε� ���� ���´�� ����ֽñ� �ٶ��ϴ�.");
	Script.push_back("������� ���� �� ���� ���ڰ� �־�......");
}



void AGallerySign::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue�� ���õ��� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions[0]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//�÷��̾�� �浹�� �Ͼ�� Ű�������°� üũ�ϰ�,
		//Ű�� �����ٸ� Textbox�� ��µǰ� �����
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			AActor* Owner = Result[0]->GetOwner();

			Player = dynamic_cast<APlayer*>(Owner);

			if (nullptr == Player)
			{
				MsgBoxAssert("�÷��̾ �ƴմϴ�.");
			}

			// Űüũ�� ������ �÷��̾�� �������� ���ϴ� ���°� ��.
			Player->StateChange(EPlayState::Event);

			Dialogue->SetActive(true);
			Dialogue->ArtTextBoxRendererOn();
			Dialogue->SetText(Script[CurTextIndex]);
		}
		else if (true == UEngineInput::IsDown(VK_SPACE) && true == Dialogue->IsActive())
		{
			++CurTextIndex;

			if (CurTextIndex >= Script.size())
			{
				CurTextIndex = 0;
				Player->StateChange(EPlayState::Idle);
				Dialogue->SetActive(false);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);
		}
	}

}