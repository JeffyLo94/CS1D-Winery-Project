#include "wine.h"

Wine::Wine() : name(""), price(0.0), year(0){}

Wine::Wine(QString wineName, double winePrice, int wineYear) : name(wineName),price(winePrice), year(wineYear)
{
}

Wine::~Wine(){}

void Wine::setName(QString wineName)
{
    name = wineName;
}

void Wine::setPrice(double winePrice)
{
    price = winePrice;
}

void Wine::setYear(int wineYear)
{
    year = wineYear;
}

QString Wine::getName()
{
    return name;
}

QString Wine::getPrice()
{
    QString tempPrice;
    tempPrice.setNum(price,'f',2);

    return tempPrice;
}

QString Wine::getYear()
{
    return QString::number(year);
}

QString Wine::returnWineDataFormated()
{
    QString temp;
    QString tempPrice;
//    QTextStream out;
    QString tempYear;

    tempYear.setNum(year);

    //Sets the precision of a float being converted to a QString
    tempPrice.setNum(price,'f',2);

    temp += "Wine Name    : "  + name + '\n';
    temp += "Wine Year    : "  + tempYear  + '\n';
    temp += "Wine Price   : "  + tempPrice + '\n' + '\n';

    qDebug() << temp;

    return temp;
}

//QString r
