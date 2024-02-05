#pragma once

#include "Control.h"
#include "Label.h"
#include <iostream>
class WindowsLabel : public Control, public Label
{
protected:
	std::string text;

public:
	void setText(std::string text) override
	{
		std::cout << "Windows Label Text Seted" << '\n';
		this->text = text;
	}

	const std::string getText() const override
	{
		std::cout << "Windows Label: ";
		return this->text;
	}
};