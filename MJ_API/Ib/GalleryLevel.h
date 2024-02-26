#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>

class ABackGroundMap;

// Ό³Έν :
class UGalleryLevel : public ULevel
{
public:
	// constrcuter destructer
	UGalleryLevel();
	~UGalleryLevel();

	// delete Function
	UGalleryLevel(const UGalleryLevel& _Other) = delete;
	UGalleryLevel(UGalleryLevel&& _Other) noexcept = delete;
	UGalleryLevel& operator=(const UGalleryLevel& _Other) = delete;
	UGalleryLevel& operator=(UGalleryLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;

private:
	ABackGroundMap* Map;
	UEngineSoundPlayer BGMPlayer;
};

