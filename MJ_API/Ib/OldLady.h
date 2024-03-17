#pragma once
#include "Dialogue.h"
#include "Helper.h"
#include <EngineCore/Actor.h>

class APlayer;

class AOldLady : public AActor
{
public:
	AOldLady();
	~AOldLady();

	// delete Function
	AOldLady(const AOldLady& _Other) = delete;
	AOldLady(AOldLady&& _Other) noexcept = delete;
	AOldLady& operator=(const AOldLady& _Other) = delete;
	AOldLady& operator=(AOldLady&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UImageRenderer* Renderer = nullptr;
	UCollision* Collision = nullptr;

	ADialogue* Dialogue = nullptr;
	APlayer* Player = nullptr;
};

