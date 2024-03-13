#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

class APlayer;

class AGallerySign : public AActor
{
public:
	AGallerySign();
	~AGallerySign();

	// delete Function
	AGallerySign(const AGallerySign& _Other) = delete;
	AGallerySign(AGallerySign&& _Other) noexcept = delete;
	AGallerySign& operator=(const AGallerySign& _Other) = delete;
	AGallerySign& operator=(AGallerySign&& _Other) noexcept = delete;

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

