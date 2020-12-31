//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>

//Node node for Set
template <class T>
struct SetNode
{
    T data;
    SetNode<T>* left;
    SetNode<T>* right;

    SetNode(const T& value);
};


//Set based on a BST
template <class T>
class MySet
{
private:
    SetNode<T>* root;

public:
    //Construct empty set
    MySet();

    //Copy constructor helper
    SetNode<T> *copy(SetNode<T> *other);

    //Copy constructor
    MySet(const MySet<T>& other);

    //Assignment Operator
    MySet<T>& operator=(const MySet<T>& other);

    //Destructor Helper
    void deleteSub(SetNode<T>* current);

    //Destructor
    ~MySet();

    //size helper
    int sizeHelper(SetNode<T>* current) const;

    //get number of items contained
    int size() const;

    //depth helper
    int depthHelper(SetNode<T> *temp) const;

    //get depth of underlying tree
    int depth() const;

    //add helper
    SetNode<T>* addHelper(SetNode<T> *temp, const T& item);

    //Add item to set
    //  Duplicate items will be ignored
    void add(const T& item);

    //contains helper
    bool containsHelper(const SetNode<T> *temp, const T& item) const;

    //Check if item is in the set
    bool contains(const T& item) const;

    //retreive smallest value relative to current node
    T getSmallestFrom(SetNode<T>* other);

    //remove helper
    SetNode<T>* removeHelper(SetNode<T>* current, T value);

    //Remove given item from the set if it exists
    void remove(const T& item);

    //returns the smallest item from the set (does not remove it)
    T getSmallest() const;
	
    //remove largest helper
    T removeLargestHelper(SetNode<T>* temp, SetNode<T> *prev) const;

    //removes the largest item from the set and returns it
    T removeLargest() const;

    //Generates a new set containing all the items that are in both
    //  this set and another set
    //  intersections of {A, B, C, D} and {B, D, F} would be {B, D}
	//  Both original sets are left unmodified
    MySet<T> intersectionWith(const MySet<T>& other) const;

    //Returns a vector of items in the set that are >= start and < end
    std::vector<T> getRange(const T& startValue, const T& endValue) const;

    //print function helper
    void printHelper(SetNode<T>* current);

    //print function
    void print();

};


//--------------------------------------------------------------------
// SetNode implementations
//--------------------------------------------------------------------

template <class T>
SetNode<T>::SetNode(const T& value)
    : data(value)
{
    left = nullptr;
    right = nullptr;
}

//--------------------------------------------------------------------
// Set Implementations
//--------------------------------------------------------------------

//Construct empty
template <class T>
MySet<T>::MySet()
{
    this->root = nullptr;
}

//Copy constructor helper
template <class T>
SetNode<T>* MySet<T>::copy(SetNode<T>* other)
{
    if (other == nullptr)
    {
        return nullptr;
    }
    SetNode<T>* temp = new SetNode<T>(other->data);
    temp->left = copy(other->left);
    temp->right = copy(other->right);
    return temp;
}

//Copy constructor
template <class T>
MySet<T>::MySet(const MySet<T>& other)
{
    this->root = copy(other.root);
}

//Assignment Operator
template <class T>
MySet<T>& MySet<T>::operator=(const MySet<T>& other)
{
    if (this != &other)
    {
        deleteSub(this->root);
        this->root = copy(other.root);
    }
    return *this;
}

//Destructor helper
template <class T>
void MySet<T>::deleteSub(SetNode<T>* current)
{
    if (current == nullptr)
    {
        return;
    }
    deleteSub(current->left);
    deleteSub(current->right);
    delete current;
}

//Destructor
template <class T>
MySet<T>::~MySet()
{
    deleteSub(this->root);
}

//size helper
template <class T>
int MySet<T>::sizeHelper(SetNode<T>* current) const
{
    if (current == NULL)
    {
        return 0;
    }

    if (current->left != nullptr)
        return 1 + sizeHelper(current->left);
    if (current->right != nullptr)
        return 1 + sizeHelper(current->right);
}

//get number of items contained
template <class T>
int MySet<T>::size() const
{
    return sizeHelper(this->root);
}

//depth helper
template <class T>
int MySet<T>::depthHelper(SetNode<T>* temp) const
{
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        int leftSize = depthHelper(temp->left);
        int rightSize = depthHelper(temp->right);

        if (leftSize <= rightSize)
        {
            return rightSize + 1;
        }
        else
        {
            return leftSize + 1;
        }
    }
}

//get depth of underlying tree
template <class T>
int MySet<T>::depth() const
{
    return depthHelper(this->root);
}

//Add item to set
//  Duplicate items will be ignored
template <class T>
void MySet<T>::add(const T& item)
{
    if (this->root == NULL)
    {
        this->root = new SetNode<T>(item);
    }
    else
    {
        SetNode<T>* parent = this->root;
        SetNode<T>* current = this->root;
        while (current != nullptr)
        {
            parent = current;

            if (item < parent->data)
            {
                current = parent->left;
            }
            else
            {
                current = parent->right;
            }
        }
        if (item == parent->data)
        {
            return;
        }
        if (item < parent->data)
        {
            parent->left = new SetNode<T>(item);
        }
        else
        {
            parent->right = new SetNode<T>(item);
        }
    }
}

template <class T>
bool MySet<T>::containsHelper(const SetNode<T>* temp, const T& item) const
{
    if (temp == NULL)
    {
        return false;
    }
    else if (temp->data == item)
    {
        return true;
    }
    else if (item < temp->data)
    {
        return containsHelper(temp->left, item);
    }
    else
    {
        return containsHelper(temp->right, item);
    }
}
//Check if item is in the set
template <class T>
bool MySet<T>::contains(const T& item) const
{
    return containsHelper(this->root, item);
}

//get smallest of two values
template <class T>
T MySet<T>::getSmallestFrom(SetNode<T>* other)
{
    SetNode<T>* temp = other->left;
    while (temp != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

//remove helper
template <class T>
SetNode<T>* MySet<T>::removeHelper(SetNode<T>* current, T value)
{
    if (current == nullptr)
    {
        return nullptr;
    }
    else if (value < current->data)
    {
        current->left = removeHelper(current->left, value);
        return current;
    }
    else if (current->data < value)
    {
        current->right = removeHelper(current->right, value);
        return current;
    }
    else
    {
        if (current->right == nullptr)
        {
            SetNode<T>* temp = current->left;
            delete current;
            return temp;
        }
        else if (current->left == nullptr)
        {
            SetNode<T>* temp = current->right;
            delete current;
            return temp;
        }
        else
        {
            current->data = getSmallestFrom(current->right);
            removeHelper(current->right, current->data);
            return current;
        }
    }
}

//Remove given item from the set if it exists
template <class T>
void MySet<T>::remove(const T& item)
{
    this->root = removeHelper(this->root, item);
}

//returns the smallest item from the set (does not remove it)
template <class T>
T MySet<T>::getSmallest() const
{
    SetNode<T>* temp = this->root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

//remove Largest helper
template <class T>
T MySet<T>::removeLargestHelper(SetNode<T>* temp, SetNode<T>* prev) const
{
    if (temp == nullptr)
    {
        return 0;
    }
    if (temp->right == nullptr)
    {
        SetNode<T>* current = temp;
        prev->right = temp->left;
        T currentData = temp->data;
        delete temp;
        current->data = currentData;
        return current->data;
    }
    else
    {
        prev = temp;
        return removeLargestHelper(temp->right, prev);
    }
}
//removes the largest item from the set and returns it
template <class T>
T MySet<T>::removeLargest() const
{
    return removeLargestHelper(this->root, nullptr);
}

//Generates a new set containing all the items that are in both
//  this set and another set
//  intersections of {A, B, C, D} and {B, D, F} would be {B, D}
//  Both original sets are left unmodified
template <class T>
MySet<T> MySet<T>::intersectionWith(const MySet<T>& other) const
{
//    MySet<T> newSet;
//    SetNode<T>* temp = this->root;
//    SetNode<T>* temp2 = other.root;

//    if (temp == temp2)
//    {
//        newSet.add(temp);
//    }
//    else
//    {
//        temp = temp->left;
//    }
}

//Returns a vector of items in the set that are >= start and < end
template <class T>
std::vector<T> MySet<T>::getRange(const T& startValue, const T& endValue) const
{

}

//print helper
template <class T>
void MySet<T>::printHelper(SetNode<T> *current)
{
    if (current == NULL)
    {
        return;
    }
    printHelper(current->left);
    std::cout << current->data << std::endl;
    printHelper(current->right);
}
//print function
template <class T>
void MySet<T>::print()
{
    return printHelper(this->root);
}

#endif // MYSET_H
