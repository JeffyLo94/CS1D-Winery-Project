#include "Winery.h"
#include <sstream>
#include <ostream>
#include <QDebug>

Winery::Winery(){
}


Winery::Winery(QString nameWinery, int wineryid,
            float distanceFromVilla,int numberWineOffered)
{
    setName(nameWinery);
    setWineryId(wineryid);
    setToVillaDistance(distanceFromVilla);
    setAmountofWinesOffered(numberWineOffered);
}

Winery::~Winery(){
}

// M U T A T O R S
void Winery::setName( QString inName ){
    name = inName;
}

void Winery::setWineryId(int inId){
    wineryId = inId;
}

void Winery::setAmountofWinesOffered(int numberOfWines)
{
    numberOfWinesOffered = numberOfWines;
}


void Winery::setToVillaDistance(double inDistance){
    villaDistance = inDistance;
}

void Winery::addToWineryDistance(double inDistance){
    wineryDistances.push_back(inDistance);
}

void Winery::addWineProduct(Wine wineType){
    wineProducts.push_back(wineType);
}

// A C C E S S O R S
QString Winery::getName(){
    return name;
}

QString Winery::getWineryId(){
    return QString::number(wineryId);
}

QString Winery::getTotWineries(){
    return QString::number(totWineries);
}

QString Winery::getVillaDistance(){
    return QString::number(villaDistance);
}

vector<double>* Winery::getDistances(){
    return &wineryDistances;
}

QString Winery::getDistance(int index){
    if(!wineryDistances.empty()){
        return QString::number(wineryDistances[index]);
    }
    else{
        std::cout << "Error - vector empty\n";
        return NULL;
    }
}

QString Winery::getNumDistances(){
    return QString::number(wineryDistances.size());
}

vector<Wine>* Winery::getWineProducts(){
    return &wineProducts;
}

QString Winery::getNumProducts(){
    return QString::number(wineProducts.size());
}

Wine Winery::getWine(int index){
    return wineProducts[index];
}

QString Winery::returnAllWineProduct()
{
    int size = wineProducts.size();

    QString allProducts;

   if(size != 0)
   {
        allProducts = "All Wine Products for " + name + '\n' + '\n';

        for(int i = 0; i < size; i++)
        {
            allProducts += wineProducts[i].returnWineDataFormated();
            allProducts += '\n';
        }

        allProducts += '\n';

        qDebug() << allProducts;
   }
   return allProducts;
}


//Returns a single wine product for the index provided

QString Winery::returnSingleWineProduct(int index)
{
    QString wineData;

    wineData += "Name  : " + wineProducts[index].getName() + '\n';
    wineData += "Price : " +  wineProducts[index].getPrice()+ '\n';
    wineData += "Year  : " + wineProducts[index].getYear()  + '\n';


    return wineData;
}
