#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialog.h"

class AArt : public AActor
{
public:
	AArt();
	~AArt();

	// delete Function
	AArt(const AArt& _Other) = delete;
	AArt(AArt&& _Other) noexcept = delete;
	AArt& operator=(const AArt& _Other) = delete;
	AArt& operator=(AArt&& _Other) noexcept = delete;

	void SetDialog(ADialog* _Dialog)
	{
		Dialog = _Dialog;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UCollision* BodyCollision0 = nullptr;
	UCollision* BodyCollision1 = nullptr;
	UCollision* BodyCollision2 = nullptr;
	UCollision* BodyCollision3 = nullptr;

	ADialog* Dialog = nullptr;

};
