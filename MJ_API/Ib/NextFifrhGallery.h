#pragma once
#include <EngineCore\Actor.h>

class ANextFifrhGallery :public AActor
{
public:
	ANextFifrhGallery();
	~ANextFifrhGallery();

	// delete Function
	ANextFifrhGallery(const ANextFifrhGallery& _Other) = delete;
	ANextFifrhGallery(ANextFifrhGallery&& _Other) noexcept = delete;
	ANextFifrhGallery& operator=(const ANextFifrhGallery& _Other) = delete;
	ANextFifrhGallery& operator=(ANextFifrhGallery&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* BodyCollision = nullptr;

};


