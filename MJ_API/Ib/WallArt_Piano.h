#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWallArt_Piano : public AActor
{
public:
	AWallArt_Piano();
	~AWallArt_Piano();

	// delete Function
	AWallArt_Piano(const AWallArt_Piano& _Other) = delete;
	AWallArt_Piano(AWallArt_Piano&& _Other) noexcept = delete;
	AWallArt_Piano& operator=(const AWallArt_Piano& _Other) = delete;
	AWallArt_Piano& operator=(AWallArt_Piano&& _Other) noexcept = delete;

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


