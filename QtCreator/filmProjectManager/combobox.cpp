#include "combobox.h"

vector<dvd> comboBox::getDvdList() const
{
    return dvdList;
}

void comboBox::setDvdList(const vector<dvd> &value)
{
    dvdList = value;
}

packaging comboBox::getPacking() const
{
    return packing;
}

void comboBox::setPacking(const packaging &value)
{
    packing = value;
}

comboBox::comboBox()
{

}
