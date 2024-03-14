#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class APlayer;

class AExit : public AActor
{
public:
	AExit();
	~AExit();

	// delete Function
	AExit(const AExit& _Other) = delete;
	AExit(AExit&& _Other) noexcept = delete;
	AExit& operator=(const AExit& _Other) = delete;
	AExit& operator=(AExit&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UCollision* Collision = nullptr;
	std::vector<UCollision*> Result;

	APlayer* Player = nullptr;

	ADialogue* Dialogue = nullptr;


};

