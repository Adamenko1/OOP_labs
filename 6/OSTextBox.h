#pragma once

#include "Control.h"
#include "TextBox.h"
#include <iostream>
class OSTextBox : protected Control, public TextBox
{
protected:
	std::string text;

public:
	void setText(std::string newText) override
	{
		std::cout << "MacOS TextBox Text Seted" << '\n';
		this->text = newText;
	}

	const std::string getText() override
	{
		std::cout << "MacOS TextBox: ";
		return this->text;
	}

	void onValueChanged() override
	{
		std::cout << "MacOS value changed" << '\n';
	}
};