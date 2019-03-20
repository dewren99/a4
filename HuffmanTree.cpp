/*
 * HuffmanTree.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#include "HuffmanTree.h"


// Defualt Constructor. Creates the root of the tree
HuffmanTree::HuffmanTree()
{
    root = new Node('$');
    prefix_code = "";
}

void HuffmanTree::build_huffman_tree(PriorityQueue &leafs)
{
    while (leafs.get_size() > 1)
    {
        unsigned freq_total;

        Node *parent = new Node('$', freq_total);
        parent->left = leafs.dequeue();

        freq_total = parent->left->frequency;

        parent->right = leafs.dequeue();

        freq_total += parent->right->frequency;

        parent->set_freq(freq_total);
        leafs.enqueue(parent);
    }

    root = leafs.dequeue();

    string str= "";
    cout<<endl;
    cout<< "Prefix codes for each letter"<<endl;
    print_huffman_tree(root, str);
    
}



void HuffmanTree::print_huffman_tree(Node* Root, string str) // str = "" ----> when the function is called
{
    if (!root)
    return;
  
    if (Root->chr != '$')
    {
        cout << Root->chr << ": " << str <<"\n";
        prefix_code_table.enqueue(Root->chr, str);
    }

    if (Root->left != NULL){
        print_huffman_tree(Root->left, str + "0");
    }
    else{

    }
    if (Root->right != NULL){
       print_huffman_tree(Root->right, str + "1");
    }
}


void HuffmanTree::add_to_prefix_code(string code)
{
    prefix_code += code;
}


HuffmanTree::~HuffmanTree()
{
}
