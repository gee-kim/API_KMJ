#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineInput.h>
#include "Bullet.h"
#include <EngineBase\EngineTime.h>
#include <vector>
#include <list>
#include "Helper.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	AActor::BeginPlay();


	//Renderer = CreateImageRenderer();
	//Renderer->SetImage("ib_00.png.png");
	//Renderer->SetTransform({ {0,0}, {100, 100} });
	//Renderer->SetImageCuttingTransform({ {82,82}, {91, 91} });
	// //971*1102
	//Renderer->CreateAnimation("Idle", "ib_00.png", 0, 2, 0.5f, true);
	//Renderer->CreateAnimation("Attack", "ib_00.png", 3, 5, 0.5f, true);
	//Renderer->ChangeAnimation("Idle");

}

void Player::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	EngineDebug::OutPutDebugText(Helper::GetMousePos().ToString());

	AlphaTime += _DeltaTime;
	if (1.0f <= AlphaTime)
	{
		Dir = !Dir;
		AlphaTime = 0.0f;
	}

	if (true == Dir)
	{
		Renderer->SetAlpha(AlphaTime);
	}
	else
	{
		Renderer->SetAlpha(1.0f - AlphaTime);
	}


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
	// QSkillCool += ��¥ �����Ӱ� ������ ���̿� �Ҹ�� ���� �ð��̾�� �Ѵ�.;

	// �ʴ� 2�� �����ߴٰ� �ص�
	// 0.5 0.5 0.5 0.5 
	// 2���� ������ 
	// �ʴ� 2�� ����ȴٰ� Ĩ�ô�.
//	if (true == EngineInput::IsDown('Q'))
//	{
//		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
//		NewBullet->SetActorLocation(GetActorLocation());
//		NewBullet->SetDir(FVector::Right);
//	}
}