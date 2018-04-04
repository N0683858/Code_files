#ifndef PROJECT_H
#define PROJECT_H


#include <string>
#include <vector>
#include "crew.h"
#include "filminglocation.h"

using namespace std;

class project
{
private:
    int id;
    string title;
    string summary;
    string genre;
    string releaseDate;
    vector<filmingLocation> listOfFilmingLocations;
    string mainLanguage;
    string runtime;
    vector<string> listOfKeywords;
    crew projectCrew;
public:
    project();
    virtual string getTitle() const;
    virtual void setTitle(const string &value);
    virtual string getSummary() const;
    virtual void setSummary(const string &value);
    virtual string getGenre() const;
    virtual void setGenre(const string &value);
    virtual string getReleaseDate() const;
    virtual void setReleaseDate(const string &value);
    virtual vector<filmingLocation> getListOfFilmingLocations() const;
    virtual void setListOfFilmingLocations(const string &value);
    virtual string getMainLanguage() const;
    virtual void setMainLanguage(const string &value);
    virtual string getRuntime() const;
    virtual void setRuntime(const string &value);
    virtual vector<string> getListOfKeywords() const;
    virtual void setListOfKeywords(const string &value);
    virtual crew getCrew() const;
    virtual void setCrew(const crew &value);
    virtual int getId() const;
    virtual void setId(int value);
};

#endif // PROJECT_H
