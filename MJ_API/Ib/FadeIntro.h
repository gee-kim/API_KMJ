#pragma once
#include <EngineCore\Actor.h>

class AFadeIntro : public AActor
{
public:
	AFadeIntro();
	~AFadeIntro();

	// delete Function
	AFadeIntro(const AFadeIntro& _Other) = delete;
	AFadeIntro(AFadeIntro&& _Other) noexcept = delete;
	AFadeIntro& operator=(const AFadeIntro& _Other) = delete;
	AFadeIntro& operator=(AFadeIntro&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* FadeImage = nullptr;
	FVector ImageScale;
	float Timer;
	float FadeTime = 3.0f;
};

