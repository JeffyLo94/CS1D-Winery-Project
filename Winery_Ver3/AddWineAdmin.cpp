#include "mainwindow.h"

void MainWindow::on_pushButton_addWine_wineOptions_clicked()
{
    //Brings up add wines page
    ui->page_wineOptionsAdmin->hide();
    ui->page_addWine_wineOptionsAdmin->show();

    //Filling Combo Box
    QStringList list;
    list << "--Select Winery--";
    for(int i = 0; i<wineryList.size();i++){
        list << wineryList.at(i).getName();
    }
    ui->comboBox_selectWinery_addWine->clear();
    ui->comboBox_selectWinery_addWine->addItems(list);

    // Connecting Signal and Slot
    connect(ui->comboBox_selectWinery_addWine, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_comboBox_selectWinery_addWine_currentIndexChanged(int)) );
}

void MainWindow::on_comboBox_selectWinery_addWine_currentIndexChanged(int index)
{
    //Slot method for index changed - only fills text browser if index is greater than 0
    if(index > 0){
        int listIndex = index - 1;
        ui->textBrowser_viewCurrent_addWine->clear();
        ui->textBrowser_viewCurrent_addWine->setPlainText(wineryList[listIndex].returnAllWineProduct());
    }
}

void MainWindow::on_pushButton_confirmAdd_addWine_clicked()
{
    bool checksPassed = false;
    bool nameCheckFail = false;
    QMessageBox* msg = new QMessageBox();
    int currYear = QDate::currentDate().year();

    //Gets the user specified index from combo box
    int currIndex = ui->comboBox_selectWinery_addWine->currentIndex();

    //Performs checks and displays window if invalid user input or notifies successful inputs
    if(currIndex != 0){
        currIndex = currIndex - 1;
        vector<Wine>* temp = wineryList.at(currIndex).getWineProducts();

        //Reads in user input
        QString name  = ui->lineEdit_wineName_addWine->text();
        qDebug() << name;
        QString year  = ui->lineEdit_wineYear_addWine->text();
        qDebug() << year;
        QString price = ui->lineEdit_winePrice_addWine->text();
        qDebug() << price;

        // Checks that input name is unique
        for(int i = 0; i < wineryList[currIndex].getNumProducts().toInt(); i++){
            if( temp->at(i).getName() == name ){
                nameCheckFail = true;
                qDebug() << "Failed Name Check";
            }
        }

        //Displays window messages and performs further checks
        if(nameCheckFail){
            msg->setWindowTitle("Error - Duplicate Wine");
            msg->setText("Input wine name: " + name + " already exists");
            msg->show();
        }
        //Checks input year is not negative
        else if(year.toInt() < 0){
            msg->setWindowTitle("Error - Year Invalid");
            msg->setText("Negative years are invalid");
            msg->show();
        }
        //Checks input year is not in the future
        else if(year.toInt() > currYear ){
            msg->setWindowTitle("Error - Year Invalid");
            msg->setText("TIME TRAVELLER!/n Future year not possible");
            msg->show();
        }
        //Checks price input is not negative
        else if(price.toDouble() < 0.0){
            msg->setWindowTitle("Error - Price Invalid");
            msg->setText("Negative Price is invalid");
            msg->show();
        }
        else{
            checksPassed = true;
        }

        //Adds wine to winery
        if(checksPassed){
            //Creating Wine Node
            Wine addedWine;
            addedWine.setName(name);
            addedWine.setYear(year.toInt());
            addedWine.setPrice(price.toDouble());

            //Adding Wine to Winery
            wineryList.at(currIndex).addWineProduct(addedWine);
            shoppingCart.setList(wineryList);
            shoppingCart.fillAllLists();

            //Success Window
            msg->setWindowTitle("Success");
            msg->setText("Wine Successfully Added");
            msg->show();

            //Clearing Text Fields
            ui->lineEdit_wineName_addWine->clear();
            ui->lineEdit_winePrice_addWine->clear();
            ui->lineEdit_wineYear_addWine->clear();

            //Refreshing Text Browser
            ui->textBrowser_viewCurrent_addWine->clear();
            ui->textBrowser_viewCurrent_addWine->setPlainText(wineryList[currIndex].returnAllWineProduct());
        }
    }
    //Displays error message if no winery selected
    else{
        msg->setWindowTitle("Error - Winery Not Found");
        msg->setText("Winery not selected");
        msg->show();
    }
}

void MainWindow::on_pushButton_back_addWine_clicked()
{
    //Brings up previous page
    ui->textBrowser_viewCurrent_addWine->clear();
    ui->page_addWine_wineOptionsAdmin->hide();
    ui->page_wineOptionsAdmin->show();
}
