#include "GallerySign.h"
#include <EngineBase\EngineDebug.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include "Helper.h"


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
		// 플레이어와 충돌체랜더
		UCollision* CurCreateCollsions = nullptr;

		CurCreateCollsions = CreateCollision(CollisionOrder::Art);
		CurCreateCollsions->SetPosition(GetActorLocation());
		CurCreateCollsions->SetScale({ 50, 50 });
		CurCreateCollsions->SetColType(ECollisionType::Rect);
		Collisions.push_back(CurCreateCollsions);

	}

	Script.push_back("'어서오세요 게르테나전의 세계에'\n        오늘은 ? ? ? 주셔서 진심으로 감사드립니다.");
	Script.push_back("본관에서는 현재 '바이스 게르테나전'을\n     ? ? 하고 있습니다.");
	Script.push_back("게르테나씨가 말년에 그리신 아름다운 작품들을\n    부디 마음 가는대로 즐겨주시기 바랍니다.");
	Script.push_back("어려워서 읽을 수 없는 글자가 있어......");
}



void AGallerySign::Tick(float _DeltaTime)
{
	if (nullptr == Dialogue)
	{
		MsgBoxAssert("Dialogue가 셋팅되지 않아서 동작이 불가능합니다.");
		return;
	}

	AActor::Tick(_DeltaTime);

	std::vector<UCollision*> Result;

	if (true == Collisions[0]->CollisionCheck(CollisionOrder::Player, Result))
	{
		//플레이어와 충돌이 일어나면 키가눌리는거 체크하고,
		//키가 눌린다면 Textbox가 출력되게 만들기
		if (true == UEngineInput::IsDown(VK_SPACE) && false == Dialogue->IsActive())
		{
			//StateChange("Talk");
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
				Dialogue->SetActive(false);
				return;
			}

			Dialogue->SetText(Script[CurTextIndex]);
		}
	}

}