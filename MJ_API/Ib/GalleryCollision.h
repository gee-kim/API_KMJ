#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialogue.h"

class AGalleryCollision : public AActor
{
public:
	AGalleryCollision();
	~AGalleryCollision();

	// delete Function
	AGalleryCollision(const AGalleryCollision& _Other) = delete;
	AGalleryCollision(AGalleryCollision&& _Other) noexcept = delete;
	AGalleryCollision& operator=(const AGalleryCollision& _Other) = delete;
	AGalleryCollision& operator=(AGalleryCollision&& _Other) noexcept = delete;

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

	UCollision* BodyCollision0 = nullptr;
	UCollision* BodyCollision1 = nullptr;
	UCollision* BodyCollision2 = nullptr;
	UCollision* BodyCollision3 = nullptr;

	ADialogue* Dialogue = nullptr;

};

