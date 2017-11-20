#include "mainwindow.h"

//void WriteToFile(vector<Winery>& wineryListPtr);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Canyon Villa Winery Tour");
    ui->mainMenu->show();
//    HelpWindow myHelp;

    //Initializization of attributes
    currentPassword    = "password";
    currentUsername    = "admin";
    adminAccessGranted = false;
    QFont titleFont;
    titleFont.setPointSize(14);

    //Setting fonts
    font.setPointSize(19);
    font.setBold(true);
    font2.setPointSize(13);
    font2.setItalic(true);
    font3.setPointSize(15);

    ui->label_17->setFont(titleFont);
    ui->label_18->setFont(titleFont);
    ui->label_16->setFont(titleFont);
    ui->distanceCustomFinal->setFont(titleFont);
    ui->label_distance_VisitAll->setFont(titleFont);
    ui->distanceShortestTrip->setFont(titleFont);
    ui->label_2->setFont(titleFont);
    ui->label_19->setFont(titleFont);
    ui->visitAllTitle->setFont(titleFont);
    ui->label_promptForWineries->setFont(font3);
    ui->thankYou->setFont(font3);
    ui->customTrip_title_1->setFont(titleFont);
    ui->label_CustomTrip_Title->setFont(titleFont);
    ui->title_1->setFont(titleFont);
    ui->label_Add_winery_title->setFont(font3);
    ui->label_CVLogoAdmin->setFont(font3);
    ui->label_Excellence->setFont(font2);
    ui->label_ViewListTitle->setFont(font3);
    ui->label_AboutVIllaTItle->setFont(font3);
    ui->label_featuredWines->setFont(font2);
    ui->label_temp->setFont(font2);

    ui->wineryList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->list_wineList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->list_currentWineries->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->listWidget_adminViewWIne->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->listWidget_adminViewWineries->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->list_customTrip->setSelectionMode(QAbstractItemView::MultiSelection);

//    ui->viewListOfWineries->set"background-image: url(:/Resources/guest.jpg)");
    ui->push_button_viewListOfWineries->setStyleSheet("color: black");
//    ui->graphicsView_viewLists

    QImage image(":/wineHeart.jpg");
    QImage image2(":/grapes.jpg");
    QImage image3(":/hotel3.jpg");
    QImage image4(":/hotelRoom.jpg");
    QImage image5(":/wineCellar.jpg");
    QImage image6(":/CanyonVilla.jpg");
    QImage image7(":/adelaidaCellars.jpg");

//    ui->label_20->setPixmap(QPixmap::fromImage(smallLogo));
    ui->label_planATrip->setPixmap(QPixmap::fromImage(image6));
    ui->label_planATrip->setScaledContents(true);
    ui->viewWines_2->setPixmap(QPixmap::fromImage(image5));
    ui->viewWines_2->setScaledContents(true);
    ui->label_picture->setPixmap(QPixmap::fromImage(image7));
    ui->label_picture->setScaledContents(true);
//    ui->myLabel->setPixmap(QPixmap::fromImage(image));
    ui->label_CVLogoAdmin->setPixmap(QPixmap::fromImage(image6));
    ui->label_CVLogoAdmin->setScaledContents(true);
    ui->label_CVLogoAdmin_2->setPixmap(QPixmap::fromImage(image6));
    ui->label_CVLogoAdmin_2->setScaledContents(true);
    ui->label_secondInViewList->setPixmap(QPixmap::fromImage(image2));
    ui->label_secondInViewList->setScaledContents(true);
    ui->label_AboutTheVilla->setPixmap(QPixmap::fromImage(image3));
    ui->label_AboutTheVilla->setScaledContents(true);
    ui->label_AboutVilla2->setPixmap(QPixmap::fromImage(image4));
    ui->label_AboutVilla2->setScaledContents(true);
    ui->label_AboutVilla3->setPixmap(QPixmap::fromImage(image5));
    ui->label_AboutVilla3->setScaledContents(true);
    ui->label_AdminLogin->setPixmap(QPixmap::fromImage(image6));
    ui->label_AdminLogin->setScaledContents(true);
    ui->label_mainTitle->setPixmap(QPixmap::fromImage(image6));
    ui->label_mainTitle->setScaledContents(true);
    ui->label_20->setPixmap(QPixmap::fromImage(image6));
    ui->label_20->setScaledContents(true);
    ui->label_titleAdminFunctions->setPixmap(QPixmap::fromImage(image6));
    ui->label_titleAdminFunctions->setScaledContents(true);
//    ui->label_tourWineries->setPixmap(QPixmap::fromImage(image6));
//    ui->label_tourWineries->setScaledContents(true);
    //QGraphicsScene * scene  = new QGraphicsScene();
//  QGraphicsPixmapItem * item = new QGraphicsPixmapItem(QPixmap::fromImage())

    FileToWinery();

    CreateDistanceVector();
    shoppingCart.setList(wineryList);
    shoppingCart.fillAllLists();
}

MainWindow::~MainWindow()
{
    WriteToFile(wineryList);
    delete ui;
}

void MainWindow::on_push_button_viewListOfWineries_clicked()
{
    ui->mainMenu->hide();

    ui->viewListOfWineries->show();
}

void MainWindow::on_pushButton_back_viewList_clicked()
{
    ui->viewListOfWineries->hide();
    ui->mainMenu->show();
    ui->list_wineList->clear();
}


void MainWindow::PropagateWineryList()
{

    WriteToFile(wineryList);

}

void MainWindow::on_pushButton_backPlanTrip_clicked()
{
    ui->planATrip->hide();
    ui->mainMenu->show();
}

void MainWindow::on_pushButton_planTrip_clicked()
{
    ui->mainMenu->hide();
    ui->planATrip->show();
}

void MainWindow::on_pushButton_backTourAndPurchase_clicked()
{
    ui->tourWineriesAndPurchase->hide();
    ui->mainMenu->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    //Back button in admin login window
    ui->adminLogin->hide();
    ui->mainMenu->show();
    ui->lineEdit_password->clear();
    ui->lineEdit_username->clear();
}

void MainWindow::on_pushButton_Admin_clicked()
{
    ui->mainMenu->hide();
    ui->adminLogin->show();
}

void MainWindow::on_pushButton_adminLogin_clicked()
{

   QString password = ui->lineEdit_password->text();
   QString username = ui->lineEdit_username->text();

   qDebug() << "Password: " << password;
   qDebug() << "Username : " << username;


   bool passwordCorrect            = password == currentPassword;
   bool usernameCorrect            = username == currentUsername;
   bool passwordAndUserNameCorrect = (password != currentPassword) ||
                                     (username != currentUsername);

   if(passwordAndUserNameCorrect)
   {
       QMessageBox::information(this, "Login Error", "Incorrect Username or Password");
       ui->lineEdit_password->clear();
       ui->lineEdit_username->clear();
   }

   else if(passwordCorrect && usernameCorrect)
   {
       QMessageBox::information(this, "Welcome", "Access granted");
       adminAccessGranted = true;


       ui->adminLogin->hide();
       ui->afterAdminLogin->show();
       ui->lineEdit_password->clear();
       ui->lineEdit_username->clear();
   }

}

void MainWindow::on_pushButton_adminLogout_clicked()
{
    adminAccessGranted = false;
    ui->afterAdminLogin->hide();
    ui->adminLogin->show();
}

void MainWindow::on_pushButton_tourAndPurchase_clicked()
{
    ui->mainMenu->hide();
    ui->tourWineriesAndPurchase->show();
}

\
QString MainWindow::returnAllData(int elementNumber)
{

    QString tempString;
    vector<Wine> temp(*(wineryList[elementNumber].getWineProducts()));

    tempString = '\n';
    tempString +=  "Name                     : " ;
    tempString += wineryList[elementNumber].getName();
    tempString += '\n';
    tempString += "Wine Id                   : ";
    tempString += wineryList[elementNumber].getWineryId();
    tempString += '\n';
    tempString += "Distance - Villa      : ";
    tempString += wineryList[elementNumber].getVillaDistance();
    tempString += '\n';
    tempString += "Wine Products       : ";
    tempString += wineryList[elementNumber].getNumProducts();
    tempString += '\n';

    return tempString;

}

//Display the list
void MainWindow::on_pushButton_viewCurrentList_clicked()
{
   ui->viewListOfWineries->hide();
   ui->viewCurrentList_childOViewList->show();

   ui->wineryList->clear();


   for(int i = 0; i < wineryList.size();i++)
   {
       ui->wineryList->addItem(returnAllData(i));
   }
}

void MainWindow::on_pushButton_backInListView_clicked()
{
    ui->viewCurrentList_childOViewList->hide();
    ui->viewListOfWineries->show();
    ui->wineryList->clear();

}
void MainWindow::on_pushButton_backAboutVilla_clicked()
{
    ui->page_AboutTheVilla->hide();
    ui->viewListOfWineries->show();
}



void MainWindow::on_pushButton_10_clicked()
{
    ui->viewListOfWineries->hide();
    ui->page_AboutTheVilla->show();
}


QString MainWindow::getWineList(int vectorElement)
{
    vector<Wine> tempWineList;

    tempWineList = *(wineryList[vectorElement].getWineProducts());

}

//View current list of wines and wineries button
void MainWindow::on_pushButton_14_clicked()
{
    for(int i = 0; i < wineryList.size();i++)
    {
        ui->list_currentWines->addItem(wineryList[i].returnAllWineProduct());
    }
    for(int i = 0; i < wineryList.size(); i++)
    {
        ui->list_currentWineries->addItem(returnAllData(i));
    }

    ui->afterAdminLogin->hide();
    ui->page_ViewCurrentLists->show();
}

void MainWindow::on_pushButton_backViewCurrentLists_clicked()
{
    ui->page_ViewCurrentLists->hide();
    ui->list_currentWines->clear();
    ui->list_currentWineries->clear();
    ui->afterAdminLogin->show();
}

void MainWindow::on_pushButton_viewWines_clicked()
{
    for(int i = 0; i < wineryList.size();i++)
    {
        ui->list_wineList->addItem(wineryList[i].returnAllWineProduct());
    }
    ui->viewListOfWineries->hide();
    ui->viewWines->show();

}

void MainWindow::on_pushButton_backViewWines_clicked()
{
    ui->viewWines->hide();
    ui->viewListOfWineries->show();
}

void MainWindow::on_pushButton_Quit_clicked()
{
    QMessageBox::information(this, " ", "Have A Nice Day");
    this->close();
}

void MainWindow::on_pushButton_backAddWinery_clicked()
{
    ui->page_addWineryInAdmin->hide();
    ui->afterAdminLogin->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->afterAdminLogin->hide();
    ui->page_addWineryInAdmin->show();
}

void MainWindow::on_pushButton_viewCurrentLists_addWinery_clicked()
{
    ui->page_addWineryInAdmin->hide();
    ui->page_AdminListVIew->show();
    for(int i = 0; i < wineryList.size();i++)
    {
        ui->listWidget_adminViewWIne->addItem(wineryList[i].returnAllWineProduct());
    }
    for(int i = 0; i < wineryList.size(); i++)
    {
        ui->listWidget_adminViewWineries->addItem(returnAllData(i));
    }
}

void MainWindow::on_pushButton_backInAdminList_clicked()
{
    ui->page_AdminListVIew->hide();
    ui->page_addWineryInAdmin->show();

    ui->listWidget_adminViewWIne->clear();
    ui->listWidget_adminViewWineries->clear();
}

bool MainWindow::AddWinery()
{
    Winery newWinery;
    int index;
    int wineryNameLength;
    QString wineryName;
    bool addingSucceed = true;
    QRegularExpression wineryNameRegExp("^([A-Z]+)([a-z]*)(\\s*)('?)(\\w*)");
    QRegularExpression distanceRegExp("(\\d+)[\\.]?(\\d*)$");
    QRegularExpressionMatch match;
//    vector<double> wineryDistances;

    match = wineryNameRegExp.match(newWineryInfo.at(0)->displayText());
    if(match.hasMatch())
    {
        //Check for existing winery list
        index = 0;
        while(index < wineryList.size() && addingSucceed)
        {
            addingSucceed = wineryList.at(index).getName() != newWineryInfo.at(0)->displayText();
            index++;
        }

        if(addingSucceed)
        {
            newWinery.setName(newWineryInfo.at(0)->displayText());
            newWinery.setWineryId(wineryList.size() + 1);
        }
        else
        {
            QMessageBox::information(this, "Add Winery Error", "Winery already exists");
        }
    }
    else
    {
        QMessageBox::information(this, "Add Winery Error", "Invalid Name");
        addingSucceed = false;
    }

    if(addingSucceed)
    {
        match = distanceRegExp.match(newWineryInfo.at(1)->displayText());

        if(match.hasMatch())
        {
            newWinery.setToVillaDistance(newWineryInfo.at(1)->displayText().toDouble());
        }
        else
        {
            QMessageBox::information(this, "Add Winery Error",
                                     "Invalid Distance to Villa");
            addingSucceed = false;
        }
    }

    index = 2;
    match = distanceRegExp.match(newWineryInfo.at(index)->displayText());
    while(addingSucceed && index < newWineryInfo.size())
    {
        match = distanceRegExp.match(newWineryInfo.at(index)->displayText());
        if(!match.hasMatch())
        {
            addingSucceed = false;

            wineryNameLength = labelList.at(index + 1)->text().size();
            wineryName = labelList.at(index + 1)->text();
            QMessageBox::information(this, "Add Winery Error",
                "Invalid Distance to " +
                    wineryName.remove(wineryNameLength - 1, 1));
            qDebug() << newWineryInfo.at(index)->displayText();

        }
        index++;
    }

    if(addingSucceed)
    {
        /*For loop -Take the distances from distance list, push it to the newWinery's
         *  distance list and add the new distance to each existing winery */
        for(index = 0; index < wineryList.size(); index++)
        {           
            newWinery.addToWineryDistance(newWineryInfo.at(index + 2)->displayText().toDouble());
            wineryList.at(index).addToWineryDistance
                    (newWineryInfo.at(index + 2)->displayText().toDouble());
//            qDebug() << wineryList.at(index).getDistances()->at(1);
        }

        newWinery.addToWineryDistance(0);
        wineryList.push_back(newWinery);

        shoppingCart.setList(wineryList);
        shoppingCart.fillAllLists();
    }

    return addingSucceed;
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->page_addWineryInAdmin->hide();

    int                 index;
    int                 xLabel    = 10;
    int                 yLabel    = 10;
    int                 xLineEdit = 200;
    QLineEdit*          distance;
    QLineEdit*          name;
    QLabel*             wineryName;
    QLabel*             label;
    QLineEdit*          villaDistance;

    label = new QLabel("Winery Name: ", ui->page_addWineryPage);
    labelList.push_back(label);
    name = new QLineEdit(ui->page_addWineryPage);

//    ui->page_addWineryPage->
    label->move(xLabel, yLabel);
    name->move(xLineEdit, yLabel);

    newWineryInfo.push_back(name);

    label = new QLabel("Distance to Canyon Villa: ", ui->page_addWineryPage);
    labelList.push_back(label);
    villaDistance = new QLineEdit(ui->page_addWineryPage);
    newWineryInfo.push_back(villaDistance);

    yLabel+= 25;

    label->move(xLabel, yLabel);
    villaDistance->move(xLineEdit, yLabel);

    label = new QLabel("Distance to other Wineries: ", ui->page_addWineryPage);
    labelList.push_back(label);

    yLabel += 25;
    label->move(xLabel, yLabel);

    /*Run through the whole winery list, get the name of the wineries to prompt
        for the distances */
    for(index = 0; index < wineryList.size(); index++)
    {
        yLabel +=25;

        wineryName = new QLabel(wineryList.at(index).getName() + ":",
                                ui->page_addWineryPage);
        labelList.push_back(wineryName);
        wineryName->move(xLabel, yLabel);
        distance = new QLineEdit(ui->page_addWineryPage);
        distance->setMaximumWidth(200);
        distance->move(xLineEdit, yLabel);

        newWineryInfo.push_back(distance);

        wineryName->move(xLabel, yLabel);
        distance->move(xLineEdit, yLabel);
    }

    ui->page_addWineryPage->show();
}

void MainWindow::on_addWineryOK_clicked()
{
    bool addSucceed;
    addSucceed = AddWinery();

    if(addSucceed)
    {
        QMessageBox::information(this, "Add Winery", "Add successfully");
        while(!labelList.empty())
        {
            labelList.back()->clear();
            labelList.pop_back();
        }

        while(!newWineryInfo.empty())
        {
            newWineryInfo.back()->clear();
            newWineryInfo.pop_back();
        }

        ui->page_addWineryPage->hide();
        ui->page_addWineryInAdmin->show();
    }
}

void MainWindow::on_addWineryCancel_clicked()
{

    while(!labelList.empty())
    {
        labelList.back()->clear();
        labelList.pop_back();
    }

    while(!newWineryInfo.empty())
    {
        newWineryInfo.back()->clear();
        newWineryInfo.pop_back();
    }

    ui->page_addWineryPage->hide();
    ui->page_addWineryInAdmin->show();
}

void MainWindow::on_pushButton_viewDistanceList_clicked()
{
    int index;
    int row;
    int column;
    int maxHeaderLength = 0;
    QString distance;
    QTableWidgetItem*   tableItem;
    QStringList         wineryNameList;

    CreateDistanceVector();

    wineryNameList.append("Canyon Villa");
    for(index = 0; index < wineryList.size(); index++)
    {
        wineryNameList.append(wineryList.at(index).getName());

        if(wineryList.at(index).getName().size() > maxHeaderLength)
        {
            maxHeaderLength = wineryList.at(index).getName().size();
        }
    }

    ui->distanceTable->setColumnCount(distanceList.size());
    ui->distanceTable->setRowCount(distanceList.size());
    ui->distanceTable->setHorizontalHeaderLabels(wineryNameList);
    ui->distanceTable->setVerticalHeaderLabels(wineryNameList);

    //For loop - Set column width
    for(column = 0; column < distanceList.size(); column++)
    {
        ui->distanceTable->setColumnWidth(column, maxHeaderLength * 6.5);
    }

    for(row = 0; row < distanceList.size(); row++)
    {
        for(column = 0; column < distanceList.size(); column++)
        {
            tableItem = new QTableWidgetItem();
            tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
            distance = distance.setNum(distanceList.at(row).at(column),'f',2);
            tableItem->setText(distance);
            ui->distanceTable->setItem(row, column, tableItem);
        }
    }
    ui->viewListOfWineries->hide();
    ui->viewDistances->show();
}



void MainWindow::on_pushButton_modifyWine_clicked()
{
    ui->afterAdminLogin->hide();
    ui->page_wineOptionsAdmin->show();
}

void MainWindow::on_pushButton_back_wineOptions_clicked()
{
    ui->page_wineOptionsAdmin->hide();
    ui->afterAdminLogin->show();
}

void MainWindow::CreateDistanceVector()
{
    int wineryIndex;
    int distanceIndex;
    vector<double>* tempDistanceVector;

    //Delete the old distance list
    while(!distanceList.empty())
    {
        distanceList.pop_back();
    }
    //First Vector: Villa Canyon
    tempDistanceVector = new vector<double>;
    //From Canyon Villa Distance to Canyon Villa Distance is 0 miles
    tempDistanceVector->push_back(0);

    //Push distance to Villa to the first vector in the vector of vector
    for(distanceIndex = 0; distanceIndex < wineryList.size(); distanceIndex++)
    {
        tempDistanceVector->push_back(wineryList.at(distanceIndex).getVillaDistance().toDouble());
    }

    distanceList.push_back(*tempDistanceVector);

    //Outter For list: Create a distance list of each winery and push to the
    //  outter vector

    for(wineryIndex = 0; wineryIndex < wineryList.size(); wineryIndex++)
    {
        //Creates a temporary vector
       tempDistanceVector = new vector<double>;

       tempDistanceVector->push_back(wineryList.at(wineryIndex).getVillaDistance().toDouble());

       for(distanceIndex = 0; distanceIndex < wineryList.size(); distanceIndex++)
       {
           tempDistanceVector->push_back(wineryList.at(wineryIndex).getDistances()->at(distanceIndex));
       }

       distanceList.push_back(*tempDistanceVector);
    }
}

void MainWindow::on_backButtonViewDistance_clicked()
{
    ui->viewDistances->hide();
    ui->viewListOfWineries->show();
}

void MainWindow::on_pushButton_customTrip_back_clicked()
{
    ui->page_customTrip->hide();
    ui->planATrip->show();
    ui->list_customTrip->clear();
}


void MainWindow::on_pushButton_shortestTrip_clicked()
{
    ui->planATrip->hide();
    ui->page_shortestTrip->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->page_shortestTrip->hide();
    ui->planATrip->show();
    ui->lineEdit_numberOfWineries->clear();
}

void MainWindow::on_pushButton_shortestTripPage2_back_clicked()
{
    ui->page_shortestTripPage2->hide();
    ui->page_shortestTrip->show();
    ui->list_customTripPage2->clear();
}


//void MainWindow::on_pushButton_editWine_wineOptions_clicked()
//{
//    ui->page_wineOptionsAdmin->hide();
//    ui->page_editWine_wineOptionsAdmin->show();

//    QStringList list;

//    for(int i = 0; i<wineryList.size();i++){
//        list << wineryList.at(i).getName();
//    }

//    ui->comboBox_selectWinery_editWine->addItems(list);

////    ui->comboBox_selectWinery_editWine->;

//}

//void MainWindow::on_pushButton__back_editWine_clicked()
//{

//    ui->page_editWine_wineOptionsAdmin->hide();
//    ui->page_wineOptionsAdmin->show();
//}



void MainWindow::on_pushButton_3_clicked()
{
    ui->viewListOfWineries->hide();
    ui->mainMenu->show();
}

void MainWindow::on_pushButton_shopForWines_clicked()
{
    shoppingCart.show();
}

void MainWindow::on_pushButton_clicked()
{
    tourWineries.show();
}

void MainWindow::on_pushButton_website_clicked()
{
    QString link = "http://www.thecanyonvilla.com/";
    QDesktopServices::openUrl(QUrl(link));
}
