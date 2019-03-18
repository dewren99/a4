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
#include "FrequencyCounter.h"

class PQ_node
{
public:
  char chr;
  unsigned frequency;
  PQ_node *next;
};

class PriorityQueue
{

public:
  PriorityQueue();

  void enqueue(const char& chr, const unsigned& frequency);
  void enqueue(const FrequencyCounter& obj);

  void dequeue();
  
  PQ_node& top() const;

  bool is_empty() const;

  unsigned get_length() const;

  ~PriorityQueue();

private:
  unsigned length;
  PQ_node *head;
};
