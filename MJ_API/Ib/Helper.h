#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>

enum PlayRenderOrder
{
	Map,
	Player,
};

class Helper
{
public:
	static FVector GetMousePos();

	
protected:

private:
	Helper();
	~Helper();

};

