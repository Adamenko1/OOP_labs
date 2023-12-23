#pragma once

#include "ControlFactory.h"
#include <iostream>
#include "OSLabel.h"
#include "OSTextBox.h"
#include "OSComboBox.h"
#include "OSButton.h"

class OSControlFactory : public ControlFactory
{
private:
    std::string osName;

public:
    OSControlFactory()
    {
        osName = std::string(std::getenv("OS")) + std::string("ControlFactory");
        std::cout << "Creating OSControlFactory" << std::endl;
    }

    Label* createLabel() override
    {
        if (osName.find("MacOS") != std::string::npos)
        {
            return new OSLabel();
        }
        return nullptr;
    }

    TextBox* createTextBox() override
    {
        if (osName.find("MacOS") != std::string::npos)
        {
            return new OSTextBox();
        }
        return nullptr;
    }

    ComboBox* createComboBox() override
    {
        if (osName.find("MacOS") != std::string::npos)
        {
            return new OSComboBox();
        }
        return nullptr;
    }

    Button* createButton() override
    {
        if (osName.find("MacOS") != std::string::npos)
        {
            return new OSButton();
        }
        return nullptr;
    }
};