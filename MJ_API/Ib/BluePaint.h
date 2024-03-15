#pragma once
#include <EngineCore/Actor.h>
#include "Dialogue.h"


class ABluePaint : public AActor
{
public:
	ABluePaint();
	~ABluePaint();

	// delete Function
	ABluePaint(const ABluePaint& _Other) = delete;
	ABluePaint(ABluePaint&& _Other) noexcept = delete;
	ABluePaint& operator=(const ABluePaint& _Other) = delete;
	ABluePaint& operator=(ABluePaint&& _Other) noexcept = delete;

	void SetDialogue(ADialogue* _Dialogue)
	{
		Dialogue = _Dialogue;
	}
	void StateChange(EPlayState _State);

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	UCollision* Collision = nullptr;

	FVector ImageScale;
	int Count = 3;

	class APlayer* Player = nullptr;
	ADialogue* Dialogue = nullptr;

	std::vector<std::string> Script;


};

