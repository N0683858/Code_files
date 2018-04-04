#ifndef FILMINGLOCATION_H
#define FILMINGLOCATION_H

#include <string>
#include "crew.h"
using namespace std;

class filmingLocation
{
private:
    string date;
    string location;
    crew crewNeeded;
public:
    filmingLocation();
    string getDate() const;
    void setDate(const string &value);
    string getLocation() const;
    void setLocation(const string &value);
    crew getCrewNeeded() const;
    void setCrewNeeded(const crew &value);
};

#endif // FILMINGLOCATION_H
