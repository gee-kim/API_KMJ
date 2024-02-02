#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineInput.h>
#include "Bullet.h"
#include <EngineBase\EngineTime.h>
#include <vector>
#include <list>

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	AActor::BeginPlay();


	Renderer = CreateImageRenderer();
	Renderer->SetImage("Blue Dolls.png");
	Renderer->SetTransform({ {0,0}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {82,82}, {91, 91} });
	 //971*1102
	Renderer->CreateAnimation("Idle", "Blue Dolls.png", 0, 12, 0.5f, true);
	Renderer->CreateAnimation("Attack", "Blue Dolls.png", 26, 32, 0.5f, true);
	Renderer->ChangeAnimation("Idle");

}

void Player::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (EngineInput::IsDown('Q'))
	{
		Renderer->ChangeAnimation("Attack");
	}

	//if (true == EngineInput::IsPress('A'))
	//{
	//	AddActorLocation(FVector::Left * 500.0f * _DeltaTime);
	//}

	//if (true == EngineInput::IsPress('D'))
	//{
	//	AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
	//}

	//if (true == EngineInput::IsPress('W'))
	//{
	//	AddActorLocation(FVector::Up * 500.0f * _DeltaTime);
	//}


	//if (true == EngineInput::IsPress('S'))
	//{
	//	AddActorLocation(FVector::Down * 500.0f * _DeltaTime);
	//}

	
	// QSkillCool += 0.1f;
	// QSkillCool += 진짜 프레임과 프레임 사이에 소모된 현실 시간이어야 한다.;

	// 초당 2번 실행했다고 해도
	// 0.5 0.5 0.5 0.5 
	// 2차가 지나야 
	// 초당 2번 실행된다고 칩시다.
//	if (true == EngineInput::IsDown('Q'))
//	{
//		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
//		NewBullet->SetActorLocation(GetActorLocation());
//		NewBullet->SetDir(FVector::Right);
//	}
}