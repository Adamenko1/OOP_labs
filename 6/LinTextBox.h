#pragma once

#include "Control.h"
#include "TextBox.h"
#include <iostream>
class LinTextBox : protected Control, public TextBox
{
protected:
	std::string text;

public:
	void setText(std::string newText) override
	{
		std::cout << "Linux TextBox Text Seted" << '\n';
		this->text = newText;
	}

	const std::string getText() override
	{
		std::cout << "Linux TextBox: ";
		return this->text;
	}

	void onValueChanged() override
	{
		std::cout << "Linux value changed" << '\n';
	}
};