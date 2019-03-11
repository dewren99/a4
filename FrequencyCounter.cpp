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
    frequency = 0;
    capacity = INITIAL_SIZE;
    frequency_table = new FrequencyCounter[capacity];
}

FrequencyCounter::FrequencyCounter(ifstream input_file) // CHECK ALGO
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
        capacity = input_file.tellg();       // determining file length
        input_file.seekg(0, input_file.beg); // determining file length

        char *arr = new char[capacity];

        while (!input_file.eof()) // while not end of file, read the characters
        {
            input_file.read(arr, capacity);
        }

        frequency_table = new FrequencyCounter[capacity];

        unsigned *index_holder = new unsigned[capacity];

        for (int i = 0; i < capacity; i++)
        {

            bool same_value_found = false;
            unsigned counter = 0;

            for (int j = i; j < capacity - 1; j++)
            {
                if (arr[i] == arr[j]) // if there is more than once occurance count how many
                {
                    counter++;
                    same_value_found = true;
                }
                if (same_value_found) //copy the char and how many of them total in the arr
                {

                    frequency_table[i].letter = arr[i];
                    frequency_table[i].frequency = counter;
                }
                else // if there is occurance more than once then copy char and set freq to 1
                {
                    frequency_table[i].letter = arr[i];
                    frequency_table[i].frequency = 1;
                }
            }
        }

        // for(int i=0; i<capacity; i++)
        // {
        //     frequency_table[i].letter = arr[i];
        // }

        // for(int i = 0; i<capacity; i++)
        // {
        //     unsigned counter = 0;
        //     for(int j=i, k=0; j<capacity-1; j++)
        //     {
        //         if(frequency_table[i].letter == frequency_table[j].letter)
        //         {
        //             counter++;
        //             frequency_table[i].frequency = counter;
        //             index_holder[k]=j;
        //             k++;
        //         }
        //     }
    }
  
    // copy chars and find count their frequency
    // no char should repeat inside frequency table so dont copy the char if its already in frequency table, instead increase the frequency

}
