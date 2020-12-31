#include <iostream>
#include <fstream>
#include <ctime>
#include "Person.h"
using namespace std;

int main()
{
    cout << "-------------Part 1-------------" << endl;
    cout << "Enter a number of names to read in: " << endl;
    int numNames;
    cin >> numNames;
    ifstream infile("people.txt");
    string line;
    Person* theArray = new Person[numNames];

    for (int i = 0; i < numNames; i++)
    {
        getline(infile, line);

        Person student;

        student.kNum = line.substr(0, line.find_first_of(','));
        line.erase(0, line.find_first_of(',') + 1);

        student.last = line.substr(0, line.find_first_of(','));
        line.erase(0, line.find_first_of(',') + 1);

        student.first = line.substr(0, line.find_first_of(','));
        line.erase(0, line.find_first_of(',') + 1);

        student.zipCode = stoi(line);

        line.erase();

        theArray[i] = student;
    }

    cout << "-------------Part 2-------------" << endl;
    int nameNum = 0;
    clock_t startClock = clock();
    for (int i = 0; i < 100000; i++)
    {
        nameNum = countLastName("Mertz", theArray, numNames);
    }
    clock_t clockDuration = clock() - startClock;
    double seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;
    cout << "In " << seconds << " seconds" << endl;
    cout << nameNum << " last names of 'Mertz'" << endl;

    cout << "-------------Part 3-------------" << endl;

    partialZipSort(theArray, 2, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << theArray[i].last << " " << theArray[i].first << " " << theArray[i].zipCode << endl;
    }
    cout << "-------------Part 4-------------" << endl;
    startClock = clock();

    for (int i = 0; i < 100; i++)
    {
        nameSort(theArray, numNames);
    }

    clockDuration = clock() - startClock;
    seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;
    seconds /= 100;
    cout << "List sorted in " << seconds << " seconds" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << theArray[i].kNum << " " << theArray[i].last << " " << theArray[i].first << " " << theArray[i].zipCode << endl;
    }

    cout << "-------------Part 5-------------" << endl;
    cout << "First of last name 'Abbott'" << endl;
    cout << binaryFindFirstByLastName("Abbott", theArray, numNames) << endl;
    cout << "Last of last name 'Abbott'" << endl;
    cout << binaryFindLastByLastName("Abbott", theArray, numNames) << endl;
    cout << endl;
    cout << "First of last name 'Zulauf'" << endl;
    cout << binaryFindFirstByLastName("Zulauf", theArray, numNames) << endl;
    cout << "Last of last name 'Zulauf'" << endl;
    cout << binaryFindLastByLastName("Zulauf", theArray, numNames) << endl;

    cout << "-------------Part 6-------------" << endl;
    startClock = clock();

    for (int i = 0; i < 10000; i++)
    {
        countLastNameInSorted("Mertz", theArray, numNames);
    }

    clockDuration = clock() - startClock;
    seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;
    seconds /= 10000;
    cout << countLastNameInSorted("Mertz", theArray, numNames) <<  " Matching names found in " << seconds << " seconds" << endl;
}
