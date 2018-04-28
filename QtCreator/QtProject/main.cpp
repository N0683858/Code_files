#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QDebug>


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);

//    QWidget *mainWindow = new QWidget;
//    mainWindow->setWindowTitle("This is a window");

//    QSpinBox *spinner = new QSpinBox;
//    QSlider *slider = new QSlider(Qt::Horizontal);
//    spinner->setRange(1,50);
//    slider->setRange(1,50);

//    QObject::connect(spinner, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
//    QObject::connect(slider, SIGNAL(valueChanged(int)), spinner, SLOT(setValue(int)));

//    spinner->setValue(10);

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(slider);
//    layout->addWidget(spinner);
//    mainWindow->setLayout(layout);
//    mainWindow->show();


//    return a.exec();

    QString str = "My Name,Is:Hoga\tBoga\nand,what:you\tgona\n";
    int z = str.indexOf("\t");
    QString substr = str.section(QRegExp("\\s+"), 0, 0, QString::SectionSkipEmpty);
    QStringRef substr2(&str, 0, str.indexOf("\n"));
    //QStringList substrList = substr2.split(QRegExp("\\s+"),QString::SkipEmptyParts);
    QStringList fullLine = str.split(QRegExp("(\\,|\\:|\\t|\\n)"),QString::SkipEmptyParts);

    qDebug() << fullLine.at(0);
}
