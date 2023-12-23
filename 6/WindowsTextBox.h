#pragma once

#include "Control.h"
#include "TextBox.h"
#include <iostream>
class WindowsTextBox : protected Control, public TextBox
{
protected:
	std::string text;

public:
	void setText(std::string& newText) override
	{
		text = newText;
	}

	const std::string& getText() const override
	{
		return text;
	}

	void onValueChanged() override
	{
		std::cout << "Windows value changed" << '\n';
	}
};