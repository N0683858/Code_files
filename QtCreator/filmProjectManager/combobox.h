#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "material.h"
#include "dvd.h"
#include "packaging.h"

class comboBox: public material
{
private:
    vector<dvd> dvdList;
    packaging packing;
public:
    comboBox();

    vector<dvd> getDvdList() const;
    void setDvdList(const vector<dvd> &value);
    packaging getPacking() const;
    void setPacking(const packaging &value);
};

#endif // COMBOBOX_H
