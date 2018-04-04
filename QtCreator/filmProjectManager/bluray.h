#ifndef BLURAY_H
#define BLURAY_H

#include "dvd.h"
#include "packaging.h"

class bluRay: public dvd
{
private:
     packaging packing;
public:
    bluRay();
    packaging getPacking() const;
    void setPacking(const packaging &value);
};

#endif // BLURAY_H
