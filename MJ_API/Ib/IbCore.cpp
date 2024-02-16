#include "IbCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "TestLevel.h"
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
	MainWindow.SetWindowPosition({ 200, 50 });

	UEngineDirectory NewDir;

	NewDir.MoveParent();

	NewDir.Move("Test_Resource");
	
	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// �������� ��Ģ�� ���Ұų�.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	//ĳ���� �̹��� 1������ �Ȱ� �ִϸ��̼� �����ֱ� ���ؼ� cutting ���ֱ�.
	UEngineResourcesManager::GetInst().CuttingImage("ib_00.png", 3, 4);
	UEngineResourcesManager::GetInst().CuttingImage("Title1.png", 13, 1);

	CreateLevel<UTitleLevel>("Title");
	CreateLevel<UPlayLevel>("Play");
	//CreateLevel<UTestLevel>("Test");

	ChangeLevel("Play");
	
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
