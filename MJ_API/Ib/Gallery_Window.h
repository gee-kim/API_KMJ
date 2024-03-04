#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

static 
class AGallery_Window : public AActor
{
public:
	AGallery_Window();
	~AGallery_Window();

	// delete Function
	AGallery_Window(const AGallery_Window& _Other) = delete;
	AGallery_Window(AGallery_Window&& _Other) noexcept = delete;
	AGallery_Window& operator=(const AGallery_Window& _Other) = delete;
	AGallery_Window& operator=(AGallery_Window&& _Other) noexcept = delete;

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

