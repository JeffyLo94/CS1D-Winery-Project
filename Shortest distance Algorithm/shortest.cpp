#include "Test.h"

float shortest(vector< vector<float> > &v,
			   vector<int> &path)
{
	// Used in element comparisons
	int key;
	int tempKey;

	// Used in outputting the order to visit
	float compare;

	// The shortest distances need to be initialized with large numbers
	float shortest = 999;
	float tempShort = 999;

	// Used as temp storage before pushing into larger vector
	vector<float> tempList;
	// A vector of vectors we can edit
	vector< vector<float> > list;

	// Copies path into tempPath so can can pop off when list is being populated
	vector<int> tempPath = path;
	// Used for comparisons in third FOR loop
	vector<int> revPath = path;

	// Reverses order of path so it's in numerical order
	reverse(tempPath.begin(), tempPath.end());

	// Finds outer vector that we want
	for (unsigned int i = 0; i < v.size(); i++)
	{
		// If the correct vector is found
		if(v.at(i).at(0) == tempPath.back())
		{
			// Finds us the correct values in the second vector
			for (unsigned int j = 1; j < v.at(i).size(); j++)
			{
				// Compares against wanted values
				for (unsigned int k = 0; k < revPath.size(); k++)
				{
					// Takes out distances to itself
					if (j == revPath.at(k) &&
						v.at(i).at(j) != 0)
					{
						// First value in vector is distance to villa
						if (tempList.empty() && i != 0)
						{
							tempList.push_back(v.at(0).at(tempPath.back()));
						}

						tempList.push_back(v.at(i).at(j));
					}
				}
			}
			// Pushes trimmed vector into other vector
			list.push_back(tempList);
			tempList.clear();
			// Pops path for next comparison
			tempPath.pop_back();
		}
	}

	// Finds the shortest distance from the villa, records the position
	for (int i = 0; i < list.at(0).size(); i++)
	{
		if (list.at(0).at(i) < shortest)
		{
			shortest = list.at(0).at(i);
			key = i;
		}
	}

	// Used for comparisons when outputting which path to take
	vector<float> distances = list.at(0);

	// Allows proper traversal of path vector being returned without needing a loop
	int count = 0;

	// Repurposing this vector to save space, it now contains the numbers of the
	// wineries to visit.
	tempPath = path;
	// Pop the first value as we're always leaving from the villa
	tempPath.erase(tempPath.begin());

	// Pops the distances of all wineries from villa
	list.erase(list.begin());

	while (!list.empty())
	{
		if (list.size() > 1)
		{
			// Iterates through inner vector to find shortest distance
			for (int i = 1; i < list.at(key).size(); i++)
			{
				if (list.at(key).at(i) < tempShort)
				{
					tempShort = list.at(key).at(i);
					tempKey = i - 1;
					compare = list.at(key).at(0);
				}
			}

			// Adds to total
			shortest += tempShort;

			// Updates path vector with which node to go to next
			for (int i = 0; i < tempPath.size(); i++)
			{
				if (distances.at(i) == compare)
				{
					path.at(count++) = tempPath.at(i);
				}
			}

			// Resets for next loop
			tempShort = 999;

			// Pops element
			list.erase(list.begin() + key);

			// Iterate through inner vectors to delete list element previously
			// popped
			if (list.size() > 1)
			{
				for (int i = 0; i < list.size(); i++)
				{
					// Because the actual element key is associated with is deleted
					// one has to be added to every element after it
					if (i < key)
					{
						list.at(i).erase(list.at(i).begin() + key);
					}
					else
					{
						list.at(i).erase(list.at(i).begin() + (key + 1));
					}
				}
			}
			// Points loop to new vector
			key = tempKey;
		} // Closes if (list.size() > 1)
		else
		{
			// Updates 2nd to last element in path vector
			for (int i = 0; i < tempPath.size(); i++)
			{
				if (distances.at(i) == list.at(0).at(0))
				{
					path.at(count++) = tempPath.at(i);
				}
			}

			shortest += list.at(0).at(0);
			list.pop_back();
			path.back() = 0;
		}
	} // Closes while (!list.empty())

	return shortest;
}
