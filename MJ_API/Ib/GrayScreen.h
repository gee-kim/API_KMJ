#pragma once
#include <EngineCore\Actor.h>

class AGrayScreen : public AActor
{
public:
	AGrayScreen();
	~AGrayScreen();

	// delete Function
	AGrayScreen(const AGrayScreen& _Other) = delete;
	AGrayScreen(AGrayScreen&& _Other) noexcept = delete;
	AGrayScreen& operator=(const AGrayScreen& _Other) = delete;
	AGrayScreen& operator=(AGrayScreen&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer = nullptr;
	FVector ScreenScale;
};

