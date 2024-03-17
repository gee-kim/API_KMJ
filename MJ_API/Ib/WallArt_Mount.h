#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWallArt_Mount : public AActor
{
public:
	AWallArt_Mount();
	~AWallArt_Mount();

	// delete Function
	AWallArt_Mount(const AWallArt_Mount& _Other) = delete;
	AWallArt_Mount(AWallArt_Mount&& _Other) noexcept = delete;
	AWallArt_Mount& operator=(const AWallArt_Mount& _Other) = delete;
	AWallArt_Mount& operator=(AWallArt_Mount&& _Other) noexcept = delete;

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


