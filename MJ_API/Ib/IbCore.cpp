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


// 게임시작
void IbCore::BeginPlay()
{

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
