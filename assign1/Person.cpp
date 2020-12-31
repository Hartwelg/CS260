//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include "Person.h"

using namespace std;

bool operator==(const Person& p1, const Person& p2){
    if(p1.kNum == p2.kNum)
        return true;
    else
        return false;
}

bool operator>(const Person& p1, const Person& p2)
{
    return p1 > p2;
}
bool operator<(const Person& p1, const Person& p2)
{
    return p1 < p2;
}
void partialZipSort(Person* array, int start, int end) {
    for (int i = 1; i < end - 1; ++i)
    {
        int k = i;
        while (k > start && array[k].zipCode < array[k - 1].zipCode)
        {
            swap(array[k - 1], array[k]);
            k--;
        }
    }
}
void MergeList(Person* array, int low, int mid, int high, Person* temp)
{
    int left = low;
    int right = mid + 1;
    int combined = low;

    while (left <= mid && right <= high)
    {
        if (array[left].last < array[right].last)
        {
            temp[combined++] = array[left++];
        }
        else if (array[left].last == array[right].last)
        {
            if (array[left].first > array[right].first)
            {
                temp[combined++] = array[right++];
            }
            else
            {
                temp[combined++] = array[left++];
            }
        }
        else
        {
            temp[combined++] = array[right++];
        }
    }

    if (left == mid + 1)
    {
        while (right <= high)
        {
            temp[combined++] = array[right++];
        }
    }
    else
    {
        while (left <= mid)
        {
            temp[combined++] = array[left++];
        }
    }

    for (int i = low; i <= high; i++)
    {
        array[i] = temp[i];
    }
}
void MergeSort(Person* array, int low, int high, Person* temp)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(array, low, mid, temp);
    MergeSort(array, mid + 1, high, temp);
    MergeList(array, low, mid, high, temp);
}
void nameSort(Person* array, int size) {
    Person* temp = new Person[size];
    MergeSort(array, 0, size - 1, temp);
    delete [] temp;
}

int countLastName(const std::string& lastName, const Person* array, int size) {
    int numNames = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i].last == lastName)
        {
            numNames++;
        }
    }
    return numNames;
}

int binaryFindFirstByLastName(const std::string& value, const Person* array, int size) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid].last > value)
        {
            high = mid - 1;
        }
        else if (array[mid].last < value)
        {
            low = mid + 1;
        }
        else
        {
            while (array[mid - 1].last == array[mid].last)
            {
                if (mid <= 1)
                {
                    return 0;
                }
                mid--;
            }
            return mid;
        }
    }
    return -1;
}



int binaryFindLastByLastName(const std::string& value, const Person* array, int size) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid].last > value)
        {
            high = mid - 1;
        }
        else if (array[mid].last < value)
        {
            low = mid + 1;
        }
        else
        {
            while (array[mid + 1].last == array[mid].last)
            {
                mid++;
            }
            return mid;
        }
    }
    return -1;
}


int countLastNameInSorted(std::string lastName, const Person* array, int size) {
	//TODO
    int low = binaryFindFirstByLastName(lastName, array, size);
    int high = binaryFindLastByLastName(lastName, array, size);
    int count = high - low;
    return count + 1;
}
