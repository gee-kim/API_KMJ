#pragma once
class DefaultTemplate
{
public:
	DefaultTemplate();
	~DefaultTemplate();

	// delete Function
	DefaultTemplate(const DefaultTemplate& _Other) = delete;
	DefaultTemplate(DefaultTemplate&& _Other) noexcept = delete;
	DefaultTemplate& operator=(const DefaultTemplate& _Other) = delete;
	DefaultTemplate& operator=(DefaultTemplate&& _Other) noexcept = delete;

protected:

private:


};

