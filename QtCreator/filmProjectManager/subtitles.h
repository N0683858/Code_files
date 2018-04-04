#ifndef SUBTITLES_H
#define SUBTITLES_H

using namespace std;
#include <string>
#include <vector>

class subtitles
{
private:
    string line;
    string timing;
public:
    subtitles();
    string getLine() const;
    void setLine(const string &value);
    string getTiming() const;
    void setTiming(const string &value);
};

#endif // SUBTITLES_H
