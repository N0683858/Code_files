#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "project.h"
#include "projectreleased.h"
#include "projectnowplaying.h"
#include "projectunreleased.h"
#include "dvd.h"
#include "dvddoublesided.h"
#include "dvdsinglesided.h"
#include "vhs.h"
#include "combobox.h"
#include "bluray.h"

/*
    MainWindow constructors and deconstructors

*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
  -----------------------------------------------
  |  Title    : Home tab
  |  Purporse : Acts as home tab for project
  |  Qobjects :
  |             - updateButton
  |
  |
  ------------------------------------------------
*/
void MainWindow::on_updateButton_clicked()
{
    //clear current list
    ui->releasedProjectsList->clear();

    QStringList releasedProjectTitles;//all titles of released projects
    QStringList projectTitles;//all titles of projects

    //get all projects
    vector<project*> projects = database.getProjectList();

    for(size_t x = 0; x < projects.size(); x++){
        //check if project is released
        if(dynamic_cast<projectReleased*>(projects[x])){
            //add released project title to list
            releasedProjectTitles.append(QString::fromStdString("#" + projects[x]->getId() + string(": ") + projects[x]->getTitle()));
        }
        projectTitles.append(QString::fromStdString("#" + projects[x]->getId() + string(": ") + projects[x]->getTitle()));
    }

    //testing
    releasedProjectTitles << "#35: apple";
    releasedProjectTitles << "#77: pear";
    projectTitles << "#35: apple";
    projectTitles << "#77: pear";
    projectTitles << "#55: orange";

    //add list
    ui->releasedProjectsList->addItems(releasedProjectTitles);
    ui->EditProjectList->addItems(projectTitles);
}


/*
  -----------------------------------------------
  |  Title      : Create Project tab
  |  Purporse   : Acts as home tab for project
  |  UI objects :
  |                 - addProjectBtn
  |                 - dateEditRelease
  |                 - radioPlaying
  |                 - radioReleased
  |                 - radioUnreleased
  |                 - textCast
  |                 - textCostumeDesigner
  |                 - textDirector
  |                 - textEditor
  |                 - textFilmingLocationsList
  |                 - textGenre
  |                 - textKeywords
  |                 - textLanguage
  |                 - textProducer
  |                 - textProductionDesigner
  |                 - textRunTime
  |                 - textSetDecorator
  |                 - textSummary
  |                 - textTitle
  |                 - textWriter
  |
  |
  ------------------------------------------------
*/
void MainWindow::on_radioUnreleased_toggled(bool checked)
{
    if(checked){
        displayTicketSale(0);
    }
}

void MainWindow::on_radioReleased_toggled(bool checked)
{
    if(checked){
        displayTicketSale(1);
    }

}

void MainWindow::on_radioPlaying_toggled(bool checked)
{
    if(checked){
        displayTicketSale(1);
    }
}

void MainWindow::displayTicketSale(bool display)
{
    if(display && !ui->dateEditSale->isVisible()){
        ui->dateEditSale->setVisible(1);
        ui->ticketSaleLBL->setVisible(1);
    }else if(!display && ui->dateEditSale->isVisible()){
        ui->dateEditSale->setVisible(0);
        ui->ticketSaleLBL->setVisible(0);
    }
}


void MainWindow::on_addProjectBtn_clicked()
{
    project *projectToAdd;

    //retreval of infomation
    string title = (ui->textTitle->toPlainText().toStdString());
    string genre = (ui->textGenre->toPlainText().toStdString());
    string runTime = (ui->textRunTime->toPlainText().toStdString());
    string mainLaunguage = (ui->textLanguage->toPlainText().toStdString());
    string summary = (ui->textSummary->toPlainText().toStdString());
    string releaseDate = (ui->dateEditRelease->text().toStdString());
    string producer = (ui->textProducer->toPlainText().toStdString());
    string director = (ui->textDirector->toPlainText().toStdString());
    string writer = (ui->textWriter->toPlainText().toStdString());
    string costumeDesigner = (ui->textCostumeDesigner->toPlainText().toStdString());
    string editor = (ui->textEditor->toPlainText().toStdString());
    string productionDesigner = (ui->textProducitonDesigner->toPlainText().toStdString());
    string setDecorator = (ui->textSetDecorator->toPlainText()).toUtf8().constData();
    string filmingLocationList = (ui->textFilmingLocationsList->toPlainText().toStdString());
    string castList = (ui->textCast->toPlainText().toStdString());
    string keywordsList = ui->textKeywords->toPlainText().toStdString();
    string weeklyTicketSale = ui->dateEditSale->text().toStdString();

    //validation
    project* addProject = validateProject(
                title,genre,runTime,mainLaunguage,summary,releaseDate,producer,director,writer,costumeDesigner,
                editor,productionDesigner,setDecorator,filmingLocationList,castList,keywordsList,weeklyTicketSale,
                projectToAdd);

    //add project to database
    if(addProject != NULL){
        database.addProject(projectToAdd);
    }
}

/*
  -----------------------------------------------
  |  Title      : Edit tab
  |  Purporse   : Edit exsisting projects
  |  UI objects :
  |               - EditProjectList
  |               - dateEditRelease_2
  |               - finalizedEditButton
  |               - radioPlaying_Edit
  |               - radioReleased_Edit
  |               - radioUnreleased_Edit
  |               - textCastList_Edit
  |               - textCostumeDesigner_Edit
  |               - textDirector_Edit
  |               - textEditor_Edit
  |               - textFilmLocationList_Edit
  |               - textGenre_Edit
  |               - textKeywordsList_Edit
  |               - textMainLanguage_Edit
  |               - textProducer_Edit
  |               - textProductionDesigner_Edit
  |               - textRunTime_edit
  |               - textSetDecorator_Edit
  |               - textSummary_Edit
  |               - textTitle_Edit
  |               - textWriter_Edit
  |               - dateEditSale_Edit
  |               - ticketSaleLBL_Edit
  |
  |
  |
  ------------------------------------------------
*/


//TODO MAKE A WAY TO CHANGE PERSON PROPERTIES FOR PROJECT CREW

void MainWindow::on_finalizedEditButton_clicked()
{
    project *projectToAdd;

    //retreval of infomation
    string title = (ui->textTitle_Edit->toPlainText().toStdString());
    string genre = (ui->textGenre_Edit->toPlainText().toStdString());
    string runTime = (ui->textRunTime_Edit->toPlainText().toStdString());
    string mainLaunguage = (ui->textMainLanguage_Edit->toPlainText().toStdString());
    string summary = (ui->textSummary_Edit->toPlainText().toStdString());
    string releaseDate = (ui->dateEditRelease_2->text().toStdString());
    string producer = (ui->textProducer_Edit->toPlainText().toStdString());
    string director = (ui->textDirector_Edit->toPlainText().toStdString());
    string writer = (ui->textWriter_Edit->toPlainText().toStdString());
    string costumeDesigner = (ui->textCostumeDesigner_Edit->toPlainText().toStdString());
    string editor = (ui->textEditor_Edit->toPlainText().toStdString());
    string productionDesigner = (ui->textProductionDesigner_Edit->toPlainText().toStdString());
    string setDecorator = (ui->textSetDecorator_Edit->toPlainText()).toUtf8().constData();
    string filmingLocationList = (ui->textFilmLocationList_Edit->toPlainText().toStdString());
    string castList = (ui->textCastList_Edit->toPlainText().toStdString());
    string keywordsList = ui->textKeywordsList_Edit->toPlainText().toStdString();
    string weeklyTicketSale = ui->dateEditSale_Edit->text().toStdString();

    //validation
    project* addProject = validateProject(
                title,genre,runTime,mainLaunguage,summary,releaseDate,producer,director,writer,costumeDesigner,
                editor,productionDesigner,setDecorator,filmingLocationList,castList,keywordsList,weeklyTicketSale,
                projectToAdd);

    //add project to database
    if(addProject != NULL){
        database.addProject(addProject);
    }
}

void MainWindow::on_EditProjectList_activated(const QString &arg1)
{
    //find id from qstring
    string selectedProject = arg1.toUtf8().constData();
    int projectId = stoi(selectedProject.substr(1,selectedProject.length() - selectedProject.find(':')));

    //get project
    project* projectInfo = database.getProject(projectId);

    //set all info according to project info
    ui->textTitle_Edit->setText(QString::fromStdString(projectInfo->getTitle()));
    ui->textGenre_Edit->setText(QString::fromStdString(projectInfo->getGenre()));
    ui->textMainLanguage_Edit->setText(QString::fromStdString(projectInfo->getMainLanguage()));
    ui->textRunTime_Edit->setText(QString::fromStdString(projectInfo->getRuntime()));

    //set crew
    ui->textCostumeDesigner_Edit->setText(QString::fromStdString(projectInfo->getCrew().getCostumeDesigner().getName()));
    ui->textDirector_Edit->setText(QString::fromStdString(projectInfo->getCrew().getDirector().getName()));
    ui->textProductionDesigner_Edit->setText(QString::fromStdString(projectInfo->getCrew().getProductionDesigner().getName()));
    ui->textSetDecorator_Edit->setText(QString::fromStdString(projectInfo->getCrew().getSetDecorator().getName()));
    ui->textWriter_Edit->setText(QString::fromStdString(projectInfo->getCrew().getWriter().getName()));
    ui->textProducer_Edit->setText(QString::fromStdString(projectInfo->getCrew().getProducer().getName()));

    //lists
    /*
    ui->textKeywordsList_Edit->setText(QString::fromStdString(projectInfo->getListOfKeywords()));
    ui->textFilmLocationList_Edit->setText(QString::fromStdString(projectInfo->getListOfFilmingLocations()));
    ui->textCastList_Edit->setText(QString::fromStdString(projectInfo->getCrew().cast));
    */
}

void MainWindow::on_radioReleased_Edit_toggled(bool checked)
{
    if(checked){
        displayTicketSale_Edit(1);
    }
}

void MainWindow::on_radioPlaying_Edit_toggled(bool checked)
{
    if(checked){
        displayTicketSale_Edit(1);
    }
}

void MainWindow::on_radioUnreleased_Edit_toggled(bool checked)
{
    if(checked){
        displayTicketSale_Edit(0);
    }
}

void MainWindow::displayTicketSale_Edit(bool display)
{
    if(display && !ui->dateEditSale_Edit->isVisible()){
        ui->dateEditSale_Edit->setVisible(1);
        ui->ticketSaleLBL_Edit->setVisible(1);
    }else if(!display && ui->dateEditSale_Edit->isVisible()){
        ui->dateEditSale_Edit->setVisible(0);
        ui->ticketSaleLBL_Edit->setVisible(0);
    }
}
/*
  -----------------------------------------------
  |  Title      : Add Materials tab
  |  Purporse   : Add mateials to release project types
  |  UI objects :
  |              DVDframe
  |              DoubleDVDframe
  |              comboboxFrame
  |
  |              dvdToggle
  |              doubleDVDtoggle
  |              vhsToggle
  |              blurayToggle
  |              comboboxToggle
  |
  |
  |
  |
  |
  |
  |
  ------------------------------------------------
*/
void MainWindow::displayDVDframe(bool display)
{
    if(display && !ui->DVDframe->isVisible()){
        ui->DVDframe->setVisible(1);
    }else if(!display && ui->DVDframe->isVisible()){
        ui->DVDframe->setVisible(0);
    }
}

void MainWindow::displayDoubleDVDframe(bool display)
{
    if(display && !ui->DoubleDVDframe->isVisible()){
        ui->DoubleDVDframe->setVisible(1);
    }else if(!display && ui->DoubleDVDframe->isVisible()){
        ui->DoubleDVDframe->setVisible(0);
    }
}

void MainWindow::displayComboboxFrame(bool display)
{
    if(display && !ui->comboboxFrame->isVisible()){
        ui->comboboxFrame->setVisible(1);
    }else if(!display && ui->comboboxFrame->isVisible()){
        ui->comboboxFrame->setVisible(0);
    }
}

void MainWindow::on_dvdToggle_toggled(bool checked)
{
    if(checked){
        displayComboboxFrame(0);
        displayDoubleDVDframe(0);
        displayDVDframe(1);
    }
}

void MainWindow::on_doubleDVDtoggle_toggled(bool checked)
{
    if(checked){
        displayComboboxFrame(0);
        displayDoubleDVDframe(1);
        displayDVDframe(1);
    }
}

void MainWindow::on_vhsToggle_toggled(bool checked)
{
    if(checked){
        displayComboboxFrame(0);
        displayDoubleDVDframe(0);
        displayDVDframe(0);
    }
}

void MainWindow::on_blurayToggle_toggled(bool checked)
{
    if(checked){
        displayComboboxFrame(0);
        displayDoubleDVDframe(0);
        displayDVDframe(1);
    }
}

void MainWindow::on_comboboxToggle_toggled(bool checked)
{
    if(checked){
        displayComboboxFrame(1);
        displayDoubleDVDframe(0);
        displayDVDframe(1);
    }
}

void MainWindow::on_addMaterialButton_clicked()
{
    string errorString = "";
    //validate all input of material page
        //validation
        //...
        //...

    material* m;

    //create material add infomation using created constructor
    if(ui->dvdToggle->isChecked()){
        m = new dvdSingleSided();
    }else if(ui->doubleDVDtoggle->isChecked()){
        m = new dvdDoubleSided();
    }else if(ui->vhsToggle->isChecked()){
        m = new vhs();
    }else if(ui->comboboxToggle->isChecked()){
        m = new comboBox();
    }else if(ui->blurayToggle->isChecked()){
        m = new bluRay();
    }else{
        errorString += "Material type not chosen. ";
    }

    if(errorString == ""){
        //get project released
            //todo get propper pr
        projectReleased *pr;

        //add material
        pr->addMaterial(m);

        //add to db
        database.addProject(pr);
    }else{
        //display errorString

    }
}

void MainWindow::on_addMaterialBtn_clicked()
{
    //get selected project
    projectReleased* selectedProject;

    //get material infomation
    string title;
    string price;
    string frameAspect;
    string mainLanguage;
    string packagingSize;

    //get list stuff depending on material type


    //validate materials


    //create material and add properties
    material* materialToAdd;

    //add material
    selectedProject->getListOfMaterials().push_back(materialToAdd);
}

/*
  -----------------------------------------------
  |  Title      : Browse tab
  |  Purporse   : Catalog browsing
  |  UI objects :
  |
  |               - searchByTitle
  |               - searchByActor
  |               - searchByGenre
  |               - searchByDirector
  |               -
  |               -
  |               -
  |               -
  |               -
  |
  |
  ------------------------------------------------
*/
void MainWindow::on_searchByTitle_clicked()
{

}

void MainWindow::on_searchByActor_clicked()
{

}

void MainWindow::on_searchByGenre_clicked()
{

}

void MainWindow::on_searchByDirector_clicked()
{

}



/*
  -----------------------------------------------
  |  Title      : Maintanence tab
  |  Purporse   : maintanence console
  |  UI objects :
  |
  |
  |
  ------------------------------------------------
*/




/*
  -----------------------------------------------
  |  Title      : multiPurpose functions
  |  Purporse   : various
  |  UI objects : none
  |
  |
  |
  ------------------------------------------------
*/
project* MainWindow::validateProject(string title, string genre, string runTime, string mainLanguage, string summary,
                     string releaseDate, string producer, string director, string writer, string costumeDesigner,
                     string editor, string productionDesigner, string setDecorator, string filmingLocationList,
                     string castList, string keywordsList, string weeklyTicketSale,project*& projectToAdd){

    string errorString = "";

    //determine type of project
    if(ui->radioReleased->isChecked()){
        projectToAdd = new projectReleased();
    }else if(ui->radioPlaying->isChecked()){
        projectToAdd = new projectNowPlaying();
    }else if(ui->radioUnreleased->isChecked()){
        projectToAdd = new projectUnreleased();
    }else{
        errorString += "No project type selected. ";
    }

    //validation!
    if(title.length() < 1 || title.length() > 20){
        errorString += "Title too long/short";
    }


    if(errorString != ""){
        //display error string


        //return null
        return NULL;
    }else{
        //createProjectToAdd
        if(dynamic_cast<projectReleased*>(projectToAdd)){
            dynamic_cast<projectReleased*>(projectToAdd)->setWeeklyTicketSale(weeklyTicketSale);
        }
        projectToAdd->setTitle(title);
        projectToAdd->setGenre(genre);
        projectToAdd->setRuntime(runTime);
        projectToAdd->setMainLanguage(mainLanguage);
        projectToAdd->setSummary(summary);
        projectToAdd->setReleaseDate(releaseDate);
        projectToAdd->getCrew().setProducer(person(producer));
        projectToAdd->getCrew().setDirector(person(director));
        projectToAdd->getCrew().setWriter(person(writer));
        projectToAdd->getCrew().setCostumeDesigner(person(costumeDesigner));
        projectToAdd->getCrew().setEditor(person(editor));
        projectToAdd->getCrew().setProductionDesigner(person(productionDesigner));
        projectToAdd->getCrew().setSetDecorator(person(setDecorator));
        projectToAdd->setListOfFilmingLocations(filmingLocationList);
        projectToAdd->setListOfKeywords(keywordsList);
        //need to add cast
    }

    return projectToAdd;
}












