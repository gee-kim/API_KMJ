#pragma once
#include <EngineCore\Actor.h>

class ABackTitle : public AActor
{
public:
	ABackTitle();
	~ABackTitle();

	// delete Function
	ABackTitle(const ABackTitle& _Other) = delete;
	ABackTitle(ABackTitle&& _Other) noexcept = delete;
	ABackTitle& operator=(const ABackTitle& _Other) = delete;
	ABackTitle& operator=(ABackTitle&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer1 = nullptr;
	UImageRenderer* Renderer2 = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;


};

