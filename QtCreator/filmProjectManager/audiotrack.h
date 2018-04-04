#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <string>
#include "subtitles.h"
using namespace std;

class audioTrack
{
private:
    string language;
    string audioFormat;
public:
    audioTrack();
    vector<subtitles> subtitles;
    string getLanguage() const;
    void setLanguage(const string &value);
    string getAudioFormat() const;
    void setAudioFormat(const string &value);
};

#endif // AUDIOTRACK_H
