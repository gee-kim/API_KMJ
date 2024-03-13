#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWindowMan : public AActor
{
public:
	AWindowMan();
	~AWindowMan();

	// delete Function
	AWindowMan(const AWindowMan& _Other) = delete;
	AWindowMan(AWindowMan&& _Other) noexcept = delete;
	AWindowMan& operator=(const AWindowMan& _Other) = delete;
	AWindowMan& operator=(AWindowMan&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	UCollision* Collisions = nullptr;

	std::vector<UCollision*> Result;
	APlayer* Player = nullptr;

	ADialogue* Dialogue = nullptr;

};

