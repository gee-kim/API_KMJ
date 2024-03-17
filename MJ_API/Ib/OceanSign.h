#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class APlayer;

class AOceanSign : public AActor
{
public:
	AOceanSign();
	~AOceanSign();

	// delete Function
	AOceanSign(const AOceanSign& _Other) = delete;
	AOceanSign(AOceanSign&& _Other) noexcept = delete;
	AOceanSign& operator=(const AOceanSign& _Other) = delete;
	AOceanSign& operator=(AOceanSign&& _Other) noexcept = delete;

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

	int CurTextIndex = 0;
	std::vector<std::string> Script;

	ADialogue* Dialogue = nullptr;

};
