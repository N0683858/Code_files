#ifndef DVDDOUBLESIDED_H
#define DVDDOUBLESIDED_H

#include "dvd.h"
#include "packaging.h"

class dvdDoubleSided: public dvd
{
private:
    string sideInfo;
    packaging packing;
public:
    dvdDoubleSided();
    string getSideInfo() const;
    void setSideInfo(const string &value);
    packaging getPacking() const;
    void setPacking(const packaging &value);
};

#endif // DVDDOUBLESIDED_H
