/*
 * HuffmanTree.h
 *
 * Class Description: Creating & Printing Huffman Tree
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#pragma once

#include "Node.h"
#include "FrequencyCounter.h"
#include "PriorityQueue.h"
#include "string"

class HuffmanTree
{
public:
  // Default Constructor
  HuffmanTree();

  // Building Huffman Tree
  void build_huffman_tree(PriorityQueue &leafs);

 // Prints Tree nodes and their prefix code
  void print_huffman_tree(Node *Root, string str);

  // Getters
  Node *get_root() const { return root; };
  string get_prefix_code() const { return prefix_code; };

  // Returns prefix code table that has characthers and their prefix code
  PriorityQueue get_prefix_code_table() const { return prefix_code_table; };

  // Updating prefix code
  void add_to_prefix_code(string code);

  // Deleting nodes recursively
  void destroy_huffman_tree(Node *tree_root);

  // Destructor
  ~HuffmanTree();

private:
  Node *root;
  PriorityQueue prefix_code_table;
  string prefix_code;
};