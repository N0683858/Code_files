#ifndef PROJECTRELEASED_H
#define PROJECTRELEASED_H

#include "project.h"
#include <string>
#include "material.h"
#include <vector>
using namespace std;

class projectReleased: public project
{
private:
    string weeklyTicketSale;
    vector<material*> listOfMaterials;
public:
    projectReleased();
    string getWeeklyTicketSale() const;
    void setWeeklyTicketSale(const string &value);
    vector<material *> getListOfMaterials() const;
    void setListOfMaterials(const vector<material *> &value);
    void addMaterial(material*);
};

#endif // PROJECTRELEASED_H
