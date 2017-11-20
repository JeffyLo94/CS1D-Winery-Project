#include "Test.h"

double shortest(vector< vector<double> > &v,
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

	vector<int>::iterator it;

	// Will always start at winery being passed in
	path.push_back(key);

	numberOfWineries--;

	while (numberOfWineries > 1)
	{
		// Finds the shortest distance from the starting winery, records the position
		for (int i = 1; i < list.at(key).size(); i++)
		{
			if (list.at(key).at(i) < tempShort &&
				list.at(key).at(i) != 0)
			{
				it = find (path.begin(), path.end(), i);

				if (it == path.end())
				{
					tempShort = list.at(startingWinery).at(i);
					tempKey = i;
				}
			}
		}

		shortest += tempShort;
		tempShort = 999;

		path.push_back(tempKey);

		key = tempKey;
		numberOfWineries--;
	}

	return shortest;
}
