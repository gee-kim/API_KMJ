#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialogue.h"

class AMom : public AActor
{
public:
	AMom();
	~AMom();

	// delete Function
	AMom(const AMom& _Other) = delete;
	AMom(AMom&& _Other) noexcept = delete;
	AMom& operator=(const AMom& _Other) = delete;
	AMom& operator=(AMom&& _Other) noexcept = delete;


	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

	void SetAnimation(std::string_view _AnimationName)
	{
		Renderer->ChangeAnimation(_AnimationName);
	}


protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UCollision* Collision = nullptr;
	UImageRenderer* Renderer = nullptr;

	float MoveSpeed = 300.0f;

	int CurTextIndex = 0;
	std::vector<std::string> Script;

	ADialogue* Dialogue = nullptr;
};

