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
        osName = std::string(std::getenv("OS")) + std::string("ControlFactory");
        std::cout << "Creating WindowsControlFactory" << std::endl;
    }

    Label* createLabel() override
    {
        if (osName.find("Windows") != std::string::npos)
        {
            return new WindowsLabel();
        }
        return nullptr;
    }

    TextBox* createTextBox() override
    {
        if (osName.find("Windows") != std::string::npos)
        {
            return new WindowsTextBox();
        }
        return nullptr;
    }

    ComboBox* createComboBox() override
    {
        if (osName.find("Windows") != std::string::npos)
        {
            return new WindowsComboBox();
        }
        return nullptr;
    }

    Button* createButton() override
    {
        if (osName.find("Windows") != std::string::npos)
        {
            return new WindowsButton();
        }
        return nullptr;
    }
};