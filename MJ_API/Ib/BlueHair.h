#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class ABlueHair : public AActor
{
public:
	ABlueHair();
	~ABlueHair();

	// delete Function
	ABlueHair(const ABlueHair& _Other) = delete;
	ABlueHair(ABlueHair&& _Other) noexcept = delete;
	ABlueHair& operator=(const ABlueHair& _Other) = delete;
	ABlueHair& operator=(ABlueHair&& _Other) noexcept = delete;

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
	std::vector<std::string> Script;

	ADialogue* Dialogue = nullptr;

};

