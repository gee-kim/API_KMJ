#include "Helper.h"

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