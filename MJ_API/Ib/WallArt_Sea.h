#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class AWallArt_Sea : public AActor
{
public:
	AWallArt_Sea();
	~AWallArt_Sea();

	// delete Function
	AWallArt_Sea(const AWallArt_Sea& _Other) = delete;
	AWallArt_Sea(AWallArt_Sea&& _Other) noexcept = delete;
	AWallArt_Sea& operator=(const AWallArt_Sea& _Other) = delete;
	AWallArt_Sea& operator=(AWallArt_Sea&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UCollision* Collision = nullptr;

	ADialogue* Dialogue = nullptr;

};

