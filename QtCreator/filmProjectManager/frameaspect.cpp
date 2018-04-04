#include "frameaspect.h"

int frameAspect::getHeight() const
{
    return height;
}

void frameAspect::setHeight(int value)
{
    height = value;
}

int frameAspect::getWidth() const
{
    return width;
}

void frameAspect::setWidth(int value)
{
    width = value;
}

frameAspect::frameAspect()
{
    
}

string frameAspect::getType() const
{
    return type;
}

void frameAspect::setType(const string &value)
{
    type = value;
}
