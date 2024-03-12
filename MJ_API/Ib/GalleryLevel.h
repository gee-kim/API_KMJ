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
	// ��ȭâ�� ��簡 ������ ����
	MomTalk,
	DadTalk,
	//����Ʈ����ũ�� �ɾ���� ����
	WalktoFront,
	WalktoDesk,
	IbTalk,
	// �÷��̾ �����Ҽ� �ִ� ����
	End,
};


class ABackGroundMap;
class ADialogue;

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


	EStartEventState CurEventState = EStartEventState::Walk;
	float WalkTime = 4.0f;
	float FrontWalkTime = 2.0f;
	float UpWalkTime = 2.0f;
	float PlayTime = 2.0f;

	void StateChange(EEventState _State);
	void StateUpdate(float _DeltaTime);
	void StartEvent(float _DeltaTime);

private:
	EEventState CurState = EEventState::StartEvent;

	ABackGroundMap* Map = nullptr;
	UEngineSoundPlayer BGMPlayer;
	UEngineSoundPlayer BGMSound;

	ADialogue* NewDialogue = nullptr;
	
	int CurTextIndex = 0;
	std::vector<std::string> Script;

	class APlayer* NewPlayer = nullptr;
	class AMom* IbMom = nullptr;
	class ADad* IbDad = nullptr;

};

