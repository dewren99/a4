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

// Building Huffman Tree
void HuffmanTree::build_huffman_tree(PriorityQueue &leafs)
{
    while (leafs.get_size() > 1) // run while PQ size is not equal to 1
    {
        unsigned freq_total; // will hold total frequency --> child1.frequency + child2.frequency

        Node *parent = new Node('$', freq_total); // create a parent node
        parent->left = leafs.dequeue();           // update left

        freq_total = parent->left->frequency; // update total frequency

        parent->right = leafs.dequeue(); // update right

        freq_total += parent->right->frequency; // update total frequency again. Now we have the total frequency of 2 childs

        parent->set_freq(freq_total); // update parent nodes frequency count

        leafs.enqueue(parent); // enqueue back to PQ
    }

    root = leafs.dequeue(); // Last item on PQ is our root

    string str = "";

    cout << endl;

    cout << "Prefix codes for each letter" << endl;
    print_huffman_tree(root, str);
}

// Prints Tree nodes and their prefix code
void HuffmanTree::print_huffman_tree(Node *Root, string str) // str = "" ----> when the function is called
{
    if (!root)
        return;

    if (Root->chr != '$') // if you reach leaf
    {
        cout << Root->chr << ": " << str << "\n";  // print leaf char and prefix code
        prefix_code_table.enqueue(Root->chr, str); // add the char and its prefix code to the prefix code table
    }

    if (Root->left != NULL)
    {
        print_huffman_tree(Root->left, str + "0"); //go left and add 0 to prefix code
    }
    else
    {
    }
    if (Root->right != NULL)
    {
        print_huffman_tree(Root->right, str + "1"); //go right and add 1 to prefix code
    }
}

// Updating prefix code
void HuffmanTree::add_to_prefix_code(string code)
{
    prefix_code += code;
}

// Deleting nodes recursively
void HuffmanTree::destroy_huffman_tree(Node *tree_root) // Deleting nodes recursively
{
    if (tree_root)
    {
        destroy_huffman_tree(tree_root->left);
        destroy_huffman_tree(tree_root->right);
        delete tree_root;
    }
}

// Destructor
HuffmanTree::~HuffmanTree()
{
    destroy_huffman_tree(root);
}
