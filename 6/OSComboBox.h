#pragma once

#include "Control.h"
#include "ComboBox.h"
#include <iostream>

class OSComboBox : public Control, public ComboBox
{
    int selectedIndex;
    std::vector<std::string> items;

public:
    void setSelectedIndex(int index)
    {
        this->selectedIndex = index;
        std::cout << "MacOS index selected" << '\n';
    }

    void setItems(std::vector<std::string> items)
    {
        this->items = items;
        std::cout << "MacOS items selected" << '\n';
    }

    const int getSelectedIndex() const override
    {
        return this->selectedIndex << '\n';
    }

    const std::vector<std::string> getItems() const override
    {
        std::cout << "MacOS Items: " << '\n';
        return this->items;
    }
};