#pragma once
class UTestLevel
{
public:
	UTestLevel();
	~UTestLevel();

	// delete Function
	UTestLevel(const UTestLevel& _Other) = delete;
	UTestLevel(UTestLevel&& _Other) noexcept = delete;
	UTestLevel& operator=(const UTestLevel& _Other) = delete;
	UTestLevel& operator=(UTestLevel&& _Other) noexcept = delete;

protected:

private:


};

