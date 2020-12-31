#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

//collaborated with abi

int main()
{
    Stack<char> s1;

    cout << "-------Part 1--------" << endl;
    s1.push('B');
    s1.push('A');
    s1.push('R');
    cout << s1.peek() << endl;
    s1.pop();
    s1.push('D');
    s1.print();
    cout << endl;
    s1.reversePrint();
    cout << endl;

    cout << "-------Part 3--------" << endl;

    Queue<char> q1;

    q1.enqueue('F');
    q1.enqueue('L');
    q1.enqueue('A');
    q1.dequeue();
    q1.enqueue('T');
    q1.print();

    q1.enqueue('E');
    q1.dequeue();
    q1.print();
    for (int i = 0; i < 1000; i++)
    {
        q1.enqueue('?');
    }
    for (int i = 0; i < 1000; i++)
    {
        q1.dequeue();
    }
    q1.print();
}
