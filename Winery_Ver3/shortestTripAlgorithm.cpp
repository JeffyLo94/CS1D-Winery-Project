#include "mainwindow.h"
double MainWindow::shortestTripAlgorithm(vector< vector<double> > &v,
                vector<int> &path,
                int startingWinery,
                int numberOfWineries)
{
    // A vector of vectors we can edit
    vector< vector<double> > list = v;

    // The shortest distances need to be initialized with large numbers
    double shortest = list.at(0).at(startingWinery);
    double tempShort = 999;

    int key = startingWinery;
    int tempKey;

    bool check = false;
    vector<int>::iterator it;

    // Will always start at winery being passed in
    path.push_back(key);

    numberOfWineries--;

    while (numberOfWineries > 0)
    {
        // Finds the shortest distance from the starting winery, records the position
        for (int i = 1; i < list.at(key).size(); i++)
        {
            if (list.at(key).at(i) < tempShort &&
                list.at(key).at(i) != 0)
            {
                for (int j = 0; j < path.size(); j++)
                {
                    if (i == path.at(j))
                    {
                        check = true;
                    }
                }

                if (check == false)
                {
                    tempShort = list.at(key).at(i);
                    tempKey = i;
                }

                check = false;
            }
        }

        shortest += tempShort;

        tempShort = 999;

        path.push_back(tempKey);

        key = tempKey;
        numberOfWineries--;

    }
    return shortest + list.at(0).at(key);
}
