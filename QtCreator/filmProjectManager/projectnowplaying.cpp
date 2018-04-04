#include "projectnowplaying.h"

projectNowPlaying::projectNowPlaying()
{

}

string projectNowPlaying::getWeeklyTicketSale() const
{
    return weeklyTicketSale;
}

void projectNowPlaying::setWeeklyTicketSale(const string &value)
{
    weeklyTicketSale = value;
}
