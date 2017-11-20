#ifndef WINE_H
#define WINE_H

#include <QString>
#include <QDebug>

class Wine
{
public:
    /***************************************************************************
     * Wine()
     *  The default constructor will set the wine's name to empty string
     *      and the wine's price to 0.0
     **************************************************************************/
    Wine();

    /***************************************************************************
     * Wine(QString wineName, double winePrice)
     *  The default constructor will set the wine's name to wineName
     *      the wine's price to winePrice, and the wine's year to wineYear
     **************************************************************************/
    Wine(QString wineName,  //IN - The wine's name
         double  winePrice, //IN - The wine's price
         int     wineYear); //IN - The wine's year

    /***************************************************************************
     * ~Wine()
     *  The default destructor will delete the object
     **************************************************************************/
    ~Wine();

    /***************************************************************************
     * setName(QString wineName)
     *  The method will set the wine's name to wineName
     *      -> RETURN: nothing
     **************************************************************************/
    void setName(QString wineName);  //IN - The wine's name

    /***************************************************************************
     * setPrice(double winePrice)
     *  The method will set the wine's price toe winePrice
     *      -> RETURN: nothing
     **************************************************************************/
    void setPrice(double winePrice); //IN - The wine's price

    /***************************************************************************
     * setYear(int year)
     *  The method will set the wine's price toe winePrice
     *      -> RETURN: nothing
     **************************************************************************/
    void setYear(int wineYear); //IN - The wine's price

    /***************************************************************************
     * getName()
     *  The method will return the wine's name
     *      -> RETURN: the wine's name
     **************************************************************************/
    QString getName();

    /***************************************************************************
     * getPrice()
     *  The method will return the wine's price
     *      -> RETURN: the wine's price
     **************************************************************************/
    QString getPrice();

    /***************************************************************************
     * getYear()
     *  The method will return the wine's year
     *      -> RETURN: the wine's year
     **************************************************************************/
    QString getYear();

    /***************************************************************************
     * returnWineDataFormated()
     *  The method will return a QString of the wine's info in a formated way
     *      -> RETURN: wine's info
     **************************************************************************/
    QString returnWineDataFormated();

private:
    QString name;       //The name of the wine
    double  price;      //The price of the wine
    int     year;       //The year of the wine

};


#endif // WINE_H
