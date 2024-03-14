#pragma once
#include <EngineCore/EngineCore.h>

class IbCore : public UEngineCore
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
	void WindowOpen(std::string& _OutWindowTitle, std::string& _SmallIconPath) override;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	

};

