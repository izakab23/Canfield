/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
                 Izak Bounds
  Class:         C243 Data Structures
  File name:     ListIterator.cc
  Last updated:  September 3, 2019
  Description:   Definition of the list iterator class.
**********************************************************************/

#include "ListIterator.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// Default constructor. We need to make sure the pointer current is
// initialized to NULL.
ListIterator::ListIterator()  
    : current(NULL)
{
} // ListIterator::ListIterator()

// Constructor from a ListNode pointer.
ListIterator::ListIterator(ListNode *link)
{
    current = link; // just store the pointer in the target object
} // ListIterator::ListIterator()

// Assignment operator with a ListNode pointer
ListNode *ListIterator::operator=(ListNode *link)
{
    current = link; // store the pointer in the target object
    return current; // then return it
} // ListIterator::operator=()

// Operator to advance the pointer.
ListIterator &ListIterator::operator++()
{
    if (current)                 // if the pointer is not null
        current = current->next; // move it to the next node
    return *this;
} // ListIterator::operator++()

// Operator to access the content of the node. If the pointer is null, 
// it exits the program with an error message.
int &ListIterator::operator*()
{
    if (current)               // if the pointer is not null
        return current->datum; // return the datum
    else  // error
    {
        cerr << "Attempting to dereference an empty iterator" << endl;
        exit(1);
    }
} // ListIterator::operator*()

// Operator to check if the pointer is not null.
ListIterator::operator bool()
{
    return (current != NULL); // return true if the pointer is not null
} // ListIterator::operator bool()

// Operator to convert to a ListNodePtr.
ListIterator::operator ListNodePtr()
{
    return current; 
} // ListIterator::operator ListNodePtr()

// Swaps the content of the target object with the other iterator if
// they are both not null. If one of them is null the function returns
// false, otherwise true.
bool ListIterator::swap(ListIterator &other)
{
    if (current && other) // if neither node is NULL
    {
        // swap the datums
        int temp = current->datum;
        current->datum = *other;
        *other = temp;

        return true;  // success
    }
    else
        return false; // failure
} // ListIterator::swap()

// Comparison operator.
bool ListIterator::operator==(ListIterator &data)
{
    // just compare the pointers
    return (current == data.current);
} // ListIterator::operator==()

// Functions to be implemented by the student.

// It locates the minimum in the list starting from the target object
// and returns a list iterator containing a pointer to this node.
// This function should NOT modify the target object, meaning that 
// it should not change the pointer current. 
// This is an accessor function. 
ListIterator ListIterator::min()
{
    if (!current)
        return ListIterator(NULL);
    ListNodePtr temp = current->next;
    ListNodePtr min = current; // min is set to the current incase it is already the min value
    do
    {
        if (min->datum > temp->datum) // checks if temp is less than the current min
        {
            min = temp;
        }
        temp = temp->next; // increments temp
    } while (temp != NULL); // temp is still in the list

    return min;

} // ListIterator::min()

// This operator should move the iterator forward by a number of nodes
// indicated by the parameter. If there are not enough nodes to skip
// that many steps forward, the current pointer should be made NULL.
// This is a mutator function, it changes the target object.
ListIterator &ListIterator::moveForward(int steps)
{
    for (int i = 0; i < (steps); i++) // counts total steps
    {
        if (*this != NULL) // if the this is not NULL
            this->current = this->current->next;
        else
            return *this; // if the next step is NULL, return NULL;
            //NOTE: I tried to increment this until it was equal to NULL and return that but my program kept crashing.
    }

    return *this;
} // ListIterator::moveForward()