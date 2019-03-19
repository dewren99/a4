/*
 * main.cpp
 *
 * Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
 #include "FrequencyCounter.h"
// #include "BitStream.h"
 #include "Node.h"
 #include "PriorityQueue.h"
#include "HuffmanTree.h"

using namespace std;

int main()
{
    string file_name;
    cin >> file_name;

    ifstream in_file(file_name.c_str());

    FrequencyCounter freq_table(in_file); // creating freq table
    cout << "capacity: " << freq_table.get_capacity() << endl;

    PriorityQueue leaf_nodes;
    HuffmanTree tree;

    for (int i = 0; i < freq_table.get_capacity(); i++)
    {
        leaf_nodes.enqueue(freq_table[i]);
    }
    
    cout<<endl;
    leaf_nodes.print();
    cout<<"capacity of PQ: "<<leaf_nodes.get_size()<<endl;
    cout<<endl;
    cout<<endl;

    tree.build_huffman_tree(leaf_nodes);

    tree.print_huffman_tree(leaf_nodes.top(),"");

    //obj.input(in_file);

    // ifstream in_file;
    // ofstream out;

    // string file_name;
    // char letter;

    // cin >> file_name;

    // in_file.open(file_name);
    // if (!in_file)
    // {
    //     cout << "error-change this error type l8r" << endl;
    // }
    // else
    // {
    //     in_file.seekg(0, in_file.end); // determining file length
    //     unsigned file_length = in_file.tellg(); // determining file length
    //     in_file.seekg(0, in_file.beg); // determining file length

    //     char* arr = new char[file_length];

    //     while (!in_file.eof()) // while not end of file, read the characters
    //     {
    //        in_file.read(arr, file_length);
    //     }
    // }

    return 0;
}