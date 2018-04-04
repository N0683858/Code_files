#include "subtitles.h"

string subtitles::getTiming() const
{
    return timing;
}

void subtitles::setTiming(const string &value)
{
    timing = value;
}

subtitles::subtitles()
{

}

string subtitles::getLine() const
{
    return line;
}

void subtitles::setLine(const string &value)
{
    line = value;
}
