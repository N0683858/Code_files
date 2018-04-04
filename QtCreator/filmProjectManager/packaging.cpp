#include "packaging.h"

string packaging::getType() const
{
    return type;
}

void packaging::setType(const string &value)
{
    type = value;
}

packaging::packaging()
{
    
}

int packaging::getSize() const
{
    return Size;
}

void packaging::setSize(int value)
{
    Size = value;
}
