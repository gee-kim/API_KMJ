#pragma once
#include "Dialogue.h"
#include "Helper.h"
#include <EngineCore/Actor.h>

class APlayer;

class ABrownHair : public AActor
{
public:
	ABrownHair();
	~ABrownHair();

	// delete Function
	ABrownHair(const ABrownHair& _Other) = delete;
	ABrownHair(ABrownHair&& _Other) noexcept = delete;
	ABrownHair& operator=(const ABrownHair& _Other) = delete;
	ABrownHair& operator=(ABrownHair&& _Other) noexcept = delete;

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

