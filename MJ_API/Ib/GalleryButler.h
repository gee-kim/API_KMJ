#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialogue.h"

class AGalleryButler : public AActor
{
public:
	AGalleryButler();
	~AGalleryButler();

	// delete Function
	AGalleryButler(const AGalleryButler& _Other) = delete;
	AGalleryButler(AGalleryButler&& _Other) noexcept = delete;
	AGalleryButler& operator=(const AGalleryButler& _Other) = delete;
	AGalleryButler& operator=(AGalleryButler&& _Other) noexcept = delete;

	//void SetCollision();
	
	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

	void StateChange();

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	std::vector<UCollision*> Collisions;

	ADialogue* Dialogue = nullptr;

};

