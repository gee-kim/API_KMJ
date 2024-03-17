#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWallArt_White : public AActor
{
public:
	AWallArt_White();
	~AWallArt_White();

	// delete Function
	AWallArt_White(const AWallArt_White& _Other) = delete;
	AWallArt_White(AWallArt_White&& _Other) noexcept = delete;
	AWallArt_White& operator=(const AWallArt_White& _Other) = delete;
	AWallArt_White& operator=(AWallArt_White&& _Other) noexcept = delete;

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


