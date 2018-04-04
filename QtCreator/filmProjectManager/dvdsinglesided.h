#ifndef DVDSINGLESIDED_H
#define DVDSINGLESIDED_H

#include "dvd.h"
#include "packaging.h"

class dvdSingleSided: public dvd
{
private:
    packaging packing;
public:
    dvdSingleSided();
    packaging getPacking() const;
    void setPacking(const packaging &value);
};

#endif // DVDSINGLESIDED_H
