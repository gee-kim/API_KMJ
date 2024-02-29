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

	void CreateText(std::string Text);
	void CreateDialogue(int _value);
	void EndDialogue();
	void CharTextBox();
	void ArtTextBox();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	//std::map<std::string, std::vector<ADialogueInfo*>>;
	UImageRenderer* CharfaceImageRenderer = nullptr;
	UImageRenderer* ArtTextBoxRenderer = nullptr;
	UImageRenderer* CharTextBoxRenderer = nullptr;
	UImageRenderer* TextRenderer = nullptr;
};

