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
        newProject->setTitle(tempProjectHolder[1]);//getting second item from the list which should be the title and then so on
        newProject->setGenre(tempProjectHolder.at(2));
        newProject->setRuntime(tempProjectHolder.at(3));
        newProject->setMainLanguage(tempProjectHolder.at(4));
        newProject->setSummary(tempProjectHolder.at(5));
        newProject->setReleaseDate(tempProjectHolder.at(6));

        //Producer's Info
        //I've had a look inside the cpp files and functions and still
        //didn't understand how you wanted the data being read in, sorry but i thought i'll give it a try anyway and i personally thought I should just give the info to the functions and you should do something inside it, idk if the way im doing is right >.<
        QString producerAge = tempProjectHolder.at(7);
        int convertedProucerAge = producerAge.toInt();
        QString producerContactInfo = tempProjectHolder.at(8);
        QString producerName = tempProjectHolder.at(9);
        QString producerSalery = tempProjectHolder.at(10);
        int convertedProucerSal = producerSalery.toFloat();

        crew* setNewCrew = new crew;
        person* newPerson = new person;
        newProject->setCrew(setNewCrew->setProducer(newPerson->setAge(convertedProucerAge)));
        newProject->setCrew(setNewCrew->setProducer(newPerson->setContactInfo(producerContactInfo)));
        newProject->setCrew(setNewCrew->setProducer(newPerson->setName(producerName);));
        newProject->setCrew(setNewCrew->setProducer(newPerson->setSalery(convertedProucerSal);));

        //Director's Info
        QString directorAge = tempProjectHolder.at(11);
        int convertedDirectorAge = directorAge.toInt();
        QString directorContactInfo = tempProjectHolder.at(12);
        QString directorName = tempProjectHolder.at(13);
        QString directorSalery = tempProjectHolder.at(14);
        int convertedDirectorSal = directorSalery.toFloat();

        newProject->setCrew(setNewCrew->setDirector(newPerson->setAge(convertedDirectorAge)));
        newProject->setCrew(setNewCrew->setDirector(newPerson->setContactInfo(directorContactInfo);));
        newProject->setCrew(setNewCrew->setDirector(newPerson->setName(directorName);));
        newProject->setCrew(setNewCrew->setDirector(newPerson->setSalery(convertedDirectorSal);));

        //Writer's Info
        QString writerAge = tempProjectHolder.at(15);
        int convertedWriterAge = writerAge.toInt();
        QString writerContactInfo = tempProjectHolder.at(16);
        QString writerName = tempProjectHolder.at(17);
        QString writerSalery = tempProjectHolder.at(18);
        int convertedWriterSal = writerSalery.toFloat();

        newProject->setCrew(setNewCrew->setWriter(newPerson->setAge(convertedWriterAge)));
        newProject->setCrew(setNewCrew->setWriter(newPerson->setContactInfo(writerContactInfo);));
        newProject->setCrew(setNewCrew->setWriter(newPerson->setName(writerName);));
        newProject->setCrew(setNewCrew->setWriter(newPerson->setSalery(convertedWriterSal);));

        //Costume Designer's Info
        QString costDesignerAge = tempProjectHolder.at(19);
        int convertedCostDesignerAge = costDesignerAge.toInt();
        QString costDesignerContactInfo = tempProjectHolder.at(20);
        QString costDesignerName = tempProjectHolder.at(21);
        QString costDesignerSalery = tempProjectHolder.at(22);
        int convertedCostDesignerSal = costDesignerSalery.toFloat();

        newProject->setCrew(setNewCrew->setCostumeDesigner(newPerson->setAge(convertedCostDesignerAge)));
        newProject->setCrew(setNewCrew->setCostumeDesigner(newPerson->setContactInfo(costDesignerContactInfo);));
        newProject->setCrew(setNewCrew->setCostumeDesigner(newPerson->setName(costDesignerName);));
        newProject->setCrew(setNewCrew->setCostumeDesigner(newPerson->setSalery(convertedCostDesignerSal);));

        //Editor's Info
        QString editorAge = tempProjectHolder.at(23);
        int convertedEditorAge = editorAge.toInt();
        QString editorContactInfo = tempProjectHolder.at(24);
        QString editorName = tempProjectHolder.at(25);
        QString editorSalery = tempProjectHolder.at(26);
        int convertedEditorSal = editorSalery.toFloat();

        newProject->setCrew(setNewCrew->setEditor(newPerson->setAge(convertedEditorAge)));
        newProject->setCrew(setNewCrew->setEditor(newPerson->setContactInfo(editorContactInfo);));
        newProject->setCrew(setNewCrew->setEditor(newPerson->setName(editorName);));
        newProject->setCrew(setNewCrew->setEditor(newPerson->setSalery(convertedEditorSal);));

        //Production Designer's Info
        QString proDesignerAge = tempProjectHolder.at(27);
        int convertedProDesignerAge = proDesignerAge.toInt();
        QString proDesignerContactInfo = tempProjectHolder.at(28);
        QString proDesignerName = tempProjectHolder.at(29);
        QString proDesignerSalery = tempProjectHolder.at(30);
        int convertedProDesignerSal = proDesignerSalery.toFloat();

        newProject->setCrew(setNewCrew->setProductionDesigner(newPerson->setAge(convertedProDesignerAge)));
        newProject->setCrew(setNewCrew->setProductionDesigner(newPerson->setContactInfo(proDesignerContactInfo);));
        newProject->setCrew(setNewCrew->setProductionDesigner(newPerson->setName(proDesignerName);));
        newProject->setCrew(setNewCrew->setProductionDesigner(newPerson->setSalery(convertedProDesignerSal);));

        //Set Decorator's Info
        projects[i]->setCrew(crew::setSetDecorator(person::setAge(tempProjectHolder.at(31))));
        projects[i]->setCrew(crew::setSetDecorator(person::setContactInfo(tempProjectHolder.at(32))));
        projects[i]->setCrew(crew::setSetDecorator(person::setName(tempProjectHolder.at(33))));
        projects[i]->setCrew(crew::setSetDecorator(person::setSalery(tempProjectHolder.at(34))));

        projects[i]->setListOfFilmingLocations(tempProjectHolder.at(35));
        projects[i]->setCrew(crew::setCast(tempProjectHolder.at(36));

                //Cast Info
                save << projects[i]->getCrew().getCast()[i].getAge() << " ";
                save << projects[i]->getCrew().getCast()[i].getContactInfo() << " ";
                save << projects[i]->getCrew().getCast()[i].getName() << " ";
                save << projects[i]->getCrew().getCast()[i].getSalery() << " ";
        projects[i]->setListOfKeywords(tempProjectHolder.at(37));

    }

    myFile.close();
    //close file
}
