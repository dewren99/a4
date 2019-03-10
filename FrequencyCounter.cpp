/*
 * FrequencyCounter.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include "FrequencyCounter.h"

FrequencyCounter::FrequencyCounter()
{
    size = 0;
    capacity = INITIAL_SIZE;
    frequency_table = new FrequencyCounter[capacity];
}

FrequencyCounter::FrequencyCounter(ifstream &input_file)
{
    //ifstream in_file;

    //string file_name;
    char letter;

    //cin >> file_name;

    //in_file.open(file_name);
    if (!input_file)
    {
        std::cout << "error-change this error type l8r" << std::endl;
    }
    else
    {
        input_file.seekg(0, input_file.end); // determining file length
        capacity = input_file.tellg();    // determining file length
        input_file.seekg(0, input_file.beg); // determining file length

        char* arr = new char[capacity];

        while (!input_file.eof()) // while not end of file, read the characters
        {
            input_file.read(arr, capacity);
        }

        frequency_table = new FrequencyCounter[capacity];

        // copy chars and find count their frequency
        // no char should repeat inside frequency table so dont copy the char if its already in frequency table, instead increase the frequency

    }
}