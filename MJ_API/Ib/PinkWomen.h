#pragma once
#include "Dialogue.h"
#include "Helper.h"
#include <EngineCore/Actor.h>

class APlayer;

class APinkWomen : public AActor
{
public:
	APinkWomen();
	~APinkWomen();

	// delete Function
	APinkWomen(const APinkWomen& _Other) = delete;
	APinkWomen(APinkWomen&& _Other) noexcept = delete;
	APinkWomen& operator=(const APinkWomen& _Other) = delete;
	APinkWomen& operator=(APinkWomen&& _Other) noexcept = delete;

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

