#pragma once
#include <EngineCore\Actor.h>
#include "Helper.h"

class ADialog : public AActor
{
public:
	ADialog();
	~ADialog();

	// delete Function
	ADialog(const ADialog& _Other) = delete;
	ADialog(ADialog&& _Other) noexcept = delete;
	ADialog& operator=(const ADialog& _Other) = delete;
	ADialog& operator=(ADialog&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* TextBoxRenderer = nullptr;
	UImageRenderer* TextRenderer = nullptr;
};

