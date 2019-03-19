/*
 * HuffmanTree.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

#include "HuffmanTree.h"

// HT_node::HT_node()
// {
//     right = left = NULL;
// }

// HT_node::HT_node(char chr)
// {
//     right = left = NULL;
//     this->chr = chr;
// }

// HT_node::HT_node(unsigned frequency, char chr)
// {
//     right = left = NULL;
//     this->chr = chr;
//     this->frequency = frequency;
// }

// HT_node::HT_node(HT_node *left_child, HT_node *right_child)
// {
//     left = left_child;
//     right = right_child;
// }

// // converting PQ_node to HT_node
//   HT_node::HT_node(const PQ_node& pq_node)
//   {
//       chr = pq_node.chr;
//       frequency = pq_node.frequency;
//   }


// Defualt Constructor. Creates the root of the tree
HuffmanTree::HuffmanTree()
{
    root = new Node('$');
}

void HuffmanTree::build_huffman_tree(PriorityQueue* leafs)
{
    while(leafs->get_size()!=1)
    {
        root->left = leafs->top();
        leafs->dequeue();

        root->right = leafs->top();
        leafs->dequeue();

        Node* parent = new Node('$', root->left->frequency + root->right->frequency);
        parent->left = root->left;
        parent->right = root->right;

        leafs->enqueue(*parent);
    }

}

void HuffmanTree::build_huffman_tree(PriorityQueue& leafs)
{

   while(leafs.get_size()>1)
    {
        unsigned freq_total;

        Node* min1 = leafs.top();
        leafs.dequeue();
        cout<<"Left: "<<min1->frequency <<' '<<min1->chr<<endl;
        freq_total = min1->frequency;
    
        Node* min2 = leafs.top();
        leafs.dequeue();
        cout<<"Right: "<<min2->frequency <<' '<<min2->chr<<endl;
        freq_total += min2->frequency;
       
        //cout<<"total: "<<freq_total<<endl;

        Node* parent = new Node('$', freq_total);
        parent->left = min1;
        parent->right = min2;
        cout<<"Parent: "<< parent->frequency<<endl;//<<' '<<parent->chr<<' '<<parent->left->chr<<' '<<parent->right->chr<<' '<<freq_total<<endl;
        leafs.enqueue(*parent);
    }

    // while(leafs.get_size()!=1)
    // {
    //     cout<<"Left Top: "<< leafs.top()->frequency<<endl;
    //     root->left = leafs.top();
    //     leafs.dequeue();
    //     cout<<"Left: "<<root->left->frequency <<' '<<root->left->chr<<endl;

    //     root->right = leafs.top();
    //     cout<<"Right: "<<root->right->frequency <<' '<<root->right->chr<<endl;
    //     leafs.dequeue();

    //     Node* parent = new Node('$', root->left->frequency + root->right->frequency);
    //     parent->left = root->left;
    //     parent->right = root->right;

    //     leafs.enqueue(*parent);
    // }
}

void HuffmanTree::print_huffman_tree(Node* root, string str) // str = "" ----> when the function is called
{
    cout<<"hey"<<endl; 
if (!root)
return;

if (root->chr != '$')
cout << root->chr << ": " << str << "\n";

print_huffman_tree(root->left, str + "0");
print_huffman_tree(root->right, str + "1");
}

HuffmanTree::~HuffmanTree()
{

}

