#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialogue.h"

class APoster : public AActor
{
public:
	APoster();
	~APoster();
	
	// delete Function
	APoster(const APoster& _Other) = delete;
	APoster(APoster&& _Other) noexcept = delete;
	APoster& operator=(const APoster& _Other) = delete;
	APoster& operator=(APoster&& _Other) noexcept = delete;
	
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

	ADialogue* Dialogue = nullptr;

};
