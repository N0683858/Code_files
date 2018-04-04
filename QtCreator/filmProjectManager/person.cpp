#include "person.h"

int person::getAge() const
{
    return age;
}

void person::setAge(int value)
{
    age = value;
}

string person::getContactInfo() const
{
    return contactInfo;
}

void person::setContactInfo(const string &value)
{
    contactInfo = value;
}

float person::getSalery() const
{
    return salery;
}

void person::setSalery(float value)
{
    salery = value;
}

person::person()
{
    
}

person::person(string name)
{
    this->name = name;
}

string person::getName() const
{
    return name;
}

void person::setName(const string &value)
{
    name = value;
}
