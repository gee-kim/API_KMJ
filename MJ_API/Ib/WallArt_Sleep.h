#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWallArt_Sleep : public AActor
{
public:
	AWallArt_Sleep();
	~AWallArt_Sleep();

	// delete Function
	AWallArt_Sleep(const AWallArt_Sleep& _Other) = delete;
	AWallArt_Sleep(AWallArt_Sleep&& _Other) noexcept = delete;
	AWallArt_Sleep& operator=(const AWallArt_Sleep& _Other) = delete;
	AWallArt_Sleep& operator=(AWallArt_Sleep&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UCollision*> Collisions;
	std::vector<UCollision*> Result;
	APlayer* Player = nullptr;

	ADialogue* Dialogue = nullptr;

};


