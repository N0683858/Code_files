#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class person
{
private:
    string name;
    int age;
    string contactInfo;
    float salery;
public:
    person();
    person(string name);
    string getName() const;
    void setName(const string &value);
    int getAge() const;
    void setAge(int value);
    string getContactInfo() const;
    void setContactInfo(const string &value);
    float getSalery() const;
    void setSalery(float value);
};

#endif // PERSON_H
