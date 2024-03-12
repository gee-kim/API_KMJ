#pragma once
class APrevLevel
{
public:
	APrevLevel();
	~APrevLevel();

	// delete Function
	APrevLevel(const APrevLevel& _Other) = delete;
	APrevLevel(APrevLevel&& _Other) noexcept = delete;
	APrevLevel& operator=(const APrevLevel& _Other) = delete;
	APrevLevel& operator=(APrevLevel&& _Other) noexcept = delete;

protected:

private:


};

