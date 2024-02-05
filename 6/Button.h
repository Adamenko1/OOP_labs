#pragma once
#include <string>

__interface Button
{
public:
    void setText(std::string text);
    const std::string getText() const;
    void setOnClick();
    void click();
};