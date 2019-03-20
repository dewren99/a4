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

// void HuffmanTree::build_huffman_tree(PriorityQueue *leafs)
// {
//     while (leafs->get_size() != 1)
//     {
//         root->left = leafs->top();
//         leafs->dequeue();

//         root->right = leafs->top();
//         leafs->dequeue();

//         Node *parent = new Node('$', root->left->frequency + root->right->frequency);
//         parent->left = root->left;
//         parent->right = root->right;

//         leafs->enqueue(*parent);
//     }
// }

void HuffmanTree::build_huffman_tree(PriorityQueue &leafs)
{
    while (leafs.get_size() > 1)
    {
         

        //cout<<"inside while"<<endl;
        unsigned freq_total;
        Node *parent = new Node('$', freq_total);
        /*Node *min1*/ 
        parent->left = leafs.dequeue();//leafs.top();
        //leafs.dequeue();
        
        //cout << "Left: " << root->left->frequency << ' ' << root->left->chr << endl;

        //cout<<"inside while"<<endl;

        freq_total = parent->left->frequency;

        parent->right = leafs.dequeue();//leafs.top();
        //leafs.dequeue();

        //cout << "Right: " << root->right->frequency << ' ' << root->right->chr << endl;
        freq_total += parent->right->frequency;

        //cout<<"total: "<<freq_total<<endl;

        parent->set_freq(freq_total);
        // parent->left = root->left; //min1;
        // parent->right = root->right;//min2;
        cout << "Parent: " << parent->frequency <<" parent chr: "<<parent->chr<<" parent->left chr: "<<parent->left->chr<<" parent->right chr: "<<parent->right->chr<<' '<<freq_total<<endl;
        leafs.enqueue(parent);
    }

    root = leafs.dequeue();//leafs.top();
    //leafs.dequeue();
    // cout << "printing" << endl;
    // cout<<endl;
    // Node * temp = root;
    // while(temp!= NULL){
    //     cout << temp->chr << endl;
    //     temp = temp->left;
    // }

    string str= "";
    print_huffman_tree(root, str);

    cout<<"PRINTING"<<endl;
    prefix_code_table.print();

    //return str;
}



void HuffmanTree::print_huffman_tree(Node* Root, string str) // str = "" ----> when the function is called
{
    // Node* temp = root;
    // while(temp!=NULL)
    // {
    //     cout<<temp->chr<< ' ' <<temp->frequency<<endl;
    //     temp = temp->left;
    // }

    if (!root)
    return;
  
    if (Root->chr != '$')
    {
        cout<<"bingo"<<endl;
        cout << Root->chr << ": " << str <<"\n";
        prefix_code_table.enqueue(Root->chr, str);
    }

    if (Root->left != NULL){
        /*return*/ print_huffman_tree(Root->left, str + "0");
    }
    else{

    }
    if (Root->right != NULL){
        /*return*/ print_huffman_tree(Root->right, str + "1");
    }
}


void HuffmanTree::add_to_prefix_code(string code)
{
    prefix_code += code;
}


HuffmanTree::~HuffmanTree()
{
}
