#pragma once

#include "Control.h"
#include "ComboBox.h"
#include <iostream>

class WindowsComboBox : public Control, public ComboBox
{
    int selectedIndex;
    std::vector<std::string> items;

public:
    void setSelectedIndex(int index)
    {
        this->selectedIndex = index;
        std::cout << "Windows index selected" << '\n';
    }

    void setItems(std::vector<std::string> items)
    {
        this->items = items;
        std::cout << "Windows items selected" << '\n';
    }

    const int getSelectedIndex() const override
    {
        std::cout << "Windows Selected Index: ";
        return this->selectedIndex;
    }

    const std::vector<std::string> getItems() const override
    {
        std::cout << "Linux Items: " << '\n';
        return this->items;
    }
};