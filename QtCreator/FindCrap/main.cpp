#include "findcrap.h"
#include <QApplication>

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <vector>

void Write(QString fileName);

void Read(QString fileName);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    FindCrap w;
//    w.show();

    Write("TextFile.txt");
    Read("TextFile.txt");

    return a.exec();
}

void Write(QString fileName)
{
    QFile myFile(fileName);

    if(!myFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug() << "The file could not open";
        return;
    }

    QTextStream writing (&myFile);
    for(int i = 0; i < 5; i++)
    {
        writing << "HEllo" << " ";
        writing << "WorlD" << " ";
        writing << "!" << " " << i  << "\n";
    }

    myFile.close();
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

    //while(!reading.atEnd())
    for(int i = 0; i < 5; i++)
    {
        QString myText = reading.readLine();

        QRegExp rx("[, \n]"); // match a comma or a space
        QStringList list = myText.split(rx, QString::SkipEmptyParts);
       // for(int x = 0; x < list.size(); x++)
       // {
            qDebug() << list.at(0);
            qDebug() << list.at(1);
            qDebug() << list.at(2);
            qDebug() << list.at(3);
       // }
//        myText.remove(',');
//        qDebug()<<myText;

//        auto commaFree = myText.split(',');
//        qDebug() << commaFree;
    }

    myFile.close();
}
