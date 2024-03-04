#pragma once
#include <EngineCore\Actor.h>
#include "Helper.h"

class ADialogueInfo
{
public:

};


class ADialogue : public AActor
{
public:
	ADialogue();
	~ADialogue();

	// delete Function
	ADialogue(const ADialogue& _Other) = delete;
	ADialogue(ADialogue&& _Other) noexcept = delete;
	ADialogue& operator=(const ADialogue& _Other) = delete;
	ADialogue& operator=(ADialogue&& _Other) noexcept = delete;

	void SetText(std::string _Text, float _Value = 20, Color8Bit _Color = Color8Bit::White);

	void CharTextBoxRendererOn();
	void ArtTextBoxRendererOn();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* CharfaceImageRenderer = nullptr;
	UImageRenderer* ArtTextBoxRenderer = nullptr;
	UImageRenderer* CharTextBoxRenderer = nullptr;
	UImageRenderer* TextRenderer = nullptr;
};

