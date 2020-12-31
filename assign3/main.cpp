#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<char> s1;

    cout << "-------Part 1--------" << endl;
    s1.push('B');
    s1.push('A');
    s1.push('R');
    cout << s1.peek() << endl;
//    s1.pop();
//    s1.push('D');
//    s1.print();
//    s1.reversePrint();
}
