#pragma once
#include <EngineCore/Actor.h>
#include "Helper.h"
#include "Player.h"
#include "Dialogue.h"

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

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;

private:
	std::vector<UImageRenderer*> Renderers;
	std::vector<UCollision*> Collisions;

	ADialogue* Dialogue = nullptr;

};

