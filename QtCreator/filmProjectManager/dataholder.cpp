#include "dataholder.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

dataHolder::dataHolder()
{
    //load(); <-- should i call it here?
}

bool dataHolder::addProject(project* p)
{
    projects.push_back(p);
}


/*
this function might not be worth keeping.
intention would be to use it when using browse tab
 and searching via project id...
*/
project* dataHolder::getProject(int id)
{
    for(size_t x = 0; x < projects.size(); x++){
        if(projects[x]->getId() == x){
            return projects[x];
        }
    }
    throw std::invalid_argument("project not found");
}

vector<project*> dataHolder::getProjectList()
{
    return projects;
}

void dataHolder::save() //takes value "QString fileName"
{
    //open file
    //Make sure the file opened successfully
    //loop through projects vector
    //add infomation of each project into file
    //seperate the info by a "Space" so it's easier to read
    //have each project read into the file by line by line
    //So the first line in the file will holdthe 1st project the second line will hold 2nd project etc

    QFile myFile("projects.txt"); //or make the function so it takes a QString value which will be the filename
    if(!myFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug() << "Could not open file for saving data";
        return;
    }

    QTextStream save(&myFile);
    char num_of_projects = projects.size();
    save << num_of_projects << "\n"; //use this to keep track of how many projects we have so
    //it's easier to read back from the file by creating a for loop since while(!file.atEnd()) wasn't working properly for me

    for(size_t i = 0; i < projects.size(); i++)
    {
        //this way the code is easier to read rather than putting it all onto one line
        save << projects[i]->getId() << " ";
        save << projects[i]->getTitle() << " ";
        save << projects[i]->getGenre() << " ";
        save << projects[i]->getRuntime() << " ";
        save << projects[i]->getMainLanguage() << " ";
        save << projects[i]->getSummary() << " ";
        save << projects[i]->getReleaseDate() << " ";
        //Producer's Info
        save << projects[i]->getCrew().getProducer().getAge() << " ";
        save << projects[i]->getCrew().getProducer().getContactInfo() << " ";
        save << projects[i]->getCrew().getProducer().getName() << " ";
        save << projects[i]->getCrew().getProducer().getSalery() << " ";
        //Director's Info
        save << projects[i]->getCrew().getDirector().getAge() << " ";
        save << projects[i]->getCrew().getDirector().getContactInfo() << " ";
        save << projects[i]->getCrew().getDirector().getName() << " ";
        save << projects[i]->getCrew().getDirector().getSalery() << " ";
        //Writer's Info
        save << projects[i]->getCrew().getWriter().getAge() << " ";
        save << projects[i]->getCrew().getWriter().getContactInfo() << " ";
        save << projects[i]->getCrew().getWriter().getName() << " ";
        save << projects[i]->getCrew().getWriter().getSalery() << " ";
        //Costume Designer's Info
        save << projects[i]->getCrew().getCostumeDesigner().getAge() << " ";
        save << projects[i]->getCrew().getCostumeDesigner().getContactInfo() << " ";
        save << projects[i]->getCrew().getCostumeDesigner().getName() << " ";
        save << projects[i]->getCrew().getCostumeDesigner().getSalery() << " ";
        //Editor's Info
        save << projects[i]->getCrew().getEditor().getAge() << " ";
        save << projects[i]->getCrew().getEditor().getContactInfo() << " ";
        save << projects[i]->getCrew().getEditor().getName() << " ";
        save << projects[i]->getCrew().getEditor().getSalery() << " ";
        //Production Designer's Info
        save << projects[i]->getCrew().getProductionDesigner().getAge() << " ";
        save << projects[i]->getCrew().getProductionDesigner().getContactInfo() << " ";
        save << projects[i]->getCrew().getProductionDesigner().getName() << " ";
        save << projects[i]->getCrew().getProductionDesigner().getSalery() << " ";
        //Set Decorator's Info
        save << projects[i]->getCrew().getSetDecorator.getAge() << " ";
        save << projects[i]->getCrew().getSetDecorator.getContactInfo() << " ";
        save << projects[i]->getCrew().getSetDecorator.getName() << " ";
        save << projects[i]->getCrew().getSetDecorator.getSalery() << " ";
        save << projects[i]->getListOfFilmingLocations() << " ";
        save << projects[i]->getCrew().getCast() << " ";
        save << projects[i]->getListOfKeywords() << "\n";
    }


    //close file
    myfile.close();
}

void dataHolder::load()
{
    //open file
    //create loop reading each projects data
    //add each project to projects vector

    QFile myFile("projects.txt"); //or make the function so it takes a QString value which will be the filename
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file for reading data";
        return;
    }

    QTextStream loading(&myFile);
    int num_of_projects = loading.readLine().toInt(); //get the number of projects to create for loop

    for(size_t i = 0; i < num_of_projects; i++)
    {
        QString loadProject = reading.readLine();
        QRegExp rx("[, \n]"); // match a comma or a space etc. so basically anything you want to ingore want not be read in
        QStringList tempProjectHolder = loadProject.split(rx, QString::SkipEmptyParts);

        projects[i]->setId(tempProjectHolder.at(0);//would you need to convert it to an int
        projects[i]->setTitle(tempProjectHolder.at(1));
        save << projects[i]->getGenre() << " ";
        save << projects[i]->getRuntime() << " ";
        save << projects[i]->getMainLanguage() << " ";
        save << projects[i]->getSummary() << " ";
        save << projects[i]->getReleaseDate() << " ";
        //Producer's Info
        save << projects[i]->getCrew().getProducer().getAge() << " ";
        save << projects[i]->getCrew().getProducer().getContactInfo() << " ";
        save << projects[i]->getCrew().getProducer().getName() << " ";
        save << projects[i]->getCrew().getProducer().getSalery() << " ";
        //Director's Info
        save << projects[i]->getCrew().getDirector().getAge() << " ";
        save << projects[i]->getCrew().getDirector().getContactInfo() << " ";
        save << projects[i]->getCrew().getDirector().getName() << " ";
        save << projects[i]->getCrew().getDirector().getSalery() << " ";
        //Writer's Info
        save << projects[i]->getCrew().getWriter().getAge() << " ";
        save << projects[i]->getCrew().getWriter().getContactInfo() << " ";
        save << projects[i]->getCrew().getWriter().getName() << " ";
        save << projects[i]->getCrew().getWriter().getSalery() << " ";
        //Costume Designer's Info
        save << projects[i]->getCrew().getCostumeDesigner().getAge() << " ";
        save << projects[i]->getCrew().getCostumeDesigner().getContactInfo() << " ";
        save << projects[i]->getCrew().getCostumeDesigner().getName() << " ";
        save << projects[i]->getCrew().getCostumeDesigner().getSalery() << " ";
        //Editor's Info
        save << projects[i]->getCrew().getEditor().getAge() << " ";
        save << projects[i]->getCrew().getEditor().getContactInfo() << " ";
        save << projects[i]->getCrew().getEditor().getName() << " ";
        save << projects[i]->getCrew().getEditor().getSalery() << " ";
        //Production Designer's Info
        save << projects[i]->getCrew().getProductionDesigner().getAge() << " ";
        save << projects[i]->getCrew().getProductionDesigner().getContactInfo() << " ";
        save << projects[i]->getCrew().getProductionDesigner().getName() << " ";
        save << projects[i]->getCrew().getProductionDesigner().getSalery() << " ";
        //Set Decorator's Info
        save << projects[i]->getCrew().getSetDecorator.getAge() << " ";
        save << projects[i]->getCrew().getSetDecorator.getContactInfo() << " ";
        save << projects[i]->getCrew().getSetDecorator.getName() << " ";
        save << projects[i]->getCrew().getSetDecorator.getSalery() << " ";
        save << projects[i]->getListOfFilmingLocations() << " ";
        save << projects[i]->getCrew().getCast() << " ";
        save << projects[i]->getListOfKeywords() << "\n";

    }

    //close file
}

void Read(QString fileName)
{
    QFile myFile(fileName);

    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open the file";
        return;
    }

    QTextStream reading(&myFile);
    //reading.setCodec("UTF-8");

    while(!reading.atEnd())
   // for(int i = 0; i < 5; i++)
    {
        QString myText = reading.readLine();

        QRegExp rx("[, \n]"); // match a comma or a space
        QStringList list = myText.split(rx, QString::SkipEmptyParts);
        for(int x = 0; x < list.size(); x++)
        {
            qDebug() << list.at(x);
        }

    }

    myFile.close();
}
