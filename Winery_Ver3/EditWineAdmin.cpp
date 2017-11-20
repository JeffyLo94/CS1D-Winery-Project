#include "mainwindow.h"
#include "Winery.h"

void MainWindow::on_pushButton_editWine_wineOptions_clicked()
{
    ui->page_wineOptionsAdmin->hide();
    ui->page_editWine_wineOptionsAdmin->show();

    QStringList list;

    //Clear The Combo Box but left --Select Winery--
    int numberOfItem = ui->comboBox_selectWinery_editWine->count();
    for(int i = 1; i < numberOfItem; i++)
    {
        ui->comboBox_selectWinery_editWine->removeItem(1);
        qDebug() << "Remove Item";
    }

    qDebug() <<"After removeItem";

    //If select winery is already in the combo box -> no need to add a new one
    if(ui->comboBox_selectWinery_editWine->count() == 0)
    {
        list << "--Select Winery--";
    }

    //Adds items to combo box
    for(int i = 0; i<wineryList.size();i++){
        list << wineryList.at(i).getName();
    }
    ui->comboBox_selectWinery_editWine->addItems(list);
    ui->comboBox_selectWinery_editWine->setCurrentIndex(0);

    //Connects combobox interaction w/ table widget
    connect(ui->comboBox_selectWinery_editWine, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_comboBox_selectWinery_editWine_currentIndexChanged(int)) );

    //Creates table widget layout
    ui->tableWidget_editWine->setColumnCount(3);
    ui->tableWidget_editWine->setHorizontalHeaderItem(0,new QTableWidgetItem("Wine Name"));
    ui->tableWidget_editWine->setHorizontalHeaderItem(1,new QTableWidgetItem("Wine Year"));
    ui->tableWidget_editWine->setHorizontalHeaderItem(2,new QTableWidgetItem("Wine Price"));
    ui->tableWidget_editWine->setColumnWidth(0, 329);
    ui->tableWidget_editWine->setColumnWidth(1, 100);
    ui->tableWidget_editWine->setColumnWidth(2, 100);
}

void MainWindow::on_comboBox_selectWinery_editWine_currentIndexChanged(int index)
{
    //Displays user selected winery's wines in the table
    if(index > 0)
    {
        int listIndex = index-1;

        int numWines = (wineryList.at(listIndex).getNumProducts()).toInt();

        //Takes in wine products for specifed winery
        vector<Wine>* temp = wineryList.at(listIndex).getWineProducts();

        //Propogates Table with wine info
        ui->tableWidget_editWine->setRowCount(numWines);
        for(int row = 0; row < numWines; row++){
            ui->tableWidget_editWine->setItem(row,0, new QTableWidgetItem(temp->at(row).getName()));
            ui->tableWidget_editWine->setItem(row,1, new QTableWidgetItem(temp->at(row).getYear()));
            ui->tableWidget_editWine->setItem(row,2, new QTableWidgetItem(temp->at(row).getPrice()));
        }//end for loop
    }
    else
    {
        ui->tableWidget_editWine->setRowCount(0);
    }
}

void MainWindow::on_pushButton__back_editWine_clicked()
{
    //Brings back previous page and hides current
    ui->tableWidget_editWine->clear();
    ui->page_editWine_wineOptionsAdmin->hide();
    ui->page_wineOptionsAdmin->show();
}

void MainWindow::on_pushButton_apply_editWine_clicked()
{
    bool checksPassed = false;
    QMessageBox* msg = new QMessageBox();
    int currYear = QDate::currentDate().year();

    //Gets user selected winery
    int wineryIndex = ui->comboBox_selectWinery_editWine->currentIndex();

    //Performs checks for user inputed information before adding wine as a product
    if(wineryIndex != 0){
        //gets current wine products in winery
        vector<Wine>* temp = wineryList.at(wineryIndex-1).getWineProducts();

        int totRows = ui->tableWidget_editWine->rowCount();
        //Reads in User inputed data and performs checks
        for(int row = 0; row < totRows; row++){
            QString name = ui->tableWidget_editWine->item(row, 0)->text();
            qDebug() << name;
            QString year = ui->tableWidget_editWine->item(row, 1)->text();
            qDebug() << year;
            QString price = ui->tableWidget_editWine->item(row, 2)->text();
            qDebug() << price;

            //Breaks out of loop and displays error message if an error is catched
            if(year.toInt() < 0){
                msg->setWindowTitle("Error - Year Invalid");
                msg->setText("Negative years are invalid");
                msg->show();
                checksPassed = false;
                break;
            }
            else if(year.toInt() > currYear ){
                msg->setWindowTitle("Error - Year Invalid");
                msg->setText("TIME TRAVELLER!/n Future year not allowed");
                msg->show();
                checksPassed = false;
                break;
            }
            else if(price.toDouble() < 0.0){
                msg->setWindowTitle("Error - Price Invalid");
                msg->setText("Negative Price is invalid");
                msg->show();
                checksPassed = false;
                break;
            }
            else{
                checksPassed = true;
            }
        }//End For Loop

        //Adds edited wine product into winery's vector of wine
        if(checksPassed){
            for(int row = 0; row < totRows; row++){
                QString name = ui->tableWidget_editWine->item(row, 0)->text();
                QString year = ui->tableWidget_editWine->item(row, 1)->text();
                QString price = ui->tableWidget_editWine->item(row, 2)->text();

                temp->at(row).setName(name);
                temp->at(row).setYear(year.toInt());
                temp->at(row).setPrice(price.toDouble());
            }
            msg->setWindowTitle("Success");
            msg->setText("Changes Sucessful");
            msg->show();

            //Adds new wine to shopping cart listings
            shoppingCart.setList(wineryList);
            shoppingCart.fillAllLists();
        }
    }
}
