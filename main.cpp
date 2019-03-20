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

int main(int argc, char *argv[])
{
    if (argc - 1 != 3)
    {
        cout << "Invaild Argument" << endl;
        exit(1);
    }

    string argument = argv[1];

    if (argument == "-c")
    {
        ifstream in_file(argv[2], ios::binary);
        ofstream out;
        out.open(argv[3], ios::out);

        cout << endl;
        cout << "Frequency Table: " << endl;
        FrequencyCounter freq_table(in_file); // creating freq table

        char *arr;
        unsigned file_length;

        PriorityQueue leaf_nodes;
        HuffmanTree tree;
        InBitStream in_bit;

        for (int i = 0; i < freq_table.get_capacity(); i++) // pass chr and frequency to priority queue
        {
            leaf_nodes.enqueue(freq_table[i]);
        }

        cout << endl;

        cout << "Building The Tree..." << endl;

        tree.build_huffman_tree(leaf_nodes);

        cout << endl;

        cout << "Compressed Version" << endl;
        in_bit.traverse(tree.get_prefix_code_table(), tree, freq_table.get_text(), freq_table.get_text_len());

        cout << tree.get_prefix_code() << endl;
        cout << endl;
    }
    else if(argument=="-d")
    {
        cout<<"Decompressing Code Unavailable :)"<<endl;
        exit(1);
    }
    else
    {
        cout<<"Invalid Command. Try -c"<<endl;
        exit(1);
    }
    

    return 0;
}