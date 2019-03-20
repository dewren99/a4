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

// PQ_node::PQ_node()
// {
// }

// PQ_node::PQ_node(char chr, unsigned frequency)
// {
//     this->chr = chr;
//     this->frequency = frequency;
// }

PriorityQueue::PriorityQueue()
{
    size = 0;
    head = NULL;
}

void PriorityQueue::enqueue(const char &chr, const unsigned &frequency)
{
    Node *new_node = new Node();
    new_node->chr = chr;
    new_node->frequency = frequency;
    new_node->next = NULL;

    if (is_empty())
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    size++;
}

void PriorityQueue::enqueue(const char &chr, const string &prefix_code)
{
    Node *new_node = new Node();
    new_node->chr = chr;
    new_node->prefix_code = prefix_code;
    new_node->next = NULL;

    if (is_empty())
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    size++;
    // Node *node = new Node();
    // node->chr = chr;
    // node->prefix_code = prefix_code;
    // node->next = NULL;
    // if (head == NULL)
    // {
    //     head = node;
    //     size++;
    // }
    // else if (node->chr < head->chr)
    // {
    //     head = node;
    //     size++;
    // }
    // else
    // {
    //     Node *prev = head;
    //     Node *curr = head->next;

    //     while (curr != NULL && node->chr >= curr->chr)
    //     {
    //         prev = curr;
    //         curr = curr->next;
    //     }

    //     node->next = curr;
    //     prev->next = node;
    //     size++;
    // }
}

// Implemented to give more options to the programmer
void PriorityQueue::enqueue(const FrequencyCounter &obj)
{
    Node *new_node = new Node();
    new_node->chr = obj.get_letter();
    new_node->frequency = obj.get_frequency();
    new_node->next = NULL;

    if (is_empty())
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    size++;
}

void PriorityQueue::enqueue(Node *node)
{
    //Node *new_node = new Node();
    // new_node->chr = node.chr;
    // new_node->frequency = node.frequency;
    // new_node->next = NULL;

    if (head == NULL)
    {
        head = node;
        size++;
    }
    else if (node->frequency < head->frequency)
    {
        head = node;
        size++;
    }
    else
    {
        Node *prev = head;
        Node *curr = head->next;

        while (curr != NULL && node->frequency >= curr->frequency)
        {
            prev = curr;
            curr = curr->next;
        }

        node->next = curr;
        prev->next = node;
        size++;
    }
    // Node *new_node = new Node();
    // new_node->chr = node.chr;
    // new_node->frequency = node.frequency;
    // new_node->next = NULL;

    // if (is_empty())
    // {
    //     head = new_node;
    // }
    // else
    // {
    //     Node *temp = head;
    //     while (temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = new_node;
    // }
    // size++;
}

Node *PriorityQueue::dequeue()
{
    if (is_empty())
    {
        return NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        size--;
        return temp;
    }
}

// Node *PriorityQueue::top() const
// {
//     if (!is_empty())
//     {
//         return head;
//     }
// }

bool PriorityQueue::is_empty() const
{
    return (head == NULL);
}

unsigned PriorityQueue::get_size() const
{
    return size;
}

 string PriorityQueue::find_prefix_code(char chr) const
  {
      Node* temp = head;
      string found_prefix_code = "";
      while(temp != NULL)
      {
          if(temp->chr != chr)
          {
              temp = temp->next;
          }
          else
          {
              found_prefix_code = temp->prefix_code;
              break;
          }
      }
      return found_prefix_code;
  }

PriorityQueue::~PriorityQueue()
{
    Node *prev = head;
    Node *curr = head;
    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    head = NULL;
}
