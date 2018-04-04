#ifndef CREW_H
#define CREW_H

#include "person.h"
#include <vector>

class crew
{
private:
    person producer;
    person director;
    person writer;
    vector<person> cast;
    person editor;
    person productionDesigner;
    person setDecorator;
    person costumeDesigner;
public:
    crew();
    person getProducer() const;
    void setProducer(const person &value);
    person getDirector() const;
    void setDirector(const person &value);
    person getWriter() const;
    void setWriter(const person &value);
    vector<person> getCast() const;
    void setCast(const vector<person> &value);
    person getEditor() const;
    void setEditor(const person &value);
    person getProductionDesigner() const;
    void setProductionDesigner(const person &value);
    person getSetDecorator() const;
    void setSetDecorator(const person &value);
    person getCostumeDesigner() const;
    void setCostumeDesigner(const person &value);
};

#endif // CREW_H
