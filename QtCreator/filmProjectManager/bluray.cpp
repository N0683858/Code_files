#include "bluray.h"

bluRay::bluRay()
{

}

packaging bluRay::getPacking() const
{
    return packing;
}

void bluRay::setPacking(const packaging &value)
{
    packing = value;
}
