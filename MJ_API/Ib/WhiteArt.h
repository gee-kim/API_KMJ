#pragma once
class AWhiteArt
{
public:
	AWhiteArt();
	~AWhiteArt();

	// delete Function
	AWhiteArt(const AWhiteArt& _Other) = delete;
	AWhiteArt(AWhiteArt&& _Other) noexcept = delete;
	AWhiteArt& operator=(const AWhiteArt& _Other) = delete;
	AWhiteArt& operator=(AWhiteArt&& _Other) noexcept = delete;

protected:

private:


};

