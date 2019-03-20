/*
 * BitStream.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
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

void InBitStream::traverse(PriorityQueue table, HuffmanTree root, ifstream* input_file)
{

    if (!input_file)
    {
        std::cout << "invalid file" << std::endl;
    }
    else
    {
        char *arr = NULL;
        unsigned capacity;
        input_file->seekg(0, input_file->end);    // determining file length
        capacity = input_file->tellg(); // determining file length
        input_file->seekg(0, input_file->beg);    // determining file length


            arr = new char[capacity];

        while (!input_file->eof()) // while not end of file, read the characters
        {
            input_file->read(arr, capacity);
        }
        string code = "";
        for (int i = 0; i < capacity; i++)
        {
            cout<<arr[i]<<' ';
            code = table.find_prefix_code(arr[i]);
            root.add_to_prefix_code(code);
        }
    }
}

InBitStream::~InBitStream()
{
}
//InBitStream Member Functions End Here

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
//OutBitStream Member Functions End Here

// void BitStream::read_input(ifstream &input_file)
// {
//     // //ifstream in_file;

//     // //string file_name;
//     // char letter;

//     // //cin >> file_name;

//     // //in_file.open(file_name);
//     // if (!input_file)
//     // {
//     //     std::cout << "error-change this error type l8r" << std::endl;
//     // }
//     // else
//     // {
//     //     input_file.seekg(0, input_file.end);          // determining file length
//     //     file_length = input_file.tellg(); // determining file length
//     //     input_file.seekg(0, input_file.beg);          // determining file length

//     //     char *arr = new char[file_length];

//     //     while (!input_file.eof()) // while not end of file, read the characters
//     //     {
//     //         input_file.read(arr, file_length);
//     //     }
//     // }
// }
// void BitStream::write_output()
// {
// }

// unsigned BitStream::get_file_length() const
// {
//     return file_length;