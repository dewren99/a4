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

void PriorityQueue::enqueue(const Node& node)
{
    Node *new_node = new Node();
    new_node->chr = node.chr;
    new_node->frequency = node.frequency;
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


void PriorityQueue::dequeue()
{
    if (is_empty())
    {
        return;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

Node* PriorityQueue::top() const
{
    if(!is_empty())
    {
        return head;
    }
}

bool PriorityQueue::is_empty() const
{
    return (head == NULL);
}

unsigned PriorityQueue::get_size() const
{
    return size;
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
