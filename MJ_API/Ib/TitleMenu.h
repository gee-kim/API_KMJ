#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include <vector>
#include <EnginePlatform\EngineSound.h>

class UOpeningLevel;

class ATitleMenu : public AActor
{
public:
	ATitleMenu();
	~ATitleMenu();

	// delete Function
	ATitleMenu(const ATitleMenu& _Other) = delete;
	ATitleMenu(ATitleMenu&& _Other) noexcept = delete;
	ATitleMenu& operator=(const ATitleMenu& _Other) = delete;
	ATitleMenu& operator=(ATitleMenu&& _Other) noexcept = delete;

	void SelectChange(int _Index);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	int SelectIndex = 0;

	UEngineSoundPlayer BGMPlayer;
	UEngineSoundPlayer BGMSound;

};

