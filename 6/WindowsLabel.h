#pragma once

#include "Control.h"
#include "Label.h"
#include <iostream>
class WindowsLabel : public Control, public Label
{
protected:
	std::string text;

public:
	void setText(std::string& text) override
	{
		std::cout << "Method called from Windows Button" << '\n';
	}

	const std::string& getText() const override
	{
		return text;
	}
};