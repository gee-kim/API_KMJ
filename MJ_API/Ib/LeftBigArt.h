#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class ALeftBigArt : public AActor
{
public:
	ALeftBigArt();
	~ALeftBigArt();

	// delete Function
	ALeftBigArt(const ALeftBigArt& _Other) = delete;
	ALeftBigArt(ALeftBigArt&& _Other) noexcept = delete;
	ALeftBigArt& operator=(const ALeftBigArt& _Other) = delete;
	ALeftBigArt& operator=(ALeftBigArt&& _Other) noexcept = delete;

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

