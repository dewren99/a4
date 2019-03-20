/*
 * BitStream.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#pragma once
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <fstream> // ifstream, ofstream
using namespace std;

class InBitStream
{
  public:
    //Default Constructor
    InBitStream();

    //Paramatized Constructor
    InBitStream(const string &file_path);

    // Checking if the file is open
    bool is_open() const { return in_file.is_open(); };

    // Closing the file. It is called by the destructor, If it is not called manually.
    void close();

    // Read the values from the file
    void read_input(ifstream &input_file);

    //Compressing the Tree
    void traverse(PriorityQueue table, HuffmanTree &root, char *arr, int size);

    //Getters
    unsigned get_file_length() const { return file_length; };

    //Desctructor
    ~InBitStream();

  private:
    unsigned file_length;
    ifstream in_file;
};

class OutBitStream
{
  public:
    //Default Constructor
    OutBitStream();

    //Paramatized Constructor
    OutBitStream(const string &file_path);

    // Write the values to a file
    void write_output();

    bool is_open() const { return out_file.is_open(); };

    // Closing the file. It is called by the destructor, If it is not called manually.
    void close();

    //Getters
    unsigned get_file_length() const { return file_length; };

    //Desctructor
    ~OutBitStream();

  private:
    unsigned file_length;
    fstream out_file;
};