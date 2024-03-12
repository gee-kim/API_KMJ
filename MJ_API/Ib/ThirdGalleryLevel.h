#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>

class ABackGroundMap;


class UThirdGalleryLevel : public ULevel
{
public:
	UThirdGalleryLevel();
	~UThirdGalleryLevel();

	// delete Function
	UThirdGalleryLevel(const UThirdGalleryLevel& _Other) = delete;
	UThirdGalleryLevel(UThirdGalleryLevel&& _Other) noexcept = delete;
	UThirdGalleryLevel& operator=(const UThirdGalleryLevel& _Other) = delete;
	UThirdGalleryLevel& operator=(UThirdGalleryLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;
private:
	ABackGroundMap* Map = nullptr;
	UEngineSoundPlayer BGMPlayer;
	UEngineSoundPlayer BGMSound;

	class APlayer* NewPlayer = nullptr;


};

