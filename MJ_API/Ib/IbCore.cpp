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


// ���ӽ���
void IbCore::BeginPlay()
{
	UEngineCore::BeginPlay();

	MainWindow.SetWindowScale({ 1280, 720 });

	UEngineDirectory NewDir;

	NewDir.MoveParent();

	//NewDir.Move("������");
	//
	//std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	//// �������� ��Ģ�� ���Ұų�.
	//for (UEngineFile& File : NewList)
	//{
	//	UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	//}

	//UEngineResourcesManager::GetInst().CuttingImage("Player_Right.png", 13, 8);
	//UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("PlayLevel\\TestFolderAnimation"));


	// "Title Level" + "�� ����ٰ� ������ �����ϴ�";

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
