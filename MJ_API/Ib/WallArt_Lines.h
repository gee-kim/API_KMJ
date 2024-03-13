#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class APlayer;

class AWallArt_Lines : public AActor
{
public:
	AWallArt_Lines();
	~AWallArt_Lines();

	// delete Function
	AWallArt_Lines(const AWallArt_Lines& _Other) = delete;
	AWallArt_Lines(AWallArt_Lines&& _Other) noexcept = delete;
	AWallArt_Lines& operator=(const AWallArt_Lines& _Other) = delete;
	AWallArt_Lines& operator=(AWallArt_Lines&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	
	std::vector<UCollision*> Collisions;
	std::vector<UCollision*> Result;
	APlayer* Player = nullptr;

	ADialogue* Dialogue = nullptr;

};

