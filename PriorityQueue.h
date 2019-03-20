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

  // Enqueue Function Overloading for more flexiblity and convenience
  void enqueue(const char &chr, const unsigned &frequency);
  void enqueue(const char &chr, const string &prefix_code);
  void enqueue(const FrequencyCounter &obj);
  void enqueue(Node *node);

// returns top
  Node *dequeue();

// Checks if priority queue empty
  bool is_empty() const;

  // Getters
  unsigned get_size() const;

  // Searching the prefix code of the chr inside the priority queue
  string find_prefix_code(char chr) const;
  
  // Printing the Priority Queue for prefix code table
  void print() const;

// Destructor
  ~PriorityQueue();

private:
  unsigned size;
  Node *head;
};
