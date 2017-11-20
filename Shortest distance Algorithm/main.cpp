#include "Test.h"

/*Shortest function
 * 	vector< vector <float> > &v
 * 	vector<int> &path
 *
 * 	v - The list of all distances from all wineries. Initialized in the
 * 		file below. Could directly integrate into QT if need be.
 *
 * 	path - Which wineries are going to be visited. Needs to be passed
 * 		   in in numerical order, but will get returned in the order
 * 		   the wineries were visited.
 *
 *	To test the function ignore everything in this file until the very
 *	end where path is pushed with values. Edit those values to signify
 *	different trips.
 */
int main ()
{
	// Distances from Villa
	vector<float> dist00;
	// The first distance is the winery number
	dist00.push_back(0);
	dist00.push_back(8);
	dist00.push_back(4.29);
	dist00.push_back(12.41);
	dist00.push_back(7.56);
	dist00.push_back(2.67);
	dist00.push_back(5.94);
	dist00.push_back(8.44);
	dist00.push_back(12.75);
	dist00.push_back(9.19);
	dist00.push_back(14.54);

	// Distances from winery 01
	vector<float> dist01;
	// The first distance is the winery number
	dist01.push_back(1);
	dist01.push_back(0);
	dist01.push_back(13.2);
	dist01.push_back(15.4);
	dist01.push_back(11.5);
	dist01.push_back(13.3);
	dist01.push_back(15.2);
	dist01.push_back(5.8);
	dist01.push_back(6.9);
	dist01.push_back(11.2);
	dist01.push_back(3.5);

	// Distances from winery 02
	vector<float> dist02;
	// The first distance is the winery number
	dist02.push_back(2);
	dist02.push_back(13.2);
	dist02.push_back(0);
	dist02.push_back(15.1);
	dist02.push_back(14.8);
	dist02.push_back(0.1);
	dist02.push_back(4.2);
	dist02.push_back(10.3);
	dist02.push_back(9.3);
	dist02.push_back(5.2);
	dist02.push_back(11.0);

	// Distances from winery 03
	vector<float> dist03;
	// The first distance is the winery number
	dist03.push_back(3);
	dist03.push_back(15.4);
	dist03.push_back(15.1);
	dist03.push_back(0);
	dist03.push_back(4.3);
	dist03.push_back(16.1);
	dist03.push_back(14.3);
	dist03.push_back(18.4);
	dist03.push_back(18.3);
	dist03.push_back(17.2);
	dist03.push_back(17.2);

	// Distances from winery 04
	vector<float> dist04;
	// The first distance is the winery number
	dist04.push_back(4);
	dist04.push_back(11.5);
	dist04.push_back(14.8);
	dist04.push_back(4.3);
	dist04.push_back(0);
	dist04.push_back(8.1);
	dist04.push_back(9.4);
	dist04.push_back(14.4);
	dist04.push_back(14.3);
	dist04.push_back(13.2);
	dist04.push_back(13.2);

	// Distances from winery 05
	vector<float> dist05;
	// The first distance is the winery number
	dist05.push_back(5);
	dist05.push_back(13.3);
	dist05.push_back(0.1);
	dist05.push_back(16.1);
	dist05.push_back(8.1);
	dist05.push_back(0);
	dist05.push_back(4.5);
	dist05.push_back(8.5);
	dist05.push_back(8.4);
	dist05.push_back(5.1);
	dist05.push_back(12.1);

	// Distances from winery 06
	vector<float> dist06;
	// The first distance is the winery number
	dist06.push_back(6);
	dist06.push_back(15.2);
	dist06.push_back(4.2);
	dist06.push_back(14.3);
	dist06.push_back(9.4);
	dist06.push_back(4.5);
	dist06.push_back(0);
	dist06.push_back(11.2);
	dist06.push_back(11.1);
	dist06.push_back(5.1);
	dist06.push_back(14.2);

	// Distances from winery 07
	vector<float> dist07;
	// The first distance is the winery number
	dist07.push_back(7);
	dist07.push_back(5.8);
	dist07.push_back(10.3);
	dist07.push_back(18.4);
	dist07.push_back(14.4);
	dist07.push_back(8.5);
	dist07.push_back(11.2);
	dist07.push_back(0);
	dist07.push_back(0.7);
	dist07.push_back(5.8);
	dist07.push_back(4.0);

	// Distances from winery 08
	vector<float> dist08;
	// The first distance is the winery number
	dist08.push_back(8);
	dist08.push_back(6.9);
	dist08.push_back(9.3);
	dist08.push_back(18.7);
	dist08.push_back(14.3);
	dist08.push_back(8.4);
	dist08.push_back(11.1);
	dist08.push_back(0.7);
	dist08.push_back(0);
	dist08.push_back(5.7);
	dist08.push_back(4.7);

	// Distances from winery 09
	vector<float> dist09;
	// The first distance is the winery number
	dist09.push_back(9);
	dist09.push_back(11.2);
	dist09.push_back(5.2);
	dist09.push_back(17.2);
	dist09.push_back(13.2);
	dist09.push_back(5.1);
	dist09.push_back(5.1);
	dist09.push_back(5.8);
	dist09.push_back(5.7);
	dist09.push_back(0);
	dist09.push_back(9.5);

	// Distances from winery 10
	vector<float> dist10;
	// The first distance is the winery number
	dist10.push_back(10);
	dist10.push_back(3.5);
	dist10.push_back(11);
	dist10.push_back(17.2);
	dist10.push_back(13.2);
	dist10.push_back(12.1);
	dist10.push_back(14.2);
	dist10.push_back(4);
	dist10.push_back(4.7);
	dist10.push_back(9.5);
	dist10.push_back(0);

	// All the distances in one vector
	vector< vector<float> > list;
	list.push_back(dist00);
	list.push_back(dist01);
	list.push_back(dist02);
	list.push_back(dist03);
	list.push_back(dist04);
	list.push_back(dist05);
	list.push_back(dist06);
	list.push_back(dist07);
	list.push_back(dist08);
	list.push_back(dist09);
	list.push_back(dist10);

	vector<int> path;
	path.push_back(0);
	path.push_back(1);
	path.push_back(2);
	path.push_back(3);
	path.push_back(4);

	cout << "The shortest distance is: "
		 << shortest(list, path);

	cout << "\n\nTaking the route\n";

	reverse (path.begin(), path.end());

	while (!path.empty())
	{
		cout << path.back() << ", ";
		path.pop_back();
	}

	return 0;
}
