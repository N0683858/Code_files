#ifndef FRAMEASPECT_H
#define FRAMEASPECT_H

#include <string>
using namespace std;

class frameAspect
{
private:
    string type;
    int height;
    int width;
public:
    frameAspect();

    string getType() const;
    void setType(const string &value);
    int getHeight() const;
    void setHeight(int value);
    int getWidth() const;
    void setWidth(int value);
};

#endif // FRAMEASPECT_H
