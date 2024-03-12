#include "GrayScreen.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"

AGrayScreen::AGrayScreen()
{
}

AGrayScreen::~AGrayScreen()
{
}

void AGrayScreen::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(PlayRenderOrder::GrayScreen);
	Renderer->SetImage("GrayScreen.png");
	
	Renderer->AutoImageScale();
	ScreenScale = GEngine->MainWindow.GetWindowScale();
	Renderer->SetTransform({ {ScreenScale.Half2D()} , ScreenScale});
}

void AGrayScreen::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);



}