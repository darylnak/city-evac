#include "QueueAr.h"

/**
 * Construct the queue.
 */
template <class Object>
Queue<Object>::Queue(int capacity) : size(capacity), currentSize(0), front(0), back(-1)
{
  theArray = new Object* [capacity];
}

/**
 * Test if the queue is logically empty.
 * Return true if empty, false otherwise.
 */
template <class Object>
bool Queue<Object>::isEmpty() const
{
  return currentSize == 0;
}

/**
 * Test if the queue is logically full.
 * Return true if full, false otherwise.
 */
template <class Object>
bool Queue<Object>::isFull() const
{
  return currentSize == size;
}

/**
 * Get the least recently inserted item in the queue.
 * Return the least recently inserted item in the queue
 * or throw Underflow if empty.
 */
template <class Object>
Object* Queue<Object>::getFront( ) const
{
  return theArray[front];
}

/**
 * Return and remove the least recently inserted item from the queue.
 * Throw Underflow if empty.
 */
template <class Object>
Object* Queue<Object>::dequeue( )
{
  currentSize--;
  Object* frontItem = theArray[front];
  increment(front);
  return frontItem;
}

/**
 * Insert x into the queue.
 * Throw Overflow if queue is full
 */
template <class Object>
void Queue<Object>::enqueue(Object* x )
{
  increment(back);
  theArray[back] = x;
  currentSize++;
}

/**
 * Internal method to increment x with wraparound.
 */
template <class Object>
void Queue<Object>::increment( int & x )
{
  if(++x == size)
    x = 0;
}