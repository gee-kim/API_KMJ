#pragma once
#include "Dialogue.h"
#include "Helper.h"
#include <EngineCore/Actor.h>
#include <EnginePlatform\EngineSound.h>


class AFootPrints : public AActor
{
public:
	AFootPrints();
	~AFootPrints();

	// delete Function
	AFootPrints(const AFootPrints& _Other) = delete;
	AFootPrints(AFootPrints&& _Other) noexcept = delete;
	AFootPrints& operator=(const AFootPrints& _Other) = delete;
	AFootPrints& operator=(AFootPrints&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	UCollision* Collision = nullptr;
	std::vector<UCollision*> Result;

	class APlayer* Player = nullptr;

	FVector ImageScale;
	FVector ScreenScale;

	float FadeTime = 0.0f;

	float DelayTime = -1.0f;

	ADialogue* Dialogue = nullptr;

	UEngineSoundPlayer BGMPlayer;

};

