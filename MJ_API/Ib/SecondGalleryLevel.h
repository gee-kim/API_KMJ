#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>
#include "Helper.h"
#include "BackGroundMap.h"


class USecondGalleryLevel : public ULevel
{
public:
	USecondGalleryLevel();
	~USecondGalleryLevel();

	// delete Function
	USecondGalleryLevel(const USecondGalleryLevel& _Other) = delete;
	USecondGalleryLevel(USecondGalleryLevel&& _Other) noexcept = delete;
	USecondGalleryLevel& operator=(const USecondGalleryLevel& _Other) = delete;
	USecondGalleryLevel& operator=(USecondGalleryLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;

private:
	class APlayer* NewPlayer = nullptr;
	ABackGroundMap* Map = nullptr;

};

