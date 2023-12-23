#pragma once

#include "Control.h"
#include "TextBox.h"
#include <iostream>
class LinTextBox : protected Control, public TextBox
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
		std::cout << "Linux value changed" << '\n';
	}
};