//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>

#include "Queue.h"
#include "Stack.h"

using namespace std;

bool possibleWords(string& current, string& next)
{
    int counter = 0;
    int length = current.length();

    for (int i = 0; i < length; i++)
    {
        if (current[i] != next[i])
        {
            counter++;
        }
        if (counter > 1)
        {
            return false;
        }
    }
    if (counter == 1)
    {
        return true;
    }
}

void findQueue(string& start, string& end)
{
    Queue<string> laddersToTry;

    laddersToTry.enqueue(start);

    while (!laddersToTry.isEmpty())
    {
        string temp = laddersToTry.dequeue();

        if (temp == end)
        {
            laddersToTry.print();
        }

        for (int i = 0; i < laddersToTry.getEnd(); i++)
        {
            string copy;

        }
    }
}
int main()
{
   string startWord, endWord;
   cout << "Enter the start word for your storage:";
   cin >> startWord;
   cout << "Enter the end word for your storage:";
   cin >> endWord;

   ifstream inFile("FiveLetterWords.txt");
   if( !inFile.is_open() ) {
      cout << "Error opening file" << endl;
      return 1;
   }

   vector<string> wordList;
   string word;

   while (!inFile.eof())
   {
       inFile >> word;
       wordList.push_back(word);
   }

//   Queue<string> storage;

//   storage.enqueue(startWord);

//   while (!storage.isEmpty())
//   {
//       string current = storage.dequeue();

//       if (current == endWord)
//       {
//           cout << current;
//           break;
//       }
//       for (vector<string>::iterator it = wordList.begin(); it != wordList.end(); it++)
//       {
//           string temp = *it;
//           if (possibleWords(current, temp))
//           {
//               storage.enqueue(temp);
//               storage.print();
//               break;
//           }

//       }
//   }

   //makes queue of related words
   Queue<string> ladder;

   ladder.enqueue(startWord);

   string current = ladder.front();

   while (!ladder.isEmpty())
   {
       for (vector<string>::iterator it = wordList.begin(); it != wordList.end(); it++)
       {
           string temp = *it;

           if (possibleWords(current, temp))
           {
               if (temp == current)
               {
                   wordList.erase(it);
                   break;
               }
               if (temp == endWord)
               {
                   ladder.enqueue(temp);
                   ladder.print();
                   exit(0);
               }
               ladder.enqueue(temp);
               wordList.erase(it);

               current = ladder.front();
               break;
           }
       }
   }
   //makes stack of related words
//   Stack<string> ladder;

//   ladder.push(startWord);

//   string current = ladder.peek();

//   while (!ladder.isEmpty())
//   {
//       for (vector<string>::iterator it = wordList.begin(); it != wordList.end(); it++)
//       {
//           string temp = *it;

//           if (possibleWords(current, temp))
//           {
//               if (temp == current)
//               {
//                   wordList.erase(it);
//                   break;
//               }
//               if (temp == endWord)
//               {
//                   ladder.push(temp);
//                   ladder.reversePrint();
//                   cout << endl;
//                   exit(0);
//               }
//               ladder.push(temp);
//               wordList.erase(it);

//               break;
//           }
//       }
//   }
}
