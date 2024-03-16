#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class APlayer;


class AArtSign : public AActor
{
public:
	AArtSign();
	~AArtSign();

	// delete Function
	AArtSign(const AArtSign& _Other) = delete;
	AArtSign(AArtSign&& _Other) noexcept = delete;
	AArtSign& operator=(const AArtSign& _Other) = delete;
	AArtSign& operator=(AArtSign&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	APlayer* Player = nullptr;
	UCollision* Collision = nullptr;
	ADialogue* Dialogue = nullptr;

};

