#ifndef WINERY_H
#define WINERY_H
#include <iostream>
#include <QString>
#include <vector>
#include "wine.h"
using namespace std;

/************************************************************
 * Winery Class
 * ----------------------------------------------------------
 *  Class for all winery objects. Composed of vectors for
 * wines and distances. Winery ID (number) corresponds with
 * the index in the vector of distances to wineries. I.E. if
 * Winery ID is 5, element in index 5 of the vector of
 * distances will return 0.0
 ************************************************************/

class Winery{
    public:
        //Default Constructor
        Winery();
        //Overloaded Constructor
        Winery(QString nameWinery, int wineryId,
               float distanceFromVilla,int numberWineOffered);
        //Deconstructor
        ~Winery();

        // M U T A T O R S
        //SetName - sets winery name
        void setName( QString inName );
        //setAmountofWinesOffered - sets total number of wines
        void setAmountofWinesOffered(int numberOfWines);
        //setWineryId - sets winery number, which corresponds w/ distance vector index
        void setWineryId( int inId );
        //setToVillaDistance - sets distance from winery to canyon villa
        void setToVillaDistance( double inDistance );
        //addToWineryDistance - adds a distance to the winery's vector of distances to other wineries
        void addToWineryDistance( double inDistance );
        //addWineProduct - adds a wine to the winery's vector of offered wines
        void addWineProduct( Wine wineType );

        // A C C E S S O R S
        //getName - Returns Name of Winery
        QString         getName();
        //getWineryId - Returns Winery Number - corresponds to distance index
        QString         getWineryId();
        //getTotWineries - Returns total number of wineries
        QString         getTotWineries();
        //getVillaDistance - Returns distance to villa
        QString         getVillaDistance();
        //getDistances - Returns pointer to distances vector
        vector<double>* getDistances();
        //getDistance - Returns distances at specified index
        QString         getDistance(int index);
        //getNumDistances - Returns the total number of distances
        QString         getNumDistances();
        //getWineProducts - Returns pointer to wines vector
        vector<Wine>*   getWineProducts();
        //getNumProducts - Returns the total number of wine products
        QString         getNumProducts();
        //getWine - Returns the wine at specified index from the vector
        Wine            getWine(int index);
        //returnAllWineProduct - Returns formated string of all wine products
        QString         returnAllWineProduct();
        //returnSingleWineProduct - Returns single wine product
        QString         returnSingleWineProduct(int index);

    private:
        QString         name;
        int             wineryId;
        int             totWineries;
        double          villaDistance;
        int             numberOfWinesOffered;
        vector<double>  wineryDistances;
        vector<Wine>    wineProducts;
};



#endif // WINERY_H
