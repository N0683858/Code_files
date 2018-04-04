#include "dvdsinglesided.h"

dvdSingleSided::dvdSingleSided()
{

}

packaging dvdSingleSided::getPacking() const
{
    return packing;
}

void dvdSingleSided::setPacking(const packaging &value)
{
    packing = value;
}
