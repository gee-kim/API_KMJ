#include "OpeningLevel.h"
#include "EngineCore/EngineCore.h"
#include "Intro.h"

UOpeningLevel::UOpeningLevel()
{
}

UOpeningLevel::~UOpeningLevel()
{
}

void UOpeningLevel::BeginPlay()
{
	ULevel::BeginPlay();

	ADialogue* IntroDialogue = SpawnActor<ADialogue>();
	IntroDialogue->SetActorLocation({ 640, 300 });
	IntroDialogue->SetMovingBoxPosition({ 0,30 });

	AIntro* Intro = SpawnActor<AIntro>();
	Intro->SetActorLocation({ 0, 0 });
	Intro->SetDialogue(IntroDialogue);


	{
		//BGMPlayer = UEngineSound::SoundPlay("ib_title.ogg");
		//BGMPlayer.Loop();

	}
}

void UOpeningLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);


	//if (UEngineInput::IsDown(VK_SPACE) && true == )
	//{
	//	BGMPlayer.Off();
	//	GEngine->ChangeLevel("Gallery");
	//}

}

void UOpeningLevel::LevelStart(ULevel* _Level)
{
	int a = 0;
}
void UOpeningLevel::LevelEnd(ULevel* _Level)
{
	int a = 0;
}