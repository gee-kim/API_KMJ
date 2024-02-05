#pragma once
#include <EngineCore/Actor.h>

class BackGroundMap : public AActor
{
public:
	BackGroundMap();
	~BackGroundMap();

	// delete Function
	BackGroundMap(const BackGroundMap& _Other) = delete;
	BackGroundMap(BackGroundMap&& _Other) noexcept = delete;
	BackGroundMap& operator=(const BackGroundMap& _Other) = delete;
	BackGroundMap& operator=(BackGroundMap&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName);
	void SetColMapImage(std::string_view _MapImageName);

	void SwitchDebug();

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UImageRenderer* Renderer = nullptr;
	UImageRenderer* ColRenderer = nullptr;

};

