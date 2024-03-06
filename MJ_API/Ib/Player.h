#pragma once
#include <EngineCore\Actor.h>
#include "Helper.h"


class APlayer : public AActor
{
private:
	static APlayer* MainPlayer;

public:
	static APlayer* GetMainPlayer();

	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void SetImageScale(FVector _ImageScale)
	{
		ImageScale = _ImageScale;
	}

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
	void Talk(float _DeltaTime);

	// ���� ���� �Լ���
	void IdleStart();
	void MoveStart();
	void TalkStart();

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
	
	float FreeMoveSpeed = 3000.0f;
	float MoveSpeed = 300.0f;
	FVector ImageScale= FVector::Zero;
};


