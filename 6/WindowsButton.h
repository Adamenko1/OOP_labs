#pragma once
#include "Control.h"
#include "Button.h"
#include <string>
#include <iostream>

class WindowsButton : public Button, public Control
{
    std::string text;

public:
    void setText(std::string newText) override
    {
        std::cout << "Windows Button Text Seted" << '\n';
        this->text = newText;
    }

    void setOnClick() override
    {
        std::cout << "Method called from Windows Button" << '\n';
    }

    const std::string getText() const override
    {
        std::cout << "Windows Button: ";
        return this->text;
    }

    void click() override
    {
        std::cout << "Button clicked" << '\n';
    }
};