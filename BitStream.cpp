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
#include<iostream>

BitStream::BitStream()
{
}

void BitStream::read_input(ifstream &input_file)
{
    // //ifstream in_file;

    // //string file_name;
    // char letter;

    // //cin >> file_name;

    // //in_file.open(file_name);
    // if (!input_file)
    // {
    //     std::cout << "error-change this error type l8r" << std::endl;
    // }
    // else
    // {
    //     input_file.seekg(0, input_file.end);          // determining file length
    //     file_length = input_file.tellg(); // determining file length
    //     input_file.seekg(0, input_file.beg);          // determining file length

    //     char *arr = new char[file_length];

    //     while (!input_file.eof()) // while not end of file, read the characters
    //     {
    //         input_file.read(arr, file_length);
    //     }
    // }
}
void BitStream::write_output()
{
}

unsigned BitStream::get_file_length() const
{
    return file_length;
}