#pragma once
#include <EngineCore\Actor.h>
#include <EnginePlatform\EngineSound.h>

class ANextLevel : public AActor
{
public:
	ANextLevel();
	~ANextLevel();

	// delete Function
	ANextLevel(const ANextLevel& _Other) = delete;
	ANextLevel(ANextLevel&& _Other) noexcept = delete;
	ANextLevel& operator=(const ANextLevel& _Other) = delete;
	ANextLevel& operator=(ANextLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float PlayTime = 2.0f;

private:
	UCollision* BodyCollision = nullptr;
	UEngineSoundPlayer BGMSound;
	UEngineSoundPlayer BGMPlayer;

};

