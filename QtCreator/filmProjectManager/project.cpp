#include "project.h"


string project::getSummary() const
{
    return summary;
}

void project::setSummary(const string &value)
{
    summary = value;
}

string project::getGenre() const
{
    return genre;
}

void project::setGenre(const string &value)
{
    genre = value;
}

string project::getReleaseDate() const
{
    return releaseDate;
}

void project::setReleaseDate(const string &value)
{
    releaseDate = value;
}

vector<filmingLocation> project::getListOfFilmingLocations() const
{
    return listOfFilmingLocations;
}

void project::setListOfFilmingLocations(const string &value)
{
    //listOfFilmingLocations = value;
}

string project::getMainLanguage() const
{
    return mainLanguage;
}

void project::setMainLanguage(const string &value)
{
    mainLanguage = value;
}

string project::getRuntime() const
{
    return runtime;
}

void project::setRuntime(const string &value)
{
    runtime = value;
}

vector<string> project::getListOfKeywords() const
{
    return listOfKeywords;
}

void project::setListOfKeywords(const string &value)
{
    //listOfKeywords = value;
}

crew project::getCrew() const
{
    return projectCrew;
}

void project::setCrew(const crew &value)
{
    projectCrew = value;
}

int project::getId() const
{
    return id;
}

void project::setId(int value)
{
    id = value;
}

project::project()
{
    
}

string project::getTitle() const
{
    return title;
}

void project::setTitle(const string &value)
{
    title = value;
}
