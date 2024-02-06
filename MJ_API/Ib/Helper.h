#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum PlayRenderOrder
{
	Map,
	Monster,
	Player,
};

enum class EActorDir
{
	Left,
	Right,
};

enum class EPlayState
{
	None,
	CameraFreeMove,
	FreeMove,
	Idle,
	Move,
};


class Helper
{
public:
	static UWindowImage* ColMapImage;
	static FVector GetMousePos();

	
protected:

private:
	Helper();
	~Helper();

};

