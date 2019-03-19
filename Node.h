/*
 * Node.h
 *
 * Class Description: Node class for both PQ and HF tree.
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

#pragma once

#include <cstdio>
#include "FrequencyCounter.h"

class Node
{
  public:
    char chr;
    unsigned frequency;
    Node *right;
    Node *left;
    Node *next;

    Node();
    Node(const char& chr);
    Node(const Node &origin);
    Node(const char &chr, const unsigned &frequency);
    Node(const FrequencyCounter& freq_and_chr);
    Node(const char& chr, Node *rigth, Node *left);

    // Getters
    char get_chr() const;
    unsigned get_freq() const;

    // Setters
    void set_chr(char chr);
    void set_freq(unsigned frequency);
};

// Node::Node()
// {
//     next = left = right = NULL;
// }

// Node::Node(char chr, unsigned frequency)
// {
//     next = left = right = NULL;
//     this->chr = chr;
//     this->frequency = frequency;
// }

// Node::Node(char chr, Node *right, Node* left)
// {
//     this->chr = chr;
//     this->left = left;
//     this->right = right;
//     next = NULL;
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
