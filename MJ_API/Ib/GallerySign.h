#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"

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

	void TextChange(ADialogue* _Dialogue);

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	std::vector<UCollision*> Collisions;

	ADialogue* Dialogue = nullptr;

};

