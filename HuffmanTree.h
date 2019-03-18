/*
 * HuffmanTree.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include "PriorityQueue.h"

class HT_node
{
public:
  char chr;
  unsigned frequency;
  HT_node *rigth;
  HT_node *left;
};

class HuffmanTree
{
  class HT_node
  {
    public:
    
  };

  public:
    HuffmanTree();
    //HuffmanTree(char letter, unsigned frequency);

    ~HuffmanTree();

  private:
  HT_node* root;

};