#pragma once
#include <EngineCore\Actor.h>
#include <EnginePlatform\EngineSound.h>

class ANextThirdLevel : public AActor
{
public:
	ANextThirdLevel();
	~ANextThirdLevel();

	// delete Function
	ANextThirdLevel(const ANextThirdLevel& _Other) = delete;
	ANextThirdLevel(ANextThirdLevel&& _Other) noexcept = delete;
	ANextThirdLevel& operator=(const ANextThirdLevel& _Other) = delete;
	ANextThirdLevel& operator=(ANextThirdLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* BodyCollision = nullptr;

	UEngineSoundPlayer BGMSound;
};

