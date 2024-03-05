#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class ARightBigArt : public AActor
{
public:
	ARightBigArt();
	~ARightBigArt();

	// delete Function
	ARightBigArt(const ARightBigArt& _Other) = delete;
	ARightBigArt(ARightBigArt&& _Other) noexcept = delete;
	ARightBigArt& operator=(const ARightBigArt& _Other) = delete;
	ARightBigArt& operator=(ARightBigArt&& _Other) noexcept = delete;

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

