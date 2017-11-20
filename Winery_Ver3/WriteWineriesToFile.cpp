#include "mainwindow.h"
#include "Winery.h"
#include "wine.h"
#include <QString>
#include <iomanip>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QDebug>

using namespace std;

void MainWindow::WriteToFile(vector<Winery>& wineryListPtr)
//void WriteToFile(vector<Winery>& wineryListPtr)
{
    const QString fileName = "wineries.txt";
    QFile outputFile(fileName);
    QTextStream output(&outputFile);

    if(!outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Cannot open file\n";
    }
    else
    {
        for(int index = 0; index < wineryListPtr.size(); index++)
        {
            output << "name of winery: " << (wineryListPtr.at(index)).getName() << endl;
            output << "winery number "   << (wineryListPtr.at(index)).getWineryId() << endl;
            output << "distance to other wineries - " << wineryListPtr.size() << endl;

            //Output distances to other wineries
            for(int i = 0; i < wineryListPtr.size(); i++)
            {
                output << i + 1 << " " << (wineryListPtr.at(index)).getDistance(i) << endl;
            }

            output << (wineryListPtr.at(index)).getVillaDistance();
            output << " miles to Canyon Villa\n";
            output << (wineryListPtr.at(index)).getNumProducts();
            output << " wines offered\n";

            //Output the wines info
            for(int i = 0; i < ((wineryListPtr.at(index)).getWineProducts())->size(); i++)
            {
                output << (((wineryListPtr.at(index)).getWineProducts())->at(i)).getName();
                output << endl;
                output << (((wineryListPtr.at(index)).getWineProducts())->at(i)).getYear();
                output << endl;
                output << (((wineryListPtr.at(index)).getWineProducts())->at(i)).getPrice();
                output << endl;
            }

            output << endl;
        }
        outputFile.close();
    }


}
