#include "IbCore.h"
#include "Player.h"
#include "Dialogue.h"
#include "TitleLevel.h"
#include "GalleryLevel.h"
#include "TestLevel.h"
#include "OpeningLevel.h"
#include "SecondGalleryLevel.h"
#include <EnginePlatform\EngineInput.h>
#include <EnginePlatform\EngineSound.h>
#include <EnginePlatform\WindowImage.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

IbCore::IbCore()
{
}

IbCore::~IbCore()
{
}


// 게임시작
void IbCore::BeginPlay()
{
	UEngineCore::BeginPlay();

	MainWindow.SetWindowScale({ 1280, 720 });
	MainWindow.SetWindowPosition({ 200, 0 });

	UEngineDirectory NewDir;

	NewDir.MoveParent();

	NewDir.Move("Ib_Resource");
	{
		//이미지로드
		std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

		// 엔진만의 규칙을 정할거냐.
		for (UEngineFile& File : NewList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}

		//캐릭터 이미지 1장으로 된거 애니메이션 돌려주기 위해서 cutting 해주기.
		UEngineResourcesManager::GetInst().CuttingImage("ib_00.png", 3, 4);
		//다른캐릭터도 넣어줘야함.
	}

	{
		//사운드로드

		std::list<UEngineFile> NewList = NewDir.AllFile({ ".wav", ".mp3", ".ogg"}, true);
		
		for (UEngineFile& File : NewList)
		{
			UEngineSound::Load(File.GetFullPath());
		}

		int a = 0;
	}

	CreateLevel<UTitleLevel>("Title");
	//CreateLevel<UOpeningLevel>("Opening");
	CreateLevel<UGalleryLevel>("Gallery");
	//CreateLevel<USecondGalleryLevel>("Second_Gallery");
	
	
	ChangeLevel("Gallery");
	//ChangeLevel("Second_Gallery");

	int a = 0;
}

void IbCore::Tick(float _DeltaTime)
{

	if (true == UEngineInput::IsDown(VK_F2))
	{
		GEngine->EngineDebugSwitch();
	}

	int a = 0;
}

void IbCore::End()
{
	int a = 0;
}
