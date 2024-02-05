#pragma once

#include "ControlFactory.h"
#include <iostream>
#include "WindowsLabel.h"
#include "WindowsTextBox.h"
#include "WindowsComboBox.h"
#include "WindowsButton.h"

class WindowsControlFactory : public ControlFactory
{
private:
    std::string osName;

public:
    WindowsControlFactory()
    {
        std::cout << "Creating WindowsControlFactory" << '\n';
    }
    Label* createLabel() override
    {
        return new WindowsLabel();
    }

    TextBox* createTextBox() override
    {
        return new WindowsTextBox();
    }

    ComboBox* createComboBox() override
    {
        return new WindowsComboBox();
    }

    Button* createButton() override {
        return new WindowsButton();
    }
};