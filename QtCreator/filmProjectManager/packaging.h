#ifndef PACKAGING_H
#define PACKAGING_H

#include <string>
using namespace std;

class packaging
{
private:
    int Size;
    string type;
public:
    packaging();
    int getSize() const;
    void setSize(int value);
    string getType() const;
    void setType(const string &value);
};

#endif // PACKAGING_H
