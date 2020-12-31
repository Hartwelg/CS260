//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <ctime>

#include "Address.h"
#include "ArrayList.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"

using namespace std;


int main()
{
    int size = 0;
    cout << "Enter problem size:" << endl;
    cin >> size;

    ArrayList<Address> aListA;
    ArrayList<Address> aListB;

    AddressFactory aFactory("25000AddressesA.txt");
    AddressFactory aFactory2("25000AddressesB.txt");

    for(int i = 0; i < size / 2; i++) {
        Address a = aFactory.getNext();
        aListA.insertEnd(a);
        Address a2 = aFactory2.getNext();
        aListB.insertEnd(a2);
    }
    
    cout << "---------Part 1---------" << endl;
    clock_t startTime = clock();

    aListA.combine(aListB);

    clock_t clockDuration = startTime - clock();
    double seconds = 1.0 * clockDuration / CLOCKS_PER_SEC;

    cout << "In " << seconds << " seconds, " << endl;

    cout << "Size of aListA: " << aListA.listSize() << endl;
    cout << "Size of aListB: " << aListB.listSize() << endl;

    int low = size / 2 - 2;
    int high = size / 2 + 1;

    for (int i = low; i <= high; i++)
    {
        cout << aListA.retrieveAt(i);
    }

    cout << "---------Part 2---------" << endl;
    Address theAddress;
    theAddress.state = "OR";

    ArrayList<Address> aListC = aListA.extractAllMatches(theAddress);

    cout << "Length of aListA: " << aListA.listSize() << endl;
    cout << "Length of aListC: " << aListC.listSize() << endl;

    cout << "---------Part 3---------" << endl;
    AddressFactory AFact1("25000AddressesA.txt");
    AddressFactory AFact2("25000AddressesB.txt");

    AddressLinkedList LinkListA;
    AddressLinkedList LinkListB;

    for(int i = 0; i < size / 2; i++) {
        Address a = AFact1.getNext();
        LinkListA.insertEnd(a);
        Address a2 = AFact2.getNext();
        LinkListB.insertEnd(a2);
    }
    cout << "Linked List A " << endl;
    LinkListA.printRange(3, 5);
    cout << endl;
    cout << "Linked List B " << endl;
    LinkListB.printRange(3, 5);

    cout << "---------Part 4---------" << endl;
    AddressLinkedList LinkListC = AddressLinkedList(LinkListA);
    AddressLinkedList LinkListD = AddressLinkedList(LinkListB);

    LinkListC.combine(LinkListD);

    cout << "LinkListC Size: " << LinkListC.listSize() << endl;
    cout << "LinkListD Size: " << LinkListD.listSize() << endl;
    cout << endl;

    LinkListC.printRange(size / 2 - 2, size / 2 + 1);

    cout << "---------Part 5---------" << endl;
    Address Item;
    Item.state = "OR";
    AddressLinkedList LinkListE = LinkListC.extractAllMatches(Item);

    cout << "LinkListC size: " << LinkListC.listSize() << endl;
    cout << "LinkListE size: " << LinkListE.listSize() << endl;

    LinkListE.printRange(0, 1);

    cout << "---------Part 6---------" << endl;

    LinkListA.interleave(LinkListB);
    LinkListA.printRange(0, 4);
    return 0;
}
