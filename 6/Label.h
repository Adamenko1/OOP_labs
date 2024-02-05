#pragma once

#include <string>

__interface Label
{
public:
	void setText(std::string text);
	const std::string getText() const;
};