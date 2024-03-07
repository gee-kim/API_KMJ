#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum class PlayRenderOrder
{
	Back,
	Map,
	Monster,
	Art_Back,
	Characters,
	Player,
	Art_Front,
	Dialogue,
	Text,
	Fade,
};

enum class CollisionOrder
{
	Art,
	Player,
};
enum class EActorDir
{
	Left,
	Right,
	Up,
	Down,
};

enum class EPlayState
{
	None,
	CameraFreeMove,
	FreeMove,
	Idle,
	Move,
	Talk,
};


class Helper
{
public:
	static class APlayer* MainPlayer;
	static UWindowImage* ColMapImage;
	static FVector GetMousePos();

	
protected:

private:
	Helper();
	~Helper();

};

