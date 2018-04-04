#include "dvddoublesided.h"

packaging dvdDoubleSided::getPacking() const
{
    return packing;
}

void dvdDoubleSided::setPacking(const packaging &value)
{
    packing = value;
}

dvdDoubleSided::dvdDoubleSided()
{

}

string dvdDoubleSided::getSideInfo() const
{
    return sideInfo;
}

void dvdDoubleSided::setSideInfo(const string &value)
{
    sideInfo = value;
}
