#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWindowAnimation : public AActor
{
public:
	AWindowAnimation();
	~AWindowAnimation();

	// delete Function
	AWindowAnimation(const AWindowAnimation& _Other) = delete;
	AWindowAnimation(AWindowAnimation&& _Other) noexcept = delete;
	AWindowAnimation& operator=(const AWindowAnimation& _Other) = delete;
	AWindowAnimation& operator=(AWindowAnimation&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

	void StateChange(EPlayState _State);

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

	void StateUpdate(float _DeltaTime);

	// 상태 함수
	void Idle(float _DeltaTime);
	void Event(float _DeltaTime);

	EPlayState State = EPlayState::Event;

private:
	std::vector<UCollision*> Collisions;
	std::vector<UCollision*> Result;

	UImageRenderer* Renderer = nullptr;

	APlayer* Player = nullptr;

	std::vector<std::string> Script;

	ADialogue* Dialogue = nullptr;

	bool IsPlayed = false;
};

