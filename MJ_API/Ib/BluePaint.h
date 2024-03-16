#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"
#include "Helper.h"

class ABluePaint : public AActor
{
public:
	ABluePaint();
	~ABluePaint();

	// delete Function
	ABluePaint(const ABluePaint& _Other) = delete;
	ABluePaint(ABluePaint&& _Other) noexcept = delete;
	ABluePaint& operator=(const ABluePaint& _Other) = delete;
	ABluePaint& operator=(ABluePaint&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

	EPlayState State = EPlayState::None;

	void StateChange(EPlayState _State);


private:
	std::vector<UImageRenderer*> Renderers;
	UCollision* Collision = nullptr;
	std::vector<UCollision*> Result;

	class APlayer* Player = nullptr;
	ADialogue* Dialogue = nullptr;

	std::vector<std::string> Script;

	FVector ImageScale;
	int CurRenderIndex = 0;
	int CurTextIndex = 0;

	float DelayTime = 0.5f;
	float LetterInTime = 0.5f;

};

