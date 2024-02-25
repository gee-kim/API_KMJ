#include "IbCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "GalleryLevel.h"
#include "TestLevel.h"
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


// ���ӽ���
void IbCore::BeginPlay()
{
	UEngineCore::BeginPlay();

	MainWindow.SetWindowScale({ 1280, 720 });
	MainWindow.SetWindowPosition({ 200, 50 });

	UEngineDirectory NewDir;

	NewDir.MoveParent();

	NewDir.Move("Ib_Resource");
	{
		//�̹����ε�
		std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

		// �������� ��Ģ�� ���Ұų�.
		for (UEngineFile& File : NewList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}

		//ĳ���� �̹��� 1������ �Ȱ� �ִϸ��̼� �����ֱ� ���ؼ� cutting ���ֱ�.
		UEngineResourcesManager::GetInst().CuttingImage("Title1.png", 13, 1);
		UEngineResourcesManager::GetInst().CuttingImage("ib_00.png", 3, 4);
		//�ٸ�ĳ���͵� �־������.
	}

	{
		//����ε�

		//std::list<UEngineFile> NewList = NewDir.AllFile({ ".wav", ".mp3" }, true);
		//
		//for (UEngineFile& File : NewList)
		//{
		//	UEngineSound::Load(File.GetFullPath());
		//}

	}

	CreateLevel<UTitleLevel>("Title");
	CreateLevel<UGalleryLevel>("Gallery");
	//CreateLevel<UTestLevel>("Test");

	ChangeLevel("Title");

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
