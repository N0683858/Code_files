#ifndef MATERIAL_H
#define MATERIAL_H

#include "frameaspect.h"
#include "audiotrack.h"

class material
{
private:
    int id;
    string title;
    string format;
    audioTrack mainAudioTrack; //subtitles & language in audioTrack
    string totalRunTime;
    float retailPrice;
    frameAspect aspect;
public:
    material();
    material(int id_, string title_, string format_, audioTrack mainAudioTrack_,string totalRunTime_,float retailPrice_,frameAspect aspect_);
    virtual int getId() const;
    virtual void setId(int value);
    virtual string getTitle() const;
    virtual void setTitle(const string &value);
    virtual string getFormat() const;
    virtual void setFormat(const string &value);
    virtual audioTrack getMainAudioTrack() const;
    virtual void setMainAudioTrack(const audioTrack &value);
    virtual string getTotalRunTime() const;
    virtual void setTotalRunTime(const string &value);
    virtual float getRetailPrice() const;
    virtual void setRetailPrice(float value);
    virtual frameAspect getAspect() const;
    virtual void setAspect(const frameAspect &value);
};

#endif // MATERIAL_H
