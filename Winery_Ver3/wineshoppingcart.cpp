#include "wineshoppingcart.h"
#include "ui_wineshoppingcart.h"


wineShoppingCart::wineShoppingCart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wineShoppingCart)
{
    ui->setupUi(this);
    this->setWindowTitle("Shopping Cart");

    grandTotal = 0;

    ui->currentTotal->setText(QString::number(grandTotal));
    ui->mainMenu->show();
}

wineShoppingCart::~wineShoppingCart()
{
    delete ui;
}

wineShoppingCart::wineShoppingCart(const vector<Winery> & List)
{
    wineryList = List;
    grandTotal = 0;
}


void wineShoppingCart::fillAllLists()
{
    int                 wineryIndex;
    int                 wineIndex;
    int                 xWineInfo;
    int                 yWineInfo;
    int                 xNumberBottle;
    int                 yNumberBottle;
    int                 xLabelBottle;
    int                 index;
    QWidget*            newTabPtr;
    QWidget*            widgetPtr;
    QListWidget*        newList;
    QLabel*             label;
    QTextBrowser*       totalBottleText;
    QTextBrowser*       totalWineryText;
    QScrollArea*        scrollArea;
    QLineEdit*          numberOfBottle;
    vector<QLineEdit*>* numberBottleListEachWinery;
    QScrollBar*         scrollBar;


    ui->wineryTab->clear();
    ui->currentTotal->setText("0");

    //Clear the whole vector of vector -> After this -> vector = NULL
    while(!bottleList.empty())
    {
        while(!(bottleList.at(bottleList.size()-1).empty()))
        {
            bottleList.at(bottleList.size() - 1).pop_back();
        }

        bottleList.pop_back();
    }

    //Clear those vector
    //Can combine since they basically has the same size
    while(!totalEachWinery.empty())
    {
        totalEachWinery.pop_back();
        totalBottleEachWinery.pop_back();
    }


    //Create the tabs
    for(wineryIndex = 0; wineryIndex < wineryList.size(); wineryIndex++)
    {
        newTabPtr = new QWidget();
        widgetPtr = new QWidget(newTabPtr);
        widgetPtr->setGeometry(20, 20, 366, 700);

        scrollArea = new QScrollArea(newTabPtr);
        scrollArea->setStyleSheet("background-color:white;");
        scrollArea->setGeometry(10, 20, 370, 225);

        numberBottleListEachWinery = new vector<QLineEdit*>;

        label = new QLabel("Total Bottles: ",newTabPtr);
        label->move(400, 40);

        totalBottleText = new QTextBrowser(newTabPtr);
        totalBottleText->setGeometry(400, 65, 113, 25);
        totalBottleText->setText("0");


        label = new QLabel("Total: ",newTabPtr);
        label->move(400, 120);

        totalWineryText = new QTextBrowser(newTabPtr);
        totalWineryText->setGeometry(400, 145, 113, 25);
        totalWineryText->setText("0");


        xWineInfo = 10;
        yWineInfo = 10;
        xLabelBottle = 240;
        xNumberBottle = 260;
        yNumberBottle = 10;

        for(wineIndex = 0; wineIndex < wineryList.at(wineryIndex).getNumProducts().toInt(); wineIndex++)
        {
            //Set wine info
            label = new QLabel(widgetPtr);
            label->setGeometry(xWineInfo, yWineInfo, 210, 50);
            label->setText(wineryList.at(wineryIndex).returnSingleWineProduct(wineIndex));

            //Set the "x" label for bottles
            label = new QLabel("x",widgetPtr);
            label->setGeometry(xLabelBottle, yNumberBottle, 30, 20);

            //Set the line edit for number of bottles
            numberOfBottle = new QLineEdit(widgetPtr);
            numberOfBottle->setGeometry(xNumberBottle, yNumberBottle, 90, 20);

            yWineInfo += 50;
            yNumberBottle += 50;

            numberBottleListEachWinery->push_back(numberOfBottle);
        }
        scrollArea->setWidget(widgetPtr);

        scrollArea->show();
        ui->wineryTab->addTab(newTabPtr, wineryList.at(wineryIndex).getName());

        totalEachWinery.push_back(totalWineryText);
        totalBottleEachWinery.push_back(totalBottleText);
        bottleList.push_back(*numberBottleListEachWinery);
    }
}

void wineShoppingCart::setList(const vector<Winery> &list)
{
    wineryList = list;
}


void wineShoppingCart::on_pushButton_checkout_clicked()
{
    QString link = "https://www.paypal.com/home";
    QDesktopServices::openUrl(QUrl(link));
}

void wineShoppingCart::on_pushButton_updateCart_clicked()
{
    int wineryIndex;
    int wineIndex;
    int numOfBottleEachWine;
    int totalBottle;
    double totalPrice;
    double totalEachWine;
    QString wineInfo;
    QString winePrice;

    grandTotal  = 0;


    for(wineryIndex = 0; wineryIndex < wineryList.size(); wineryIndex++)
    {
        totalBottle = 0;
        totalPrice  = 0;
        numOfBottleEachWine = 0;
//        totalEachWine = 0;

        for(wineIndex = 0; wineIndex < wineryList.at(wineryIndex).getNumProducts().toInt(); wineIndex++)
        {
            //Read in the number bottle of each wine
            numOfBottleEachWine = bottleList[wineryIndex][wineIndex]->displayText().toInt();
            //Calculate the total amount for each wine
            totalEachWine   = numOfBottleEachWine *
wineryList[wineryIndex].getWineProducts()->at(wineIndex).getPrice().toDouble();

            //Add up the total bottle of each wineries
            totalBottle     += numOfBottleEachWine;

            //Calculate the total price for each winery
            totalPrice += totalEachWine;

            //Calculate the grand total
            grandTotal += totalEachWine;
        }

        totalEachWinery.at(wineryIndex)->setText(QString::number(totalPrice));
        totalBottleEachWinery.at(wineryIndex)->setText(QString::number(totalBottle));
    }

    ui->currentTotal->setText(QString::number(grandTotal));
}
