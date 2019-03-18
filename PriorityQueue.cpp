/*
 * PriorityQueue.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

#include "PriorityQueue.h"


PriorityQueue::PriorityQueue()
{
    length = 0;
    head = NULL;
}

void PriorityQueue::enqueue(const char& chr, const unsigned& frequency)
{
    PQ_node* new_node = new PQ_node();
    new_node->chr = chr;
    new_node->frequency = frequency;
    new_node->next = NULL;

    if(is_empty())
    {
        head = new_node;
    }
    else
    {
        PQ_node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = new_node;
    }
    length++;
}

void PriorityQueue::enqueue(const FrequencyCounter& obj)
{
    PQ_node* new_node = new PQ_node();
    new_node->chr = obj.get_letter();
    new_node->frequency = obj.get_frequency();
    new_node->next = NULL;

    if(is_empty())
    {
        head = new_node;
    }
    else
    {
        PQ_node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = new_node;
    }
    length++;
}

void PriorityQueue::dequeue()
{
    if(is_empty())
    {
        cout<<"Empty, cant dequeue"<<endl;
    }
    else
    {
        PQ_node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }
}

PQ_node& PriorityQueue::top() const
{
  if(is_empty())
  {
      cout<<"Empty cant return top"<<endl;
  }
  else
  { 
      return *head;
  }
}

bool PriorityQueue::is_empty() const
{
    return (head==NULL);
}

unsigned PriorityQueue::get_length() const
{
  return length;
}


PriorityQueue::~PriorityQueue()
{
    PQ_node* prev = head;
    PQ_node* curr = head;
    while(curr!=NULL)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    head = NULL;
}
