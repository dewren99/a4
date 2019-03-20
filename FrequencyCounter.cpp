/*
 * FrequencyCounter.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */
#include "FrequencyCounter.h"

FrequencyCounter::FrequencyCounter()// Default constructor
{
    size = 0;
    frequency = 0;
    capacity = INITIAL_SIZE;
    frequency_table = NULL;
    text_len = 0;
}

FrequencyCounter::FrequencyCounter(ifstream &input_file)// Read input file and create frequency table

{
    char letter;

    if (!input_file)
    {
        std::cout << "error reading the file" << std::endl;
    }
    else
    {
        input_file.seekg(0, input_file.end); // determining file length
        capacity = input_file.tellg();       // determining file length
        input_file.seekg(0, input_file.beg); // determining file length

        char *arr = NULL;
        if (capacity > 0)
        {
            arr = new char[capacity];
        }
        else
        {
            cout<<"Error. Empty file"<<endl;
            exit(1); // If file is empty terminate the program
        }

        while (!input_file.eof() && capacity != 0) // while not end of file, read the characters
        {
            input_file.read(arr, capacity); // read the file pass the characters to char array
        }
        frequency_table = new FrequencyCounter[capacity];

        text = new char[capacity];

        for(int i =0; i<capacity; i++) // Copying the char array to array called "text"
        {
            text[i]= arr[i];
        }
        text_len = capacity; // Storing the char array before editing it for future use


        unsigned *index_holder = new unsigned[capacity]; // for storing the index numbers

        for (int i = 0; i < capacity; i++)
        {

            bool same_value_found = false;
            unsigned counter = 0;
            int k = 0;
            if (i == index_holder[i] && i != 0)
            {
                continue;
            }
            else
            {
                for (int j = i; j < capacity; j++)
                {
                    if (arr[i] == arr[j]) // if there is more than once occurance count how many
                    {
                        counter++;
                        frequency_table[i].letter = arr[i]; // copy char to frequency table
                        frequency_table[i].frequency = counter; // copy chars frequency to frequency table
                        index_holder[j] = j; // store current index
                    }
                }
            }
        }
        FrequencyCounter *temp = new FrequencyCounter[capacity];
        unsigned new_size = 0;

        for (int i = 0; i < capacity; i++)
        {
            temp[i] = frequency_table[i];
            if (frequency_table[i].frequency != 0)
            {
                new_size++;
            }
        }

        delete[] frequency_table;

        frequency_table = new FrequencyCounter[new_size];

        for (int i = 0, j = 0; i < capacity; i++)
        {
            if (temp[i].frequency != 0)
            {
                frequency_table[j] = temp[i];
                j++;
            }
        }

        capacity = new_size;
        size = capacity-1;
        cout << endl;

        unsigned start = 0;

        merge_sort(frequency_table,start,size); // sort the frequency table by frequency

        for (int i = 0; i < capacity; i++)
        {
            cout << frequency_table[i].letter << " " << frequency_table[i].frequency << endl;
        }
    }
}

bool operator<=(const FrequencyCounter& arr1, const FrequencyCounter& arr2)
{
    return (arr1.get_frequency() <= arr2.get_frequency()); // return biggest frequency
}

bool operator>=(const FrequencyCounter& arr1, const FrequencyCounter& arr2)
{
    return (arr1.get_frequency() >= arr2.get_frequency()); // return biggest frequency
}

void merge(FrequencyCounter *arr, unsigned first, unsigned mid, unsigned last) // merge function for merge sort
{

       int i, j, k; 
    int n1 = mid - first + 1; 
    int n2 =  last - mid; 
  
    // creating temp arrays
    FrequencyCounter L[n1], R[n2]; 
  
    // Copy data to temp arrays L[] (left) and R[] (right)
    for (i = 0; i < n1; i++) 
        L[i] = arr[first + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = first; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[]
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[]
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
}

void merge_sort(FrequencyCounter *arr, unsigned first, unsigned last)
{
    if (last <= first)
        return;
    unsigned mid = (last + first) / 2;

    merge_sort(arr, first, mid);
    merge_sort(arr, mid + 1, last);

    merge(arr, first, mid, last);
}

  FrequencyCounter& FrequencyCounter::operator[](const unsigned& index) const
  {
      if(index >= capacity)
      cout<<"out of bound"<<endl;
      else
      return frequency_table[index]; 
  }
