#include "Helper.h"

UWindowImage* Helper::ColMapImage = nullptr;


Helper::Helper()
{
}

Helper::~Helper()
{
}

FVector Helper::GetMousePos()
{
	return GEngine->MainWindow.GetMousePosition();
}