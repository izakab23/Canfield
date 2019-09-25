/*********************************************************************
  Author:        Izak Bounds
  Class:         C243 Data Structures
  File name:     Queue.cc
  Last updated:  September 2019
  Description:   Implementation of a class queue derived from a list.
**********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "Queue.h"

// Default constructor
Queue::Queue()
    : List()
{
} // Queue::Queue()

// Insert an object into the queue.
void Queue::enqueue(int data)
{
    insertBack(data);
} // void Queue::enqueue()

// Remove the front object and return its value.
int Queue::dequeue()
{
    int result = *begin();
    removeFront();
    return result;
} // int dequeue()

// Inspect the value of the front object.
int Queue::front()
{
    if (!isEmpty()) 
        return *begin();
    else
    {
        cout << "Attempt to access the front of an empty queue" << endl;
        exit(1);
    }
} // int Queue::front()

// Delete all the objects in the queue.
void Queue::makeEmpty()
{
    List::makeEmpty(); 
} // void Queue::makeEmpty()

// Test if the queue is empty.
bool Queue::isEmpty()
{
        return List::isEmpty();
} // bool Queue::isEmpty()

// Concatenate two queues.
void Queue::concatenate(Queue &other)
{
    List::concatenate(other);
} // void Queue::concatenate()

// The number of objects in the queue.
int Queue::stored()
{
    return getSize();
} // int Queue::stored()



