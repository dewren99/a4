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

InBitStream::InBitStream()
{
}

InBitStream::InBitStream(const string &file_path)
{
}

// Closing the file. It is called by the destructor, If it is not called manually.
void InBitStream::close()
{
}

void InBitStream::read_input(ifstream &input_file)
{
}

void InBitStream::traverse(PriorityQueue table, HuffmanTree &root, char *arr, int size)
{
    string code = "";
    for (int i = 0; i < size; i++)
    {
        code = table.find_prefix_code(arr[i]);
        root.add_to_prefix_code(code);
    }
}

InBitStream::~InBitStream()
{
}

//OutBitStream Member Functions

OutBitStream::OutBitStream()
{
}
OutBitStream::OutBitStream(const string &file_path)
{
}

void OutBitStream::write_output()
{
}

// Closing the file. It is called by the destructor, If it is not called manually.
void OutBitStream::close()
{
}

OutBitStream::~OutBitStream()
{
    if (is_open())
    {
        close();
    }
}