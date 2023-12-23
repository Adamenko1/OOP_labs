#pragma once

#include "ControlFactory.h"
#include "LinLabel.h"
#include "LinTextBox.h"
#include "LinComboBox.h"
#include "LinButton.h"

#include <iostream>

class LinControlFactory : public ControlFactory
{
public:
	LinControlFactory()
	{
		std::cout << "Creating LinControlFactory" << '\n';
	}
	Label* createLabel() override
	{
		return new LinLabel();
	}

	TextBox* createTextBox() override
	{
		return new LinTextBox();
	}

	ComboBox* createComboBox() override
	{
		return new LinComboBox();
	}

	Button* createButton() override {
		return new LinButton();
	}
};