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


	//Renderer = CreateImageRenderer();
	//Renderer->SetImage("Player_Right.png");
	//Renderer->SetTransform({ {0,0}, {100, 100} });
	//Renderer->SetImageCuttingTransform({ {64,64}, {32, 32} });
	//Renderer->CreateAnimation("Idle", "Player_Right.png", 0, 17, 0.5f, true);
	//Renderer->CreateAnimation("Attack", "Player_Right.png", 26, 32, 0.5f, true);
	//Renderer->ChangeAnimation("Idle");

}

void Player::Tick(float _DeltaTime)
{
	// 1�ʿ� 2���� �����ߴٸ�
	// Tick�� Tick���� �ð���? 
	// 0.5�� �ϲ���.

	// 1�ʿ� 100�� �����ϴ� �ְ� �ִٰ� Ĩ�ô�.
	// 0.5�ʿ� ���ȼ��� �������� �ϳ���?
	// 100 * 0.5
	AActor::Tick(_DeltaTime);

	//if (EngineInput::IsDown('Q'))
	//{
	//	Renderer->ChangeAnimation("Attack");
	//}

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
	if (true == EngineInput::IsDown('Q'))
	{
		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
		NewBullet->SetActorLocation(GetActorLocation());
		NewBullet->SetDir(FVector::Right);
	}
}