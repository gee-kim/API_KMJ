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

	//std::string_view _Name = "AAAAA";
	//std::string ErrorText = "�̹� �����ϴ� �̸��� ������ �� ������� �߽��ϴ�" + _Name;
	//MessageBoxA(nullptr, ErrorText.c_str(), "ġ���� ����", MB_OK); 
	//assert(false);

	//std::string ErrorText;
	//ErrorText = std::string("Title Level") + std::string("�� ����ٰ� ������ �����ϴ�");

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
