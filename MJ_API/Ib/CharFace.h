#pragma once
#include <EngineCore\Actor.h>
#include "Helper.h"

class ACharFace : public AActor
{
public:
	ACharFace();
	~ACharFace();

	// delete Function
	ACharFace(const ACharFace& _Other) = delete;
	ACharFace(ACharFace&& _Other) noexcept = delete;
	ACharFace& operator=(const ACharFace& _Other) = delete;
	ACharFace& operator=(ACharFace&& _Other) noexcept = delete;

	void SetMomSmileFace();
	void SetMomUpsetFace();
	void SetMomBigSmileFace();
	void SetMomAngryFace();
	void SetDadSmileFace();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MomSmileFace = nullptr;
	UImageRenderer* MomUpsetFace = nullptr;
	UImageRenderer* MomBigSmileFace = nullptr;
	UImageRenderer* MomAngryFace = nullptr;
	UImageRenderer* DadSmileFace = nullptr;

};

