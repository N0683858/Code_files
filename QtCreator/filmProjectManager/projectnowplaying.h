#ifndef PROJECTNOWPLAYING_H
#define PROJECTNOWPLAYING_H

#include "project.h"
#include <string>
using namespace std;

class projectNowPlaying: public project
{
private:
    string weeklyTicketSale;
public:
    projectNowPlaying();
    string getWeeklyTicketSale() const;
    void setWeeklyTicketSale(const string &value);
};

#endif // PROJECTNOWPLAYING_H
