/*
 * Node.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include <cstdio>

template <class T>

class Node
{
  public:
    T data;
    T *next;

    Node();
    Node(T data);
    Node(T data, T *next);
};

template <class T>
Node<T>::Node()
{
    next = NULL;
}

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    next = NULL;
}

template <class T>
Node<T>::Node(T data, T *next)
{
    this->data = data;
    this->next = next;
}