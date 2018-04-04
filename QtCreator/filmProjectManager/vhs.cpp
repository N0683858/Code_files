#include "vhs.h"

audioTrack vhs::getTrack() const
{
    return track;
}

void vhs::setTrack(const audioTrack &value)
{
    track = value;
}

vhs::vhs()
{
    
}
