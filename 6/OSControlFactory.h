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
        std::cout << "Creating MacOSControlFactory" << '\n';
    }
    Label* createLabel() override
    {
        return new OSLabel();
    }

    TextBox* createTextBox() override
    {
        return new OSTextBox();
    }

    ComboBox* createComboBox() override
    {
        return new OSComboBox();
    }

    Button* createButton() override {
        return new OSButton();
    }
};