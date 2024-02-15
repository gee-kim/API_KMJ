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

	// ���� ���� �Լ�
	void DirCheck();

	std::string GetAnimationName(std::string _Name);

	// ���� �ֿ� ������Ʈ
	void StateChange(EPlayState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);

	// ���� ���� �Լ���
	void IdleStart();
	void MoveStart();

	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";

private:
	UCollision* BodyCollision = nullptr;

	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;
	
	float FreeMoveSpeed = 1000.0f;
	float MoveSpeed = 500.0f;

	FVector MoveVector = FVector::Zero;
	FVector LastMoveVector = FVector::Zero;

	void MoveUpdate(float _DeltaTime);
};


