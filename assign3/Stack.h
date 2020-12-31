//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef STACK_H
#define STACK_H

#include <iostream>


//Turn loops off for the duration of this file. 
//You are to use recursion for any repetition.
//Make sure to do any other includes before these defines.
#define for DONOTUSETHIS
#define while DONOTUSETHIS
#define goto DONOTUSETHIS

/**
 * @brief List node for AddressLinkedList
 */
template <class T>
struct StackNode
{
    T data;
    StackNode* next;

    StackNode();
    StackNode(const T& value);
};


/**
 * @brief Stack based on a linked list
 */
template <class T>
class Stack
{
private:
    StackNode<T>* top;

public:
    /**
     * @brief Construct empty stack
     */
    Stack();

    /**
     * @brief Copy constructor
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Stack(const Stack<T>& other);

    /**
     * @brief Assignment Operator
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Stack<T>& operator=(const Stack<T>& other);

    /**
     * @brief listClear
     */
    void listClear();

    /**
     * @brief Destructor
     */
    ~Stack();

    /**
     * @brief Check if stack is empty
     * @return true if nothing in stack, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Add item to stack
     * @param value Item to push a copy of onto the stack
     */
    void push(const T& item);

    /**
     * @brief Remove and return top item from stack
     * @return Item that was at the top of the stack
     * Can throw exception/blow up with assertion if currently empty
     */
    T pop();

    /**
     * @brief Return a copy of the top item on the stack (wihtout removing it)
     * @return Item that is at the top of the stack
     */
    T peek() const;

    /**
     * @brief Output the stack in order to cout
     */
    void print() const;
	 
    /**
     * @brief print helper
     */
    void recursivePrint(const StackNode<T>* node) const;
    /**
     * @brief Output the stack in reverse order to cout
     */
    void reversePrint() const;
    /**
     * @brief reversePrint helper
     * @param node
     */
    void reverseRecursivePrint(const StackNode<T>* node) const;
};


//--------------------------------------------------------------------
// StackNode implementations
//--------------------------------------------------------------------

template <class T>
StackNode<T>::StackNode() {
    next = nullptr;
    data = T(); //data will be default initialized
}

template <class T>
StackNode<T>::StackNode(const T& value)
    : data(value)
{
    next = nullptr;
}

//--------------------------------------------------------------------
// Stack Implementations
//--------------------------------------------------------------------
/**
 * @brief Construct empty stack
 */
template <class T>
Stack<T>::Stack()
{
    this->top = NULL;
}

/**
 * @brief Copy constructor
 *
 * Implement if you need it, otherwise not required
 * Declared to prevent default shallow copy
 */
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{

}

/**
 * @brief Assignment Operator
 *
 * Implement if you need it, otherwise not required
 * Declared to prevent default shallow copy
 */
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{

}
/**
 * @brief listClear
 */
template <class T>
void Stack<T>::listClear()
{
    if (this->top == NULL)
    {
        return;
    }
    StackNode<T>* temp = this->top;
    this->top = this->top->next;
    delete temp;
    listClear();
}

/**
 * @brief Destructor
 */
template <class T>
Stack<T>::~Stack()
{
    if (this->top != NULL)
    {
        listClear();
    }
}

/**
 * @brief Check if stack is empty
 * @return true if nothing in stack, false otherwise
 */
template <class T>
bool Stack<T>::isEmpty() const
{
    if (this->top == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Add item to stack
 * @param value Item to push a copy of onto the stack
 */
template <class T>
void Stack<T>::push(const T& item)
{

    StackNode<T>* temp = new StackNode<T>(item);
    if (this->top == NULL)
    {
        this->top = temp;
    }
    else
    {
        temp->next = this->top;
        this->top = temp;
    }
}

/**
 * @brief Remove and return top item from stack
 * @return Item that was at the top of the stack
 * Can throw exception/blow up with assertion if currently empty
 */
template <class T>
T Stack<T>::pop()
{
    StackNode<T>* temp = this->top;
    if (this->top->next == nullptr)
    {
        return 0;
    }
    this->top = top->next;

    return temp->data;
}

/**
 * @brief Return a copy of the top item on the stack (wihtout removing it)
 * @return Item that is at the top of the stack
 */
template <class T>
T Stack<T>::peek() const
{
    return this->top->data;
}

template <class T>
void Stack<T>::recursivePrint(const StackNode<T>* node) const
{
    if (node->next == NULL)
    {
        std::cout << node->data << " ";
        return;
    }
    else
    {
        std::cout << node->data << " ";
        recursivePrint(node->next);
    }
}

/**
 * @brief Output the stack in order to cout
 */
template <class T>
void Stack<T>::print() const
{
    StackNode<T>* temp = this->top;
    this->recursivePrint(temp);
}

template <class T>
void Stack<T>::reverseRecursivePrint(const StackNode<T>* node) const
{
    if (node->next == NULL)
    {
        std::cout << node->data << " ";
        return;
    }
    else
    {
        reverseRecursivePrint(node->next);
        std::cout << node->data << " ";
    }
}
/**
 * @brief Output the stack in reverse order to cout
 */
template <class T>
void Stack<T>::reversePrint() const
{
    StackNode<T>* temp = this->top;
    this->reverseRecursivePrint(temp);
}


//--------------------------------------------------------------------
// All your code before here
//--------------------------------------------------------------------
//Turn loops back on.
//Otherwise whatever file includes this will not be able to use them.
#undef for
#undef while
#undef goto

#endif // STACK_H
