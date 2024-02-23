#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"

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

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	UCollision* BodyCollision;

};

