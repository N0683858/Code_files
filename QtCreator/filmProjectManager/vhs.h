#ifndef VHS_H
#define VHS_H

#include "material.h"
#include "audiotrack.h"
#include "subtitles.h"

class vhs: public material
{
private:
    audioTrack track;
public:
    vhs();
    vector<subtitles> subtitles;
    audioTrack getTrack() const;
    void setTrack(const audioTrack &value);
};

#endif // VHS_H
