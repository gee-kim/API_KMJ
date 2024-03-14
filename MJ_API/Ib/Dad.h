#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialogue.h"
#include "CharFace.h"

class ADad : public AActor
{
public:
	ADad();
	~ADad();

	// delete Function
	ADad(const ADad& _Other) = delete;
	ADad(ADad&& _Other) noexcept = delete;
	ADad& operator=(const ADad& _Other) = delete;
	ADad& operator=(ADad&& _Other) noexcept = delete;


	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

	void SetCharFace(ACharFace* _CharFace)
	{
		CharFace = _CharFace;
	}


	void SetAnimation(std::string_view _AnimationName)
	{
		Renderer->ChangeAnimation(_AnimationName);
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
	UCollision* Collision = nullptr;
	std::vector<UCollision*> Result;

	UImageRenderer* Renderer = nullptr;

	APlayer* Player = nullptr;

	int CurTextIndex = 0;
	std::vector<std::string> Script;

	ADialogue* Dialogue = nullptr;
	ACharFace* CharFace = nullptr;

};

