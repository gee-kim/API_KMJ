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

	UEngineDirectory NewDir;

	NewDir.MoveParent();

	//NewDir.Move("폴더명");
	//
	//std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	//// 엔진만의 규칙을 정할거냐.
	//for (UEngineFile& File : NewList)
	//{
	//	UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	//}

	//UEngineResourcesManager::GetInst().CuttingImage("Player_Right.png", 13, 8);
	//UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("PlayLevel\\TestFolderAnimation"));


	// "Title Level" + "을 만들다가 에러가 났습니다";

	SetFrame(60);

	CreateLevel<UTitleLevel>("Title");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
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
