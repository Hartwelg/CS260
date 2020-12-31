//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>

#include "MySet.h"

using namespace std;

//assumes x is in range [0-999]
string intTo3DigitString(int x) {
	stringstream s;
	s << setw(3) << setfill('0') << x;
	return s.str();
}

//Returns a vector containing all valid IP addresses starting with 192.168
vector<string> getLocalIPs() {
	string prefix = "192.168";
	
	vector<string> localIPs;
	
	for(int i = 0; i < 256; i++) {
		string thirdSegment = "." + intTo3DigitString(i);
		for(int j = 0; j < 256; j++) {
			string fourthSegment = "." + intTo3DigitString(j);
			localIPs.push_back(prefix + thirdSegment + fourthSegment);
		}
	}
		
	return localIPs;
}


int main()
{
    cout << "--------part 1--------" << endl;

    int size;
    cout << "enter size" << endl;
    cin >> size;
    MySet<string> setA;

    ifstream inFile("IPListA.txt");
    if( !inFile.is_open() ) {
       cout << "Error opening file" << endl;
       return 1;
    }
    string address;

    for (int i = 0; i < size; i++)
    {
        inFile >> address;
        setA.add(address);
    }

    setA.print();

    cout << "Depth of tree is: " << setA.depth() << endl;

    cout << "--------part 2--------" << endl;

    cout << setA.getSmallest() << endl;

    cout << "--------part 3--------" << endl;

    MySet<string> setA2(setA);

    for (int i = 0; i < 10; i++)
    {
        SetNode<string> temp = setA2.removeLargest();
        cout << temp.data << endl;
    }

    cout << "--------part 4--------" << endl;

    MySet<string> setA3(setA);

    vector<string> local = getLocalIPs();

    for (vector<string>::iterator it = local.begin(); it != local.end(); it++)
    {
        string current = *it;
        if (setA3.contains(current))
        {
            setA3.remove(current);
        }
    }
    cout << setA3.size() << endl;

    cout << "--------part 5--------" << endl;

    MySet<string> setB;

    ifstream inFileB("IPListB.txt");
    if( !inFile.is_open() ) {
       cout << "Error opening file" << endl;
       return 1;
    }

    for (int i = 0; i < size; i++)
    {
        inFileB >> address;
        setB.add(address);
    }

    MySet<string> setAB = setA.intersectionWith(setB);

    cout << setAB.size() << endl;
    cout << setAB.getSmallest() << endl;
}
