/*
 * BitStream.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#include "BitStream.h"
#include <iostream>

//InBitStream Member Functions

//Default Constructor
InBitStream::InBitStream()
{
}

//Paramatized Constructor
InBitStream::InBitStream(const string &file_path)
{
}

// Closing the file. It is called by the destructor, If it is not called manually.
void InBitStream::close()
{
}

// Read the values from the file
void InBitStream::read_input(ifstream &input_file)
{
}

//Compressing the Tree
void InBitStream::traverse(PriorityQueue table, HuffmanTree &root, char *arr, int size)
{
    string code = "";
    for (int i = 0; i < size; i++)
    {
        code = table.find_prefix_code(arr[i]);
        root.add_to_prefix_code(code);
    }
}

//Desctructor
InBitStream::~InBitStream()
{
}

//OutBitStream Member Functions

//Default Constructor
OutBitStream::OutBitStream()
{
}

//Paramatized Constructor
OutBitStream::OutBitStream(const string &file_path)
{
}

// Write the values to a file
void OutBitStream::write_output()
{
}

// Closing the file. It is called by the destructor, If it is not called manually.
void OutBitStream::close()
{
}

//Desctructor
OutBitStream::~OutBitStream()
{
    if (is_open())
    {
        close();
    }
}