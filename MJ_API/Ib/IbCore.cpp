#include "IbCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayLevel.h"

IbCore::IbCore()
{
}

IbCore::~IbCore()
{
}


// ���ӽ���
void IbCore::BeginPlay()
{

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
