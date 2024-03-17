#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform\EngineSound.h>
#include "Helper.h"
#include "Dialogue.h"

class APlayer;

class AWallArt_Sneeze : public AActor
{
public:
	AWallArt_Sneeze();
	~AWallArt_Sneeze();

	// delete Function
	AWallArt_Sneeze(const AWallArt_Sneeze& _Other) = delete;
	AWallArt_Sneeze(AWallArt_Sneeze&& _Other) noexcept = delete;
	AWallArt_Sneeze& operator=(const AWallArt_Sneeze& _Other) = delete;
	AWallArt_Sneeze& operator=(AWallArt_Sneeze&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}

	void SetRenderOff();

	void StateChange(EPlayState _State);


protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

	void StateUpdate(float _DeltaTime);

	// 상태 함수
	void Idle(float _DeltaTime);
	void Event(float _DeltaTime);

	EPlayState State = EPlayState::Idle;

private:
	UImageRenderer* Renderer = nullptr;
	std::vector<UCollision*> Collisions;
	std::vector<UCollision*> Result;

	ADialogue* Dialogue = nullptr;

	APlayer* Player = nullptr;

	UEngineSoundPlayer BGMSound;

	bool IsPlayed = false;

};

