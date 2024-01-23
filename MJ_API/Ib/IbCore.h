#pragma once
#include <EngineCore/EngineCore.h>

class IbCore : public EngineCore
{
public:
	IbCore();
	~IbCore();

	// delete Function
	IbCore(const IbCore& _Other) = delete;
	IbCore(IbCore&& _Other) noexcept = delete;
	IbCore& operator=(const IbCore& _Other) = delete;
	IbCore& operator=(IbCore&& _Other) noexcept = delete;

protected:
	void EngineStart() override;
	void EngineUpdate() override;
	void EngineEnd() override;

private:


};

