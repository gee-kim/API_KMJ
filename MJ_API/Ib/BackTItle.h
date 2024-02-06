#pragma once
#include <EngineCore\Actor.h>

class ABackTItle : public AActor
{
public:
	ABackTItle();
	~ABackTItle();

	// delete Function
	ABackTItle(const ABackTItle& _Other) = delete;
	ABackTItle(ABackTItle&& _Other) noexcept = delete;
	ABackTItle& operator=(const ABackTItle& _Other) = delete;
	ABackTItle& operator=(ABackTItle&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;


};

