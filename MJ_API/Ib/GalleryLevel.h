#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>

enum class EEventState
{
	// ������ �ɾ���� �ϴ� ����
	StartEvent,
	// �÷��̾ �����Ҽ� �ִ� ����
	PlayerControll,
};

enum class EStartEventState
{
	// ������ �ɾ���� �ϴ� ����
	Walk,
	// �÷��̾ �����Ҽ� �ִ� ����
	End,
};


class ABackGroundMap;

// ���� :
class UGalleryLevel : public ULevel
{
public:
	// constrcuter destructer
	UGalleryLevel();
	~UGalleryLevel();

	// delete Function
	UGalleryLevel(const UGalleryLevel& _Other) = delete;
	UGalleryLevel(UGalleryLevel&& _Other) noexcept = delete;
	UGalleryLevel& operator=(const UGalleryLevel& _Other) = delete;
	UGalleryLevel& operator=(UGalleryLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;


	EStartEventState StartEventState = EStartEventState::Walk;
	float WalkTime = 2.0f;

	void StateChange(EEventState _State);
	void StateUpdate(float _DeltaTime);
	void StartEvent(float _DeltaTime);

private:
	EEventState CurState = EEventState::StartEvent;

	ABackGroundMap* Map = nullptr;
	UEngineSoundPlayer BGMPlayer;

	class APlayer* NewPlayer = nullptr;
	class AMom* IbMom = nullptr;
	class ADad* IbDad = nullptr;

};

