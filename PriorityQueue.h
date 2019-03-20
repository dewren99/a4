/*
 * PriorityQueue.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#pragma once

#include "Node.h"



class PriorityQueue
{

public:

// Default Constructor
  PriorityQueue();

// Parameterized Constructor
  void enqueue(const char &chr, const unsigned &frequency); 
  void enqueue(const char &chr, const string &prefix_code);
  void enqueue(const FrequencyCounter &obj);
  void enqueue(Node* node);

  Node* dequeue();

  bool is_empty() const;

  unsigned get_size() const;

string find_prefix_code(char chr) const;

  ~PriorityQueue();

void print(){ Node* temp = head; while(temp!=NULL){ cout<< temp->chr<<' '<<temp->prefix_code<<endl; temp = temp->next; }};

private:
  unsigned size;
  Node *head;
};
