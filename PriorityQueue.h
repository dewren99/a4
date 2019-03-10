/*
 * PriorityQueue.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include "Node.h"

template <class T>
class PriorityQueue
{

public:
  PriorityQueue();

  void enqueue();
  void dequeue();
  T top() const;

  unsigned get_length() const;

  ~PriorityQueue();

private:
  unsigned length;
  Node<T> *head;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{

}

template <class T>
void PriorityQueue<T>::enqueue()
{

}

template <class T>
void PriorityQueue<T>::dequeue()
{

}

template <class T>
T PriorityQueue<T>::top() const
{
  if(head)
  {
    return head->data;
  }
}

template <class T>
unsigned PriorityQueue<T>::get_length() const
{
  return length;
}



template <class T>
PriorityQueue<T>::~PriorityQueue()
{

}
