#pragma once
#include <EngineCore\Actor.h>
#include "Dialogue.h"
#include <EnginePlatform\EngineSound.h>

class AIntro : public AActor
{
public:
	AIntro();
	~AIntro();

	// delete Function
	AIntro(const AIntro& _Other) = delete;
	AIntro(AIntro&& _Other) noexcept = delete;
	AIntro& operator=(const AIntro& _Other) = delete;
	AIntro& operator=(AIntro&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BackGround = nullptr;
	UImageRenderer* FadeImage = nullptr;
	ADialogue* Dialogue = nullptr;

	std::vector<std::string> Script;
	int CurTextIndex = 0;

	FVector ImageScale;
	float Timer;
	float FadeTime = 3.0f;

	UEngineSoundPlayer BGMPlayer;
	
};

