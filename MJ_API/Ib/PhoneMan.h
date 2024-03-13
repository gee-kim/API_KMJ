#pragma once
#include "Dialogue.h"
#include "Helper.h"
#include <EngineCore/Actor.h>

class APhoneMan : public AActor
{
public:
	APhoneMan();
	~APhoneMan();

	// delete Function
	APhoneMan(const APhoneMan& _Other) = delete;
	APhoneMan(APhoneMan&& _Other) noexcept = delete;
	APhoneMan& operator=(const APhoneMan& _Other) = delete;
	APhoneMan& operator=(APhoneMan&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	UCollision* Collisions = nullptr;

	ADialogue* Dialogue = nullptr;

};

