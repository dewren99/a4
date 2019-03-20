/*
 * BitStream.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

#pragma once
#include"PriorityQueue.h"
#include"HuffmanTree.h"
#include <fstream> // ifstream, ofstream
using namespace std;

class InBitStream
{
  public:
    InBitStream(); // read file?
    InBitStream(const string &file_path);

    bool is_open() const {return in_file.is_open();};

// Closing the file. It is called by the destructor, If it is not called manually.
    void close();

    void read_input(ifstream &input_file);

    void traverse(PriorityQueue table, HuffmanTree root, ifstream* input_file);


    unsigned get_file_length() const {return file_length;};

    ~InBitStream();

  private:
    unsigned file_length;
    ifstream in_file;
};

class OutBitStream
{
  public:
    OutBitStream();
    OutBitStream(const string &file_path);

    void write_output();

    bool is_open() const {return out_file.is_open();};

// Closing the file. It is called by the destructor, If it is not called manually.
    void close();

    unsigned get_file_length() const {return file_length;};

    ~OutBitStream();

  private:
    unsigned file_length;
    fstream out_file;
};

// // 8 bits = one char
// class BitStream
// {
//     public:
//     BitStream(); // read file?
//     void read_input(ifstream& input_file);
//     void write_output();
//     unsigned get_file_length() const;

//     private:
//     unsigned file_length;

// };