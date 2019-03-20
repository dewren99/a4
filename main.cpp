/*
 * main.cpp
 *
 * Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#include "FrequencyCounter.h"
#include "BitStream.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"

using namespace std;

int main(/*int argc, int argv[]*/)
{
    cout<<endl;
    cout<<"Please drag and drop the file"<<endl;

    string file_name;
    cin >> file_name;

    ifstream in_file(file_name.c_str());

cout<<endl;
    cout<<"Frequency Table: "<<endl;
    FrequencyCounter freq_table(in_file); // creating freq table


    char *arr;
    unsigned file_length;

    PriorityQueue leaf_nodes;
    HuffmanTree tree;
    InBitStream in_bit;

    for (int i = 0; i < freq_table.get_capacity(); i++)
    {
        leaf_nodes.enqueue(freq_table[i]);
    }

    cout << endl;

    cout<<"Building The Tree"<<endl;

    tree.build_huffman_tree(leaf_nodes);

    cout << endl;


cout<<"Compressed Version"<<endl;
    in_bit.traverse(tree.get_prefix_code_table(), tree, freq_table.get_text(), freq_table.get_text_len());

    cout << tree.get_prefix_code() << endl;
    cout<<endl;

    return 0;
}