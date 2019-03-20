/*
 * PriorityQueue.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#include "PriorityQueue.h"

// Default Constructor
PriorityQueue::PriorityQueue()
{
    size = 0;
    head = NULL;
}

// Enqueue Function Overloading for more flexiblity and convenience
void PriorityQueue::enqueue(const char &chr, const unsigned &frequency) // enqueue char and its frequency
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

// Enqueue Function Overloading for more flexiblity and convenience
void PriorityQueue::enqueue(const char &chr, const string &prefix_code) // used for prefix code table
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
}

// Enqueue Function Overloading for more flexiblity and convenience
void PriorityQueue::enqueue(const FrequencyCounter &obj) // copying objects char and frequency
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

// Enqueue Function Overloading for more flexiblity and convenience
void PriorityQueue::enqueue(Node *node)
{

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
}

// returns top
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

// Checks if priority queue empty
bool PriorityQueue::is_empty() const
{
    return (head == NULL);
}

// Getters
unsigned PriorityQueue::get_size() const
{
    return size;
}

// Searching the prefix code of the chr inside the priority queue
string PriorityQueue::find_prefix_code(char chr) const
{
    Node *temp = head;
    string found_prefix_code = "";
    while (temp != NULL)
    {
        if (temp->chr != chr)
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

 // Printing the Priority Queue for prefix code table
void PriorityQueue::print() const
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->chr << ' ' << temp->prefix_code << endl;
        temp = temp->next;
    }
}

// Destructor
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
