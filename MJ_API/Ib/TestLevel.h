#pragma once
#include "Dialogue.h"

class UTestLevel : public ULevel
{
public:
	UTestLevel();
	~UTestLevel();

	// delete Function
	UTestLevel(const UTestLevel& _Other) = delete;
	UTestLevel(UTestLevel&& _Other) noexcept = delete;
	UTestLevel& operator=(const UTestLevel& _Other) = delete;
	UTestLevel& operator=(UTestLevel&& _Other) noexcept = delete;


	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	
private:
	std::vector<UImageRenderer*> Renderers;
	std::vector<UCollision*> Collisions;

	int CurTextIndex = 0;
	std::vector<std::string> Script;

	ADialogue* Dialogue = nullptr;


};

