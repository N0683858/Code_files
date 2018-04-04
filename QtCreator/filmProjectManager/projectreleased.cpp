#include "projectreleased.h"

string projectReleased::getWeeklyTicketSale() const
{
    return weeklyTicketSale;
}

void projectReleased::setWeeklyTicketSale(const string &value)
{
    weeklyTicketSale = value;
}

vector<material *> projectReleased::getListOfMaterials() const
{
    return listOfMaterials;
}

void projectReleased::setListOfMaterials(const vector<material *> &value)
{
    listOfMaterials = value;
}

void projectReleased::addMaterial(material* m)
{
    listOfMaterials.push_back(m);
}

projectReleased::projectReleased()
{

}
