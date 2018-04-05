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

void dataHolder::save() //could take value "QString fileName"
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
        //Cast Info
        save << projects[i]->getCrew().getCast()[i].getAge() << " ";
        save << projects[i]->getCrew().getCast()[i].getContactInfo() << " ";
        save << projects[i]->getCrew().getCast()[i].getName() << " ";
        save << projects[i]->getCrew().getCast()[i].getSalery() << " ";

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
        QString loadProject = reading.readLine();//read the next line from the file
        QRegExp rx("[, \n]"); // match a comma or a space etc. so basically anything you want to ingore want not be read in
        QStringList tempProjectHolder = loadProject.split(rx, QString::SkipEmptyParts);//save the string without including any of the spaces and commas etc.
        //convert the string to Int
        QString temptIDholder = tempProjectHolder.at(0);
        int convertedID = temptIDholder.toInt();
        //reading the data into the right variables from the list string
        project* newProject = new project;
        addProject(newProject);
        newProject->setId(convertedID);
        newProject->setTitle(tempProjectHolder[0]);
        projects[i]->setTitle(tempProjectHolder.at(1));//getting second item from the list which should be the title and then so on
        projects[i]->setGenre(tempProjectHolder.at(2));
        projects[i]->setRuntime(tempProjectHolder.at(3));
        projects[i]->setMainLanguage(tempProjectHolder.at(4));
        projects[i]->setSummary(tempProjectHolder.at(5));
        projects[i]->setReleaseDate(tempProjectHolder.at(6));

        //Cast Info
        save << projects[i]->getCrew().getCast()[i].getAge() << " ";
        save << projects[i]->getCrew().getCast()[i].getContactInfo() << " ";
        save << projects[i]->getCrew().getCast()[i].getName() << " ";
        save << projects[i]->getCrew().getCast()[i].getSalery() << " ";

        //Producer's Info
        //projects[i]->setCrew(project::setProducer(tempProjectHolder.at(7), tempProjectHolder.at(8), tempProjectHolder.at(9), tempProjectHolder.at(10)));//wouldn set Crew needs to take more values
        //such "int age, QString contactInfo, QString name, QString salary" or somthing so you can then assign them or is there another way. I've had a look inside the cpp files and functions and still
        //didn't understand how you wanted the data being read in, sorry but i i'll give it a try anyway
        //projects[i]->setCrew(tempProjectHolder.at(7).setProducer().setAge()); //or is it supposed to be somthing like this or are they supposed to be nested inside eachother
        projects[i]->setCrew(crew::setProducer(person::setAge(tempProjectHolder.at(7))));
        projects[i]->setCrew(crew::setProducer(person::setContactInfo(tempProjectHolder.at(8))));
        projects[i]->setCrew(crew::setProducer(person::setName(tempProjectHolder.at(9))));
        projects[i]->setCrew(crew::setProducer(person::setSalery(tempProjectHolder.at(10))));

        //Director's Info
        projects[i]->setCrew(crew::setDirector(person::setAge(tempProjectHolder.at(11))));
        projects[i]->setCrew(crew::setDirectorr(person::setContactInfo(tempProjectHolder.at(12))));
        projects[i]->setCrew(crew::setDirector(person::setName(tempProjectHolder.at(13))));
        projects[i]->setCrew(crew::setDirector(person::setSalery(tempProjectHolder.at(14))));

        //Writer's Info
        projects[i]->setCrew(crew::setWriter(person::setAge(tempProjectHolder.at(15)))); 
        projects[i]->setCrew(crew::setWriter(person::setContactInfo(tempProjectHolder.at(16))));
        projects[i]->setCrew(crew::setWriter(person::setName(tempProjectHolder.at(17))));
        projects[i]->setCrew(crew::setWriter(person::setSalery(tempProjectHolder.at(18))));

        //Costume Designer's Info
        projects[i]->setCrew(crew::setCostumeDesigner(person::setAge(tempProjectHolder.at(19))));
        projects[i]->setCrew(crew::setCostumeDesigner(person::setContactInfo(tempProjectHolder.at(20))));
        projects[i]->setCrew(crew::setCostumeDesigner(person::setName(tempProjectHolder.at(21))));
        projects[i]->setCrew(crew::setCostumeDesigner(person::setSalery(tempProjectHolder.at(22))));

        //Editor's Info
        projects[i]->setCrew(crew::setEditor(person::setAge(tempProjectHolder.at(23))));
        projects[i]->setCrew(crew::setEditor(person::setContactInfo(tempProjectHolder.at(24))));
        projects[i]->setCrew(crew::setEditor(person::setName(tempProjectHolder.at(25))));
        projects[i]->setCrew(crew::setEditor(person::setSalery(tempProjectHolder.at(26))));

        //Production Designer's Info
        projects[i]->setCrew(crew::setProductionDesigner(person::setAge(tempProjectHolder.at(27))));
        projects[i]->setCrew(crew::setProductionDesigner(person::setContactInfo(tempProjectHolder.at(28))));
        projects[i]->setCrew(crew::setProductionDesigner(person::setName(tempProjectHolder.at(29))));
        projects[i]->setCrew(crew::setProductionDesigner(person::setSalery(tempProjectHolder.at(30))));

        //Set Decorator's Info
        projects[i]->setCrew(crew::setSetDecorator(person::setAge(tempProjectHolder.at(31))));
        projects[i]->setCrew(crew::setSetDecorator(person::setContactInfo(tempProjectHolder.at(32))));
        projects[i]->setCrew(crew::setSetDecorator(person::setName(tempProjectHolder.at(33))));
        projects[i]->setCrew(crew::setSetDecorator(person::setSalery(tempProjectHolder.at(34))));

        projects[i]->setListOfFilmingLocations(tempProjectHolder.at(35));
        projects[i]->setCrew(crew::setCast(tempProjectHolder.at(36));
        projects[i]->setListOfKeywords(tempProjectHolder.at(37));

    }

    myFile.close();
    //close file
}
