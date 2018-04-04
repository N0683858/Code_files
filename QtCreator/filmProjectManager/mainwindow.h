#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataholder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_updateButton_clicked();

    void on_radioUnreleased_toggled(bool checked);

    void on_radioReleased_toggled(bool checked);

    void on_radioPlaying_toggled(bool checked);

    void on_dvdToggle_toggled(bool checked);

    void on_doubleDVDtoggle_toggled(bool checked);

    void on_vhsToggle_toggled(bool checked);

    void on_blurayToggle_toggled(bool checked);

    void on_comboboxToggle_toggled(bool checked);

    void displayTicketSale(bool display);//todo fix
    void displayTicketSale_Edit(bool display);//i realize this is bad practice (having two functions that allmost do the same thing)
    void displayDVDframe(bool);
    void displayDoubleDVDframe(bool);
    void displayComboboxFrame(bool);
    project* validateProject(string title, string genre, string runTime, string mainLanguage, string summary,
                         string releaseDate, string producer, string director, string writer, string costumeDesigner,
                         string editor, string productionDesigner, string setDecorator, string filmingLocationList,
                         string castList, string keywordsList, string weeklyTicketSale,project*& projectToAdd);


    void on_addMaterialButton_clicked();

    void on_addProjectBtn_clicked();

    void on_radioReleased_Edit_toggled(bool checked);

    void on_radioPlaying_Edit_toggled(bool checked);

    void on_radioUnreleased_Edit_toggled(bool checked);

    void on_EditProjectList_activated(const QString &arg1);

    void on_finalizedEditButton_clicked();

    void on_addMaterialBtn_clicked();

    void on_searchByTitle_clicked();

    void on_searchByActor_clicked();

    void on_searchByGenre_clicked();

    void on_searchByDirector_clicked();

private:
    Ui::MainWindow *ui;
    dataHolder database;
};

#endif // MAINWINDOW_H
