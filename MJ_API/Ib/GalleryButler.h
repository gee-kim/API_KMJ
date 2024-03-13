#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

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
	std::vector<UCollision*> Result;
	APlayer* Player = nullptr;

	int CurTextIndex = 0;
	std::vector<std::string> Texts;

	ADialogue* Dialogue = nullptr;

};

