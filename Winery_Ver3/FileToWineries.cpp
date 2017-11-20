#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Winery.h"
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QRegExp>
#include <QDebug>

void MainWindow::FileToWinery(){
    QString fileName = "wineries.txt";
    QFile inFile(fileName);
    QTextStream in(&inFile);
    if(!inFile.open(QIODevice::ReadOnly)){
        QString msg = fileName.append(" has failed to load");
        QMessageBox::information(0,"Critical Failure", msg);
    }

     Winery * entry;
     Wine   * temp;

     entry = new Winery;

    while (!in.atEnd())
    {
        //Reading Winery Name
        QString line = in.readLine();
        qDebug() << line << endl;
        line.remove(QRegExp(".*: ", Qt::CaseInsensitive	, QRegExp::RegExp));
        entry->setName(line);
//        qDebug() << line << endl;

        //Reading Winery Number
        line = in.readLine();
        line.remove(QRegExp("winery number ", Qt::CaseInsensitive	, QRegExp::RegExp));
        entry->setWineryId(line.toInt());
//        qDebug() << line << endl;

        //Reading number of wineries
        line = in.readLine();
        line.remove(QRegExp(".*- ", Qt::CaseInsensitive	, QRegExp::RegExp));
        int numDistances = line.toInt();
//        qDebug() << line << endl;

        //Reading distances to other wineries
        for(int i = 0; i<numDistances; i++){
            line = in.readLine();
            entry->addToWineryDistance(line.split(" ")[1].toDouble());
//            qDebug() << line.split(" ")[1].toDouble()<< endl;
        }

        //Reading Distance to Villa
        line = in.readLine();
        entry->setToVillaDistance(line.split(" ")[0].toDouble());
//        qDebug() << line << endl;

        //Reading number of wine products
        line = in.readLine();
        int numWines = line.split(" ")[0].toInt();
        for(int i = 0; i < numWines; i++){
            //Reading Wine Name

            temp = new Wine;
            line = in.readLine();
            temp->setName(line);
//            qDebug() << line << endl;

            //Reading Wine Year
            line = in.readLine();
            temp->setYear(line.toInt());
//            qDebug() << line << endl;

            //Reading Wine Price
            line = in.readLine();
            temp->setPrice(line.toDouble());
//            qDebug() << line << endl;

            entry->addWineProduct(*temp);
        }

        //Reading in White Space
        line = in.readLine();


        wineryList.push_back(*entry);


        entry = new Winery;
    }
    inFile.close();
}
