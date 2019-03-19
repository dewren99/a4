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
#include "BitStream.h"
#include "PriorityQueue.h"

// class HT_node
// {
// public:
//   char chr;
//   unsigned frequency;
//   HT_node *right;
//   HT_node *left;
//   HT_node *parent;

//   HT_node();

//   HT_node(char chr);

//   // leaf node constructor.
//   HT_node(unsigned frequency, char chr);

//   // internal node constructor.
//   HT_node(HT_node *left_child, HT_node *right_child);


// // converting PQ_node to HT_node
//   HT_node(const PQ_node& pq_node);
// };

class HuffmanTree
{
public:
  HuffmanTree();

  void build_huffman_tree(PriorityQueue* leafs);
  void build_huffman_tree(PriorityQueue& leafs);

  void compress();
  void decompress();

  void print_huffman_tree(Node* root, string str);
  

  //HuffmanTree(char letter, unsigned frequency);

  ~HuffmanTree();

private:
  Node *root;
};