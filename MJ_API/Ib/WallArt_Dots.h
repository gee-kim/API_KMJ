#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWallArt_Dots : public AActor
{
public:
	AWallArt_Dots();
	~AWallArt_Dots();

	// delete Function
	AWallArt_Dots(const AWallArt_Dots& _Other) = delete;
	AWallArt_Dots(AWallArt_Dots&& _Other) noexcept = delete;
	AWallArt_Dots& operator=(const AWallArt_Dots& _Other) = delete;
	AWallArt_Dots& operator=(AWallArt_Dots&& _Other) noexcept = delete;

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




