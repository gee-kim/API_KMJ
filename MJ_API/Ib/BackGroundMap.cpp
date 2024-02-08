#include "BackGroundMap.h"
#include "Helper.h"
#include <EngineCore/EngineResourcesManager.h>

ABackGroundMap::ABackGroundMap()
{
}

ABackGroundMap::~ABackGroundMap()
{
}


void ABackGroundMap::SetMapImage(std::string_view _MapImageName)
{
	Renderer->SetImage(_MapImageName);
	UWindowImage* Image = Renderer->GetImage();
	FVector ImageScale = Image->GetScale();
	Renderer->SetTransform({ ImageScale.Half2D(), ImageScale });
}

void ABackGroundMap::SetColMapImage(std::string_view _MapImageName)
{
	ColRenderer->SetImage(_MapImageName);
	UWindowImage* Image = ColRenderer->GetImage();
	Helper::ColMapImage = Image;
	FVector ImageScale = Image->GetScale();
	ColRenderer->SetTransform({ ImageScale.Half2D(), ImageScale });
}

void ABackGroundMap::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);



	if (UEngineInput::IsDown('O'))
	{
		SwitchDebug();
	}
}


void ABackGroundMap::SwitchDebug()
{
	if (true == Renderer->IsActive())
	{
		Renderer->SetActive(false);
		ColRenderer->SetActive(true);
	}
	else
	{
		Renderer->SetActive(true);
		ColRenderer->SetActive(false);
	}

}
void ABackGroundMap::BeginPlay()
{
	// 여기서 상수로 고정시키면.
	//Renderer = CreateImageRenderer(MarioRenderOrder::Map);
	//ColRenderer = CreateImageRenderer(MarioRenderOrder::Map);
	//ColRenderer->SetActive(false);
	// Renderer->SetImageCuttingTransform({ 0,0 }, { });
}

