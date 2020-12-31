//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "AddressLinkedList.h"
//#include <iostream>

AddressListNode::AddressListNode() {
    next = nullptr;
    //data will be default initialized
}

AddressListNode::AddressListNode(const Address& value)
    : data(value)
{
    next = nullptr;
}
AddressLinkedList::AddressLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}
AddressLinkedList::AddressLinkedList(const AddressLinkedList& other)
{
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
    AddressListNode* temp = other.head;
    for (int i = 0; i < other.length; i++)
    {
        this->insertEnd(temp->data);
        temp = temp->next;
    }
}
AddressLinkedList::~AddressLinkedList()
{
    AddressListNode* temp = this->head;
    while (this->head != NULL)
    {
        this->head = this->head->next;
        delete temp;
        temp = head;
    }
}

int AddressLinkedList::listSize() const
{
    return this->length;
}
Address AddressLinkedList::removeFirst()
{
    AddressListNode* temp;
    temp = this->head;
    this->head = this->head->next;
    this->length--;
    return temp->data;
}
void AddressLinkedList::printRange(int startIndex, int endIndex) const
{
    AddressListNode* current = this->head;

    if (endIndex > this->length - 1)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (i >= startIndex)
            {
                std::cout << current->data << std::endl;
            }
            current = current->next;
        }
    }
    else
    {
        for (int i = 0; i <= endIndex; i++)
        {
            if (i >= startIndex)
            {
                std::cout << current->data << std::endl;
            }
            current = current->next;
        }
    }

}
void AddressLinkedList::insertStart(const Address &value)
{
    AddressListNode* temp = new AddressListNode(value);
    temp->next = this->head;
    this->head = temp;

    if (this->head->next == nullptr)
    {
        this->tail = this->head;
    }
    this->length++;
}
void AddressLinkedList::insertEnd(const Address &value)
{
    AddressListNode* temp = new AddressListNode(value);
    if (this->length == 0)
    {
        delete temp;
        insertStart(value);
        return;
    }
    this->tail->next = temp;
    this->tail = temp;
    this->length++;
}
void AddressLinkedList::combine(AddressLinkedList &other)
{
    int size = other.length;
    AddressListNode* temp = other.head;
    for (int i = 0; i < size; i++)
    {
        this->insertEnd(temp->data);
        other.head = other.head->next;
        delete temp;
        temp = other.head;
        other.length--;
    }
}
AddressLinkedList AddressLinkedList::extractAllMatches(const Address &itemToMatch)
{
    AddressLinkedList temp;
    AddressListNode* current = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (current->data.state == itemToMatch.state)
        {
            temp.insertEnd(current->data);
            this->length--;
        }
    }
    return temp;
}
void AddressLinkedList::interleave(AddressLinkedList &other)
{
    AddressLinkedList* temp = new AddressLinkedList;
    AddressListNode* currentA = this->head;
    AddressListNode* currentB = other.head;
    int size = this->length;
    for (int i = 0; i < size; i++)
    {
        temp->insertEnd(currentA->data);
        this->head = this->head->next;
        temp->insertEnd(currentB->data);
        other.head = other.head->next;
        delete currentA;
        delete currentB;
        currentA = this->head;
        currentB = other.head;
        this->length--;
        other.length--;
    }
    AddressListNode* tempCurrent = temp->head;
    for (int i = 0; i < temp->length; i++)
    {
        this->insertEnd(tempCurrent->data);
        tempCurrent = tempCurrent->next;
    }
    delete temp;
}
