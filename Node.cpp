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

Node::Node()
{
    next = left = right = NULL;
    frequency = 0;
}

Node::Node(const char& chr)
{
    this->chr = chr;
    next = left = right = NULL;
    frequency = 0;
}

Node::Node(const Node &origin)
{
    chr = origin.chr;
    frequency = origin.frequency;
    next = left = right = NULL;
}

Node::Node(const char &chr, const unsigned &frequency)
{
    //next = left = right = NULL;
    this->chr = chr;
    this->frequency = frequency;
}

Node::Node(const char& chr, Node *right, Node *left)
{
    this->chr = chr;
    this->left = left;
    this->right = right;
    next = NULL;
}

// Getters

char Node::get_chr() const
{
    return chr;
}

unsigned Node::get_freq() const
{
    return frequency;
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

// Node::Node()
// {
//     rigth = NULL;
//     left = NULL;
// }

// Node::Node(char chr)
// {
//     this->chr = chr;
// }

// Node::Node(char chr, Node *rigth, Node* left)
// {
//     this->chr = chr;
//     left = NULL;
//     rigth = NULL;
// }

//  // Getters
// char Node::get_chr() const
// {
// return chr;
// }

// unsigned Node::get_freq() const
// {
// return frequency;
// }

// // Setters
// void Node::set_chr(char chr)
// {
// this->chr = chr;
// }

// void Node::set_freq(unsigned frequency)
// {
// this->frequency = frequency;
// }