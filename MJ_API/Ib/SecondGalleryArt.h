#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"
#include <EnginePlatform/EngineSound.h>

enum class ESecondEventState
{
	// 암전 깜빡이는 상태
	StartEvent,
	// 플레이어 조작 상태
	PlayerControll,

};

enum class ESecondStartEventState
{
	BlackOut,
	End,
};

class APlayer;

class ASecondGalleryArt :public AActor
{
public:
	ASecondGalleryArt();
	~ASecondGalleryArt();

	// delete Function
	ASecondGalleryArt(const ASecondGalleryArt& _Other) = delete;
	ASecondGalleryArt(ASecondGalleryArt&& _Other) noexcept = delete;
	ASecondGalleryArt& operator=(const ASecondGalleryArt& _Other) = delete;
	ASecondGalleryArt& operator=(ASecondGalleryArt&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

	void StateChange(ESecondEventState _State);
	void StateUpdate(float _DeltaTime);
	void StartEvent(float _DeltaTime);


private:
	ESecondEventState CurState = ESecondEventState::PlayerControll;
	UImageRenderer* BlackRenderer= nullptr;
	FVector ImageScale;
	int Count = 3;

	APlayer* Player = nullptr;

	UCollision* Collisions = nullptr;

	ADialogue* Dialogue = nullptr;

	float Time = 0.0f;

	UEngineSoundPlayer BGMPlayer;
	UEngineSoundPlayer BGMSound;
	bool IsPlayed = false;
};

