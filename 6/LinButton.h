#pragma once

#include "Control.h"
#include "Button.h"
#include <string>
#include <iostream>

class LinButton : public Button, public Control
{
    std::string text;

public:
    void setText(std::string newText) override
    {
        std::cout << "Linux Button Text Seted" << '\n';
        this->text = newText;
    }

    void setOnClick() override
    {
        std::cout << "Method called from Linux Button" << '\n';
    }

    const std::string getText() const override
    {
        std::cout << "Linux Button: ";
        return this->text;
    }

    void click() override
    {
        std::cout << "Linux Button clicked" << '\n';
    }
};