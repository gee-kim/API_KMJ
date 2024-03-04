#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Helper.h"

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

APlayer* APlayer::MainPlayer = nullptr;

APlayer* APlayer::GetMainPlayer()
{
	return MainPlayer;
}


void APlayer::BeginPlay()
{
	AActor::BeginPlay();
	
	{
		Renderer = CreateImageRenderer(PlayRenderOrder::Player);
		Renderer->SetImage("ib_00.png");
		Renderer->SetTransform({ {0,-48}, {48, 96} });
		//Renderer->SetImageCuttingTransform({ {82,82}, {91, 91} });
		//971*1102

		Renderer->CreateAnimation("Idle", "ib_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Right", "ib_00.png", 7, 7, 0.1f, true);
		Renderer->CreateAnimation("Idle_Left", "ib_00.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Idle_Down", "ib_00.png", 1, 1, 0.5f, true);
		Renderer->CreateAnimation("Idle_Up", "ib_00.png", 10, 10, 0.5f, true);

		Renderer->CreateAnimation("Move_Down", "ib_00.png", 0, 2, 0.3f, true);
		Renderer->CreateAnimation("Move_Left", "ib_00.png", 3, 5, 0.5f, true);
		Renderer->CreateAnimation("Move_Right", "ib_00.png", 6, 8, 0.2f, true);
		Renderer->CreateAnimation("Move_Up", "ib_00.png", 9, 11, 0.5f, true);
		Renderer->ChangeAnimation("Idle");
	}
	
	{
		BodyCollision = CreateCollision(CollisionOrder::Player);
		BodyCollision->SetPosition({ 0,-48 });
		BodyCollision->SetScale({ 50,100 });
		BodyCollision->SetColType(ECollisionType::CirCle);
	}
		
	StateChange(EPlayState::Idle);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);
}



void APlayer::DirCheck()
{
	EActorDir Dir = DirState;
	if (UEngineInput::IsPress(VK_LEFT))
	{
		Dir = EActorDir::Left;
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		Dir = EActorDir::Right;
	}
	if (UEngineInput::IsPress(VK_UP))
	{
		Dir = EActorDir::Up;
	}
	if (UEngineInput::IsPress(VK_DOWN))
	{
		Dir = EActorDir::Down;
	}
	if (Dir != DirState)
	{
		DirState = Dir;
		std::string Name = GetAnimationName(CurAnimationName);
		// Renderer->ChangeAnimation(Name, true);
		Renderer->ChangeAnimation(Name, true, Renderer->GetCurAnimationFrame(), Renderer->GetCurAnimationTime());
	}
}


void APlayer::CameraFreeMove(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		GetWorld()->AddCameraPos(FVector::Left * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Left * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		//                             2        *  시간      * 500
		GetWorld()->AddCameraPos(FVector::Right * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		GetWorld()->AddCameraPos(FVector::Up * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Up * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		GetWorld()->AddCameraPos(FVector::Down * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Down * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsDown('2'))
	{
		StateChange(EPlayState::Idle);
	}
}

void APlayer::FreeMove(float _DeltaTime)
{
	FVector FreeMove = FVector::Zero;

	if (UEngineInput::IsPress(VK_LEFT))
	{
		FreeMove += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		FreeMove += FVector::Right * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		FreeMove += FVector::Up * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		FreeMove += FVector::Down * _DeltaTime * FreeMoveSpeed;
	}

	AddActorLocation(FreeMove * _DeltaTime);
	GetWorld()->AddCameraPos(FreeMove * _DeltaTime);

	if (UEngineInput::IsDown('1'))
	{
		StateChange(EPlayState::Idle);
	}
}



std::string APlayer::GetAnimationName(std::string _Name)
{
	std::string DirName = "";

	switch (DirState)
	{
	case EActorDir::Left:
		DirName = "_Left";
		break;
	case EActorDir::Right:
		DirName = "_Right";
		break;
	case EActorDir::Up:
		DirName = "_Up";
		break;
	case EActorDir::Down:
		DirName = "_Down";
		break;
	default:
		break;
	}

	CurAnimationName = _Name;

	return _Name + DirName;

}

void APlayer::IdleStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Idle"));
	DirCheck();
}

void APlayer::MoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Move"));
	DirCheck();
}

void APlayer::StateChange(EPlayState _State)
{
	// 이전상태와 지금 상태가 같지 않아
	// 이전에는 move 지금은 Idle
	if (State != _State)
	{
		switch (_State)
		{
		case EPlayState::Idle:
			IdleStart();
			break;
		case EPlayState::Move:
			MoveStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void APlayer::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::CameraFreeMove:
		CameraFreeMove(_DeltaTime);
		break;
	case EPlayState::FreeMove:
		FreeMove(_DeltaTime);
		break;
	case EPlayState::Idle:
		Idle(_DeltaTime);
		break;
	case EPlayState::Move:
		Move(_DeltaTime);
		break;
	default:
		break;
	}


}


void APlayer::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsDown('1'))
	{
		StateChange(EPlayState::FreeMove);
		return;
	}

	if (true == UEngineInput::IsDown('2'))
	{
		StateChange(EPlayState::CameraFreeMove);
		return;
	}


	if (
		true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT) ||
		true == UEngineInput::IsPress(VK_UP) ||
		true == UEngineInput::IsPress(VK_DOWN)
		)
	{
		StateChange(EPlayState::Move);
		return;
	}

}


void APlayer::Move(float _DeltaTime)
{
	DirCheck();


	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT) && UEngineInput::IsFree(VK_UP) && UEngineInput::IsFree(VK_DOWN))
	{
		StateChange(EPlayState::Idle);
		return;
	}

	//왼쪽으로 이동하다가 픽셀충돌하면 한칸 반대방향으로 보내주기
	if (UEngineInput::IsPress(VK_LEFT))
	{

		FVector NextPos = GetActorLocation() + (FVector::Left * _DeltaTime * MoveSpeed);

		Color8Bit Color = Helper::ColMapImage->GetColor(NextPos.iX(), NextPos.iY(), Color8Bit::MagentaA);
		if (Color != Color8Bit(255, 0, 255, 0))
		{
			AddActorLocation(FVector::Left * _DeltaTime * MoveSpeed);
		}

	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		FVector NextPos = GetActorLocation() + (FVector::Right * _DeltaTime * MoveSpeed);

		Color8Bit Color = Helper::ColMapImage->GetColor(NextPos.iX(), NextPos.iY(), Color8Bit::MagentaA);
		if (Color != Color8Bit(255, 0, 255, 0))
		{
			AddActorLocation(FVector::Right * _DeltaTime * MoveSpeed);
		}

	}

	if (true == UEngineInput::IsPress(VK_UP))
	{
		FVector NextPos = GetActorLocation() + (FVector::Up * _DeltaTime * MoveSpeed);

		Color8Bit Color = Helper::ColMapImage->GetColor(NextPos.iX(), NextPos.iY(), Color8Bit::MagentaA);
		if (Color != Color8Bit(255, 0, 255, 0))
		{
			AddActorLocation(FVector::Up * _DeltaTime * MoveSpeed);
		}

	}

	if (true == UEngineInput::IsPress(VK_DOWN))
	{
		FVector NextPos = GetActorLocation() + (FVector::Down * _DeltaTime * MoveSpeed);

		Color8Bit Color = Helper::ColMapImage->GetColor(NextPos.iX(), NextPos.iY(), Color8Bit::MagentaA);
		if (Color != Color8Bit(255, 0, 255, 0))
		{
			AddActorLocation(FVector::Down * _DeltaTime * MoveSpeed);
		}
	}

	if (nullptr == Helper::ColMapImage)
	{
		MsgBoxAssert("맵 이미지가 존재하지 않으므로 충돌이 불가능합니다.");
	}




	//카메라의 위치는 
	//플레이어의 위치에서 윈도우 크기의 Half만큼 x,y 값으로 이동한 위치
	// 플레이어의 위치
	// 윈도우 크기


	FVector PlayerLocation = GetTransform().GetPosition();

	UEngineWindow& Window = GEngine->MainWindow;

	FVector ScreenSize = Window.GetWindowScale();

	FVector CameraPos;
	CameraPos.X = PlayerLocation.X - ScreenSize.hX();
	CameraPos.Y = PlayerLocation.Y - ScreenSize.hY();


	// 카메라 위치 맵에서 나가지 않게 지정해주기

	if (0.0 >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	if (0.0 >= CameraPos.Y)
	{
		CameraPos.Y = 0.0f;
	}


	// 맵이미지 크기 끝점(RightBottom)까지 갔을 때 카메라의 위치는
	// 이미지크기 - 윈도우 화면 만큼이다.
	if (CameraPos.X >= ImageScale.X - GEngine->MainWindow.GetWindowScale().X)
	{
		CameraPos.X = ImageScale.X - GEngine->MainWindow.GetWindowScale().X;
	}
	if (CameraPos.Y >= ImageScale.Y - GEngine->MainWindow.GetWindowScale().Y)
	{
		CameraPos.Y = ImageScale.Y - GEngine->MainWindow.GetWindowScale().Y;
	}

	GetWorld()->SetCameraPos(CameraPos);

};

















