#ifndef DVD_H
#define DVD_H

#include "material.h"
#include "audiotrack.h"

class dvd: public material
{
private:
    vector<audioTrack> audioTracks;
    string bonusFeatures;
public:
    dvd();
    vector<audioTrack> getAudioTracks() const;
    void setAudioTracks(const vector<audioTrack> &value);
    string getBonusFeatures() const;
    void setBonusFeatures(const string &value);
};

#endif // DVD_H
