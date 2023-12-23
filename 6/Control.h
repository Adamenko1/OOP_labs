#pragma once

class Control
{
protected:
    int position;
public:
    void setPosition(int newPosition)
    {
        position = newPosition;
    }

    const int getPosition() const
    {
        return position;
    }
};