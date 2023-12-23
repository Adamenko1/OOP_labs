#pragma once

#include "Label.h"
#include "TextBox.h"
#include "ComboBox.h"
#include "Button.h"

__interface ControlFactory
{
public:
    Label* createLabel();
    TextBox* createTextBox();
    ComboBox* createComboBox();
    Button* createButton(); // virtual // = 0;

};