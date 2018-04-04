#include "dvd.h"

vector<audioTrack> dvd::getAudioTracks() const
{
    return audioTracks;
}

void dvd::setAudioTracks(const vector<audioTrack> &value)
{
    audioTracks = value;
}

string dvd::getBonusFeatures() const
{
    return bonusFeatures;
}

void dvd::setBonusFeatures(const string &value)
{
    bonusFeatures = value;
}

dvd::dvd()
{

}
