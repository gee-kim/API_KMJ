#include "PlayLevel.h"
#include "Player.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>

UPlayLevel::UPlayLevel()
{
}

UPlayLevel::~UPlayLevel()
{
}


void UPlayLevel::BeginPlay()
{
	// �����ΰ� ���;� �Ѵٰ� �����մϴ�.
	UEngineDirectory NewPath;

	NewPath.MoveParent();
	// NewPath.Move("ContentsResources");

	NewPath.Move("image source");
	NewPath.Move("Ib 2022");


	// Ȯ���ڵ� �������� ��ҹ��� ������ ������ �빮�ڷ� �ٲ㼭 ã�����̴�..
	std::list<UEngineFile> AllFileList = NewPath.AllFile({ ".png", ".bmp" }, true);

	// CherryBomb_0.png
	UEngineResourcesManager::GetInst().LoadImg("C:\\GM\\Win\\ContentsResources\\AAAA.png");

	// ULevel* const This = this;
	this->SpawnActor<Player>();

	// SpawnActor<Player>();

	// ������ 
	// �÷��̾�
	// ���
	// ����
	// ������ �ڵ�� ���⼭ �� ������ �Ѵ�.
}