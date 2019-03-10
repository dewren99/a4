
#include "Node.h"

template <class T>
class PriorityQueue
{

  public:
  PriorityQueue();
  
  void enqueue();
  void dequeue();
  void top();

  void set_length(const unsigned length);

  int get_length() const;

  private:
    unsigned length;
    Node<T>* head;
};
