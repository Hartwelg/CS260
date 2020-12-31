//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>

#include "Stack.h"

using namespace std;

int main()
{
   ifstream inFile("Document.html");
   if( !inFile.is_open() ) {
      cout << "Error opening file" << endl;
      return 1;
   }

    Stack<string> s1;
    string tag = "";

    while (!inFile.eof())
    {
        inFile >> tag;

        if (tag.find('/') == true) //end tag
        {
            string opening = s1.peek().substr(1);
            string closing = tag.substr(2);
            if (opening.compare(closing) != 0)
            {
                cout << "NO" << endl;
                return false;
            }
            else
            {
                s1.pop();
            }
        }
        else if (tag.substr(0, 1) == "<") //start tag
        {
            s1.push(tag);
        }
        else //word
        {
            s1.reversePrint();
            cout << tag << endl;
            cout << endl;
        }
    }
}
