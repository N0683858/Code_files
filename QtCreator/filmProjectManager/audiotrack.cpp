#include "audiotrack.h"

string audioTrack::getLanguage() const
{
    return language;
}

void audioTrack::setLanguage(const string &value)
{
    language = value;
}

string audioTrack::getAudioFormat() const
{
    return audioFormat;
}

void audioTrack::setAudioFormat(const string &value)
{
    audioFormat = value;
}

audioTrack::audioTrack()
{
    
}
