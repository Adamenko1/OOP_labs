#pragma once

#include "Control.h"
#include "Label.h"
#include <iostream>
class OSLabel : public Control, public Label
{
protected:
	std::string text;

public:
	void setText(std::string text) override
	{
		std::cout << "MacOS Label Text Seted" << '\n';
		this->text = text;
	}

	const std::string getText() const override
	{
		std::cout << "MacOS Label: ";
		return this->text;
	}
};