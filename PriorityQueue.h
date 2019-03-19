/*
 * PriorityQueue.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

#pragma once


#include "Node.h"

// class PQ_node
// {
// public:
//   char chr;
//   unsigned frequency;
//   PQ_node *next;

//   PQ_node();
//   PQ_node(char chr, unsigned frequency);
// };

class PriorityQueue
{

public:
  PriorityQueue();

  void enqueue(const char &chr, const unsigned &frequency);
  void enqueue(const FrequencyCounter &obj);
  void enqueue(const Node& node);

  void dequeue();

  Node* top() const;

  bool is_empty() const;

  unsigned get_size() const;

  ~PriorityQueue();

void print(){ Node* temp = head; while(temp!=NULL){ cout<< temp->chr<<' '<<temp->frequency<<endl; temp = temp->next; }};

private:
  unsigned size;
  Node *head;
};
