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
	Characters_Back,
	Characters,
	Player,
	Art_Front,
	Characters_Front,
	GrayScreen,
	BlueScreen,
	BlackScreen,
	Dialogue,
	Text,
	Fade,
};

enum class CollisionOrder
{
	Art,
	Characters,
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
	Event,
	Sink,

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

