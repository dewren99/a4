/*
 * HuffmanTree.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
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
  HuffmanTree();

  //void build_huffman_tree(PriorityQueue* leafs);

  void build_huffman_tree(PriorityQueue& leafs);

  void traverse(PriorityQueue table);

  string compress(string text);
  void decompress();

  void print_huffman_tree(Node* Root, string str);

  Node* get_root() const {return root;};

  string get_prefix_code() const {return prefix_code;};

  PriorityQueue get_prefix_code_table() const {return prefix_code_table;};

void add_to_prefix_code(string code);
  

  //HuffmanTree(char letter, unsigned frequency);

  ~HuffmanTree();

private:
  Node *root;
  PriorityQueue prefix_code_table;
  string prefix_code;
};