#include "material.h"

string material::getTitle() const
{
    return title;
}

void material::setTitle(const string &value)
{
    title = value;
}

string material::getFormat() const
{
    return format;
}

void material::setFormat(const string &value)
{
    format = value;
}

audioTrack material::getMainAudioTrack() const
{
    return mainAudioTrack;
}

void material::setMainAudioTrack(const audioTrack &value)
{
    mainAudioTrack = value;
}

string material::getTotalRunTime() const
{
    return totalRunTime;
}

void material::setTotalRunTime(const string &value)
{
    totalRunTime = value;
}

float material::getRetailPrice() const
{
    return retailPrice;
}

void material::setRetailPrice(float value)
{
    retailPrice = value;
}

frameAspect material::getAspect() const
{
    return aspect;
}

void material::setAspect(const frameAspect &value)
{
    aspect = value;
}

material::material()
{
    
}

material::material(int id_, string title_, string format_, audioTrack mainAudioTrack_, string totalRunTime_, float retailPrice_, frameAspect aspect_)
{
    this->id = id_;
    this->title = title_;
    this->format = format_;
    this->mainAudioTrack = mainAudioTrack_;
    this->totalRunTime = totalRunTime_;
    this->retailPrice = retailPrice_;
    this->aspect = aspect_;
}

int material::getId() const
{
    return id;
}

void material::setId(int value)
{
    id = value;
}
