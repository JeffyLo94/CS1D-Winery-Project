#include "mainwindow.h"


void MainWindow::on_pushButton__clicked()
{
    ui->list_customTrip->clear();

    for(int i = 0; i < wineryList.size(); i++)
    {
        ui->list_customTrip->addItem(returnAllData(i));
    }

    ui->planATrip->hide();
    ui->page_customTrip->show();
}

void MainWindow::CreateDistanceVectorTrip(vector < vector<double> > & someVec)
{
    int wineryIndex;
    int distanceIndex;
    vector<double>* tempDistanceVector;
    vector< vector<double> > distanceVector;

    //First Vector: Villa Canyon
    tempDistanceVector = new vector<double>;
    //From Canyon Villa Distance to Canyon Villa Distance is 0 miles
    tempDistanceVector->push_back(0);

    //Push distance to Villa to the first vector in the vector of vector
    for(distanceIndex = 0; distanceIndex < wineryList.size(); distanceIndex++)
    {
        tempDistanceVector->push_back(wineryList.at(distanceIndex).getVillaDistance().toDouble());
    }

    distanceVector.push_back(*tempDistanceVector);

    //Outter For list: Create a distance list of each winery and push to the
    //  outter vector

    for(wineryIndex = 0; wineryIndex < wineryList.size(); wineryIndex++)
    {
       tempDistanceVector = new vector<double>;
       tempDistanceVector->push_back(wineryList.at(wineryIndex).getWineryId().toInt());

       for(distanceIndex = 0; distanceIndex < wineryList.size(); distanceIndex++)
       {
           tempDistanceVector->push_back(wineryList.at(wineryIndex).getDistances()->at(distanceIndex));
       }

       distanceVector.push_back(*tempDistanceVector);
    }

    someVec = distanceVector;
}

void MainWindow::on_pushButton_next_clicked()
{
    QModelIndexList listIndeces = ui->list_customTrip->selectionModel()->selectedIndexes();
    int rowIndex                = ui->list_customTrip->currentRow();
    vector<int> newList;
    vector < vector<double> > distanceVec;
    double distance;
    QString distanceString;
    vector<Winery> selectedWineriesList;

    int i;
    newList.push_back(0);

    if(rowIndex != -1)
    {

            for(int numRows = 0; numRows < listIndeces.count(); numRows++)
            {
                 i = 0;

                //Checks to see if the item was selected in the list
                while(ui->list_customTrip->item(listIndeces[numRows].row())->text() != returnAllData(i) && i < wineryList.size())
                {
                    i++;
                }
                if(i < wineryList.size())
                {    //This is the vector that you will be using
                    //It is currently using "i + 1" because you mentioned your algorithm started counting at 1 (0 is reserved for the villa)
                    //You can do you operations in this same method definition but down there
                    //
                    newList.push_back(i+1);

                }
                //For testing purposes
    //            for(vector<int>::iterator it = newList.begin(); it != newList.end(); ++it)
    //            {
    //                qDebug() << "INDECES: " << *it <<endl;
    //            }
            }

            sort(newList.begin(), newList.end());



            //Here is a good place to implement your algorithm

            CreateDistanceVectorTrip(distanceVec);





           if(newList.size() > 2)
           {
               qDebug() << "Before Shortest" << endl;
                distance = shortest(distanceVec, newList);
                qDebug() << "After Shortest" << endl;

                //Create a new list for shopping cart
                selectedWineriesList = CreateSelectedWineryList(newList);
                shoppingCart.setList(selectedWineriesList);
                shoppingCart.fillAllLists();

                distanceString = QString::number(distance);

                int temp;
                for(vector<int>::iterator it = newList.begin(); it != newList.end(); ++it)
                {
                    temp = *it;
//                    qDebug() << "Temp " << temp << endl;
                    if(temp != 0)
                    {
                        ui->list_FinalListCustomTrip->addItem(returnAllData(temp-1));
                    }
                }
           }
           else
           {

               float temp;

               distanceString = wineryList.at(newList.at(1)-1).getVillaDistance();

               temp = distanceString.toFloat();
               temp *= 2;

               distanceString = QString::number(temp);

               ui->list_FinalListCustomTrip->addItem(returnAllData(newList.at(1)-1));

           }

            qDebug() << "Please work" << endl;
            ui->distanceCustomFinal->setText(distanceString);
            ui->page_customTrip->hide();
            ui->page_customTrip_final->show();

    }    //
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please select a winery");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::on_pushButton_shortestTrip_next_clicked()
{

    QString num = ui->lineEdit_numberOfWineries->text();

    int number = num.toInt();

    if(number <= 0 || number > wineryList.size())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please enter a number between 1 and " + QString::number(wineryList.size()));
        messageBox.setFixedSize(500,200);

        ui->lineEdit_numberOfWineries->clear();
    }
    else
    {
       ui->page_shortestTrip->hide();
       ui->page_shortestTripPage2->show();

       ui->list_customTripPage2->clear();
       for(int i = 0; i < wineryList.size(); i++)
       {
           ui->list_customTripPage2->addItem(returnAllData(i));
       }

       amountToVisit = number;

       ui->page_shortestTrip->hide();
       ui->page_shortestTripPage2->show();
       ui->lineEdit_numberOfWineries->clear();
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    int index = ui->list_customTripPage2->currentRow();
    vector< vector<double> > distanceVec;
    vector<Winery> selectedWineriesList;
    double distance;
    QString stringDistance;
    vector<int> intVector;
    QString temp;
    float tempFloat;
    int i = 1;

    qDebug() << "&&&&&& "<< endl;

    CreateDistanceVectorTrip(distanceVec);

    qDebug() << "********** "<< endl;

    beginningWinery = index;

        if(index != -1)
        {

           distance = shortestTripAlgorithm(distanceVec, intVector, beginningWinery +1, amountToVisit);
           stringDistance = QString::number(distance);
           ui->distanceShortestTrip->setText(stringDistance);


           //Create a new list for shopping cart
           selectedWineriesList = CreateSelectedWineryList(intVector);
           shoppingCart.setList(selectedWineriesList);
           shoppingCart.fillAllLists();


           for(vector<int>::iterator it = intVector.begin(); it != intVector.end(); ++it)
           {
               if((*it) > 0)
               {
                   ui->list_finalListShortestTrip->addItem (returnAllData((*it)-1));

               }
           }

           qDebug() << "Reached here";
           ui->page_shortestTripPage2->hide();
           ui->page_shortestTripPage3->show();

        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Please select a winery");
            messageBox.setFixedSize(500,200);
        }
}


void MainWindow::on_pushButton_15_clicked()
{
   ui->page_shortestTripPage3->hide();
   ui->planATrip->show();
   ui->list_finalListShortestTrip->clear();
}

void MainWindow::on_pushButton_6_clicked()
{

 shoppingCart.show();

}

void MainWindow::on_push_button_customTrip_Done_clicked()
{
    ui->page_customTrip_final->hide();
    ui->planATrip->show();
    ui->list_FinalListCustomTrip->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    shoppingCart.show();
}


//Visit All!!!!!!!!
void MainWindow::on_pushButton_visitAll_clicked()
{
    vector< vector<double> > distanceVec;
    vector< int > intVector;
    int temp;
    double distance;
    QString stringDistance;


    intVector.push_back(0);

    for(int i = 0; i < wineryList.size(); i++)
    {
     intVector.push_back(i+1);
    }

    CreateDistanceVectorTrip(distanceVec);


    distance = shortest(distanceVec, intVector);


    stringDistance = QString::number(distance);

    ui->label_distance_VisitAll->setText(stringDistance);

    for(vector<int>::iterator it = intVector.begin(); it != intVector.end(); ++it)
    {
        temp = *it;
        qDebug() << "Temp " << temp << endl;
        if(temp > 0)
        {    ui->list_visitAll->addItem(returnAllData(temp-1));
        }
    }

    shoppingCart.setList(wineryList);
    shoppingCart.fillAllLists();
    ui->planATrip->hide();
    ui->page_finalVisitAll->show();
}

void MainWindow::on_pushButton_16_clicked()
{
 shoppingCart.show();
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->page_finalVisitAll->hide();
    ui->planATrip->show();
    ui->list_visitAll->clear();
}

vector<Winery> MainWindow::CreateSelectedWineryList(const vector<int>& IDList)
{
    vector<Winery> selectedWineryList;
    int index;
    Winery newWinery;

    for(index = 0; index < IDList.size(); index++)
    {
        qDebug() << "Index is: " << index;
        if(IDList.at(index) - 1 != -1)
        {
            newWinery = wineryList.at(IDList.at(index) - 1);
            qDebug() << newWinery.getName();
            selectedWineryList.push_back(newWinery);
        }
    }

    qDebug() << "Return from for";

    return selectedWineryList;
}

