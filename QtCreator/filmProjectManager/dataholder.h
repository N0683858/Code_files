#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include <project.h>
#include <vector>
#include <stdexcept>

using namespace std;

class dataHolder
{
private:
    vector<project*> projects;
public:
    dataHolder();

    bool addProject(project*);
    project* getProject(int);
    vector<project*> getProjectList();

    void save();
    void load();

};

#endif // DATAHOLDER_H
