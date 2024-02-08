#pragma once
#include <EngineCore\Actor.h>
#include "Helper.h"


class APlayer : public AActor
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// 상태 보조 함수
	void GravityCheck(float _DeltaTime);
	// 각 상태마다 언제나 가장 위에 실행되어야 한다.
	void DirCheck();

	std::string GetAnimationName(std::string _Name);

	// 상태 주요 업데이트
	void StateChange(EPlayState _State);
	void StateUpdate(float _DeltaTime);

	// 상태 함수들
	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Move(float _DeltaTime);

	// 상태 시작 함수들
	void IdleStart();
	void MoveStart();
	void JumpStart();

	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;
	

	float FreeMoveSpeed = 1000.0f;

	float MoveSpeed = 500.0f;
	float Gravity = 500.0f;
};

