// /*
//  * Node.cpp
//  *
//  * Class Description:
//  *
//  *
//  * Author: Deniz Evrendilek
//  * Date:  16/MAR/2019
//  */

#include "Node.h"

// Default Constructor
Node::Node()
{
    next = left = right = NULL;
    frequency = 0;
}

// Parameterized Constructors
Node::Node(const char& chr)// Implemented for flexibility
{
    this->chr = chr;
    next = left = right = NULL;
    frequency = 0;
}

Node::Node(const Node &origin)// Copy Constructor
{
    chr = origin.chr;
    frequency = origin.frequency;
    next = left = right = NULL;
}

Node::Node(const char &chr, const unsigned &frequency)// Used during "Prefix code table"
{
    next = left = right = NULL;
    this->chr = chr;
    this->frequency = frequency;
}

  Node::Node(const FrequencyCounter& freq_and_chr) // Implemented for flexibility
  {
    next = left = right = NULL;
    this->chr = freq_and_chr.get_letter();
    this->frequency = freq_and_chr.get_frequency();
  }

Node::Node(const char& chr, Node *right, Node *left)// Implemented for flexibility
{
    this->chr = chr;
    this->left = left;
    this->right = right;
    next = NULL;
}

// void Node::operator=(const Node* origin)
// {
//     chr = origin->chr;
//     frequency = origin->frequency;
// }


// Getters
char Node::get_chr() const
{
    return chr;
}

unsigned Node::get_freq() const
{
    return frequency;
}

string Node::get_prefix_code() const
{
    return prefix_code;
}


// Setters
void Node::set_chr(char chr)
{
    this->chr = chr;
}

void Node::set_freq(unsigned frequency)
{
    this->frequency = frequency;
}

void Node::set_prefix_code(string prefix_code)
{
    this->prefix_code = prefix_code;
}
