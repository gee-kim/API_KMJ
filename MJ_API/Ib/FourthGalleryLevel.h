#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>
#include "Helper.h"
#include "BackGroundMap.h"

class UFourthGalleryLevel : public ULevel
{
public:
	UFourthGalleryLevel();
	~UFourthGalleryLevel();

	// delete Function
	UFourthGalleryLevel(const UFourthGalleryLevel& _Other) = delete;
	UFourthGalleryLevel(UFourthGalleryLevel&& _Other) noexcept = delete;
	UFourthGalleryLevel& operator=(const UFourthGalleryLevel& _Other) = delete;
	UFourthGalleryLevel& operator=(UFourthGalleryLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	class APlayer* NewPlayer = nullptr;
	ABackGroundMap* Map = nullptr;


};

