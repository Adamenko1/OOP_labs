#pragma once
#include <string>
#include <vector>
__interface ComboBox
{
public:
    const int getSelectedIndex() const;
    void setSelectedIndex(int index);
    void setItems(std::vector<std::string> items);
    const std::vector<std::string> getItems() const;
};
