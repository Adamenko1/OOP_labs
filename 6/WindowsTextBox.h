#pragma once

#include "Control.h"
#include "TextBox.h"
#include <iostream>
class WindowsTextBox : protected Control, public TextBox
{
protected:
	std::string text;

public:
	void setText(std::string newText) override
	{
		std::cout << "Windows TextBox Text Seted" << '\n';
		this->text = newText;
	}

	const std::string getText() override
	{
		std::cout << "Windows TextBox: ";
		return this->text;
	}

	void onValueChanged() override
	{
		std::cout << "Windows value changed" << '\n';
	}
};