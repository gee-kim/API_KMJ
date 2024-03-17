#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform\EngineSound.h>
#include "Dialogue.h"

class APlayer;

class ANoExit : public AActor
{
public:
	ANoExit();
	~ANoExit();

	// delete Function
	ANoExit(const ANoExit& _Other) = delete;
	ANoExit(ANoExit&& _Other) noexcept = delete;
	ANoExit& operator=(const ANoExit& _Other) = delete;
	ANoExit& operator=(ANoExit&& _Other) noexcept = delete;

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

	UEngineSoundPlayer BGMSound;
};

