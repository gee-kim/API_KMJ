#pragma once
#include <EngineCore\Actor.h>

class ANextFourthGallery : public AActor
{
public:
	ANextFourthGallery();
	~ANextFourthGallery();

	// delete Function
	ANextFourthGallery(const ANextFourthGallery& _Other) = delete;
	ANextFourthGallery(ANextFourthGallery&& _Other) noexcept = delete;
	ANextFourthGallery& operator=(const ANextFourthGallery& _Other) = delete;
	ANextFourthGallery& operator=(ANextFourthGallery&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* BodyCollision = nullptr;

};

