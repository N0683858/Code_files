#include "filminglocation.h"

string filmingLocation::getLocation() const
{
    return location;
}

void filmingLocation::setLocation(const string &value)
{
    location = value;
}

crew filmingLocation::getCrewNeeded() const
{
    return crewNeeded;
}

void filmingLocation::setCrewNeeded(const crew &value)
{
    crewNeeded = value;
}

filmingLocation::filmingLocation()
{
    
}

string filmingLocation::getDate() const
{
    return date;
}

void filmingLocation::setDate(const string &value)
{
    date = value;
}
