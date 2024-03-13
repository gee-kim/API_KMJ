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

	void SetText(std::string _Text, float _Value = 22, Color8Bit _Color = Color8Bit::White);

	void CharTextBoxRendererOn();
	void ArtTextBoxRendererOn();
	void AllTextBoxRendererOff();
	void SetMovingBoxPosition(FVector _Value);
	void SetMomFace(std::string_view _Name);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::vector<UImageRenderer*> Renderers;

	UImageRenderer* MomSmileFace = nullptr;
	UImageRenderer* MomUpsetFace = nullptr;
	UImageRenderer* MomBigSmileFace = nullptr;
	UImageRenderer* MomAngryFace = nullptr;
	UImageRenderer* DadSmileFace = nullptr;

	std::vector<std::string> FaceName;

};

