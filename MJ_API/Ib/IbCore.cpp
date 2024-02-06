#include "IbCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
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
	MainWindow.SetWindowPosition({ 200, 50 });

	UEngineDirectory NewDir;

	NewDir.MoveParent();

	NewDir.Move("Test_Resource");
	
	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// 엔진만의 규칙을 정할거냐.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("ib_00.png", 3, 4);


	CreateLevel<UTitleLevel>("Title");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("Title");
	// CreateLevel<UTitleLevel>("Title");
	int a = 0;
}

void IbCore::Tick(float _DeltaTime)
{
	int a = 0;
}

void IbCore::End()
{
	int a = 0;
}
