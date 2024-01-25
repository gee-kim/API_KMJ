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

	//std::string_view _Name = "AAAAA";
	//std::string ErrorText = "이미 존재하는 이름의 레벨을 또 만들려고 했습니다" + _Name;
	//MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); 
	//assert(false);

	//std::string ErrorText;
	//ErrorText = std::string("Title Level") + std::string("을 만들다가 에러가 났습니다");

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
