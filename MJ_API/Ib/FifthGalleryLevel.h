#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>

class ABackGroundMap;


class UFifthGalleryLevel : public ULevel
{
public:
	UFifthGalleryLevel();
	~UFifthGalleryLevel();

	// delete Function
	UFifthGalleryLevel(const UFifthGalleryLevel& _Other) = delete;
	UFifthGalleryLevel(UFifthGalleryLevel&& _Other) noexcept = delete;
	UFifthGalleryLevel& operator=(const UFifthGalleryLevel& _Other) = delete;
	UFifthGalleryLevel& operator=(UFifthGalleryLevel&& _Other) noexcept = delete;

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

