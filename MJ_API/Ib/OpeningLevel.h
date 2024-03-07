#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>

class UOpeningLevel : public ULevel
{
public:
	UOpeningLevel();
	~UOpeningLevel();

	// delete Function
	UOpeningLevel(const UOpeningLevel& _Other) = delete;
	UOpeningLevel(UOpeningLevel&& _Other) noexcept = delete;
	UOpeningLevel& operator=(const UOpeningLevel& _Other) = delete;
	UOpeningLevel& operator=(UOpeningLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;

private:

	UEngineSoundPlayer BGMPlayer;
};

