#pragma once
#include <EngineCore\Actor.h>
#include "Helper.h"
#include "Helper.h"

class ADialogInfo
{
public:

};


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
	void CharTextBox();
	void ArtTextBox();
	void CreateText();
	//std::map<std::string, std::vector<ADialogInfo*>>;
	UImageRenderer* CharfaceImageRenderer = nullptr;
	UImageRenderer* ArtTextBoxRenderer = nullptr;
	UImageRenderer* CharTextBoxRenderer = nullptr;
	UImageRenderer* TextRenderer = nullptr;
};

