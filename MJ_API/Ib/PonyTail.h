#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class APonyTail :public AActor
{
public:
	APonyTail();
	~APonyTail();

	// delete Function
	APonyTail(const APonyTail& _Other) = delete;
	APonyTail(APonyTail&& _Other) noexcept = delete;
	APonyTail& operator=(const APonyTail& _Other) = delete;
	APonyTail& operator=(APonyTail&& _Other) noexcept = delete;
	
	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	UCollision* Collision = nullptr;

	int CurTextIndex = 0;
	std::vector<std::string> Texts;

	ADialogue* Dialogue = nullptr;

};

