#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform/EngineSound.h>

enum class EEventState
{
	// 앞으로 걸어나가야 하는 상태
	StartEvent,
	// 플레이어가 조작할수 있는 상태
	PlayerControll,
};

enum class EStartEventState
{
	// 앞으로 걸어나가야 하는 상태
	Walk,
	// 대화창에 대사가 나오는 상태
	MomTalk,
	DadTalk,
	//프론트데스크로 걸어나가는 상태
	WalktoFront,
	WalktoDesk,
	IbTalk,
	// 플레이어가 조작할수 있는 상태
	End,
};


class ABackGroundMap;
class ADialogue;
class ACharFace;

// 설명 :
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
	float FrontWalkTime = 1.5f;
	float UpWalkTime = 1.0f;
	
	float DelayTime = 0.5f;


	void StateChange(EEventState _State);
	void StateUpdate(float _DeltaTime);
	void StartEvent(float _DeltaTime);

private:
	EEventState CurState = EEventState::StartEvent;

	ABackGroundMap* Map = nullptr;

	UEngineSoundPlayer BGMSound;

	ADialogue* NewDialogue = nullptr;
	ACharFace* CharFace = nullptr;

	int CurTextIndex = 0;
	std::vector<std::string> Script;

	class APlayer* NewPlayer = nullptr;
	class AMom* IbMom = nullptr;
	class ADad* IbDad = nullptr;

	bool MomSoundPlayed = false;
	bool DadSoundPlayed = false;
	bool IbSoundPlayed = false;

};

