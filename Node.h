/*
 * Node.h
 *
 * Class Description: Node class for both PQ and HF tree.
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#pragma once

#include <cstdio>
#include "FrequencyCounter.h"

class Node
{
  public:
    char chr; // character
    unsigned frequency; // characters frequency
    Node *right; // pointer to right child (for Huffman Tree)
    Node *left; // pointer to left child (for Huffman Tree)
    Node *next; // pointer to next 
    string prefix_code;

    // Default Constructor
    Node();

    // Parameterized Constructors
    Node(const char& chr); // Implemented for flexibility
    Node(const Node &origin); // Copy Constructor
    Node(const char &chr, const unsigned &frequency); // Used during "Prefix code table"
    Node(const FrequencyCounter& freq_and_chr); // Implemented for flexibility
    Node(const char& chr, Node *rigth, Node *left); // Implemented for flexibility


    // Getters
    char get_chr() const;
    unsigned get_freq() const;
    string get_prefix_code() const;

    // Setters
    void set_chr(char chr);
    void set_freq(unsigned frequency);
    void set_prefix_code(string prefix_code);
};