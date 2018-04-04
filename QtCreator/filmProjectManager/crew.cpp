#include "crew.h"

person crew::getDirector() const
{
    return director;
}

void crew::setDirector(const person &value)
{
    director = value;
}

person crew::getWriter() const
{
    return writer;
}

void crew::setWriter(const person &value)
{
    writer = value;
}

vector<person> crew::getCast() const
{
    return cast;
}

void crew::setCast(const vector<person> &value)
{
    cast = value;
}

person crew::getEditor() const
{
    return editor;
}

void crew::setEditor(const person &value)
{
    editor = value;
}

person crew::getProductionDesigner() const
{
    return productionDesigner;
}

void crew::setProductionDesigner(const person &value)
{
    productionDesigner = value;
}

person crew::getSetDecorator() const
{
    return setDecorator;
}

void crew::setSetDecorator(const person &value)
{
    setDecorator = value;
}

person crew::getCostumeDesigner() const
{
    return costumeDesigner;
}

void crew::setCostumeDesigner(const person &value)
{
    costumeDesigner = value;
}

crew::crew()
{
    
}

person crew::getProducer() const
{
    return producer;
}

void crew::setProducer(const person &value)
{
    producer = value;
}
