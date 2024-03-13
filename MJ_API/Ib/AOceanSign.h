#pragma once
class AOceanSign
{
public:
	AOceanSign();
	~AOceanSign();

	// delete Function
	AOceanSign(const AOceanSign& _Other) = delete;
	AOceanSign(AOceanSign&& _Other) noexcept = delete;
	AOceanSign& operator=(const AOceanSign& _Other) = delete;
	AOceanSign& operator=(AOceanSign&& _Other) noexcept = delete;

protected:

private:


};

