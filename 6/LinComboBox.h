#pragma once

#include "Control.h"
#include "ComboBox.h"
#include <iostream>

class LinComboBox : public Control, public ComboBox
{
    int selectedIndex;
    std::vector<std::string> items;

public:
    void setSelectedIndex(int index)
    {
        std::cout << "Method called from Linux Button" << '\n';
    }

    void setItems(std::vector<std::string> items)
    {
        std::cout << "Method called from Linux Button" << '\n';
    }

    const int getSelectedIndex() const override
    {
        return selectedIndex;
    }

    const std::vector<std::string>& getItems() const override
    {
        return items;
    }
};