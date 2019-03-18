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
    frequency_table = NULL;
}

FrequencyCounter::FrequencyCounter(ifstream &input_file) // CHECK ALGO
{
    cout << "Entered" << endl;
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

        char *arr = NULL;
        if (capacity > 0)
        {
            arr = new char[capacity];
        }
        else
        {
            arr = new char[INITIAL_SIZE];
        }

        while (!input_file.eof()) // while not end of file, read the characters
        {
            input_file.read(arr, capacity);
        }
        // // cout<<"Found text in file: ";
        // // for(int i=0; i<capacity; i++)
        // // {
        // //     cout<<arr[i];
        // // }
        // // cout<<endl;
        frequency_table = new FrequencyCounter[capacity];

        unsigned *index_holder = new unsigned[capacity];

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
                        frequency_table[i].letter = arr[i];
                        frequency_table[i].frequency = counter;
                        index_holder[j] = j;
                        //same_value_found = true;
                    }
                    // if (same_value_found) //copy the char and how many of them total in the arr
                    // {

                    //     //frequency_table[i].letter = arr[i];
                    //     frequency_table[i].frequency = counter;
                    // }
                    // else // if there is occurance more than once then copy char and set freq to 1
                    // {
                    //     frequency_table[i].letter = arr[i];
                    //     frequency_table[i].frequency = 1;
                    // }
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
                //cout<<"adding "<< temp[i].letter<<endl;
                frequency_table[j] = temp[i];
                j++;
            }
            else
            {
                //cout<<"not adding "<< temp[i].letter<<endl;
            }
        }

        capacity = new_size;
        size = capacity-1;
        cout << endl;

        unsigned start = 0;

        merge_sort(frequency_table,start,size);

        for (int i = 0; i < capacity; i++)
        {
            cout << frequency_table[i].letter << " " << frequency_table[i].frequency << endl;
        }

        // Coding for Sorting the frequency table from now on
    }
    /////////////////////////////////////////////////////
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

//     void FrequencyCounter::input(ifstream& input_file)
//     {

//     char letter;

//     //cin >> file_name;

//     //in_file.open(file_name);
//     if (!input_file)
//     {
//         std::cout << "error-change this error type l8r" << std::endl;
//     }
//     else
//     {
//         input_file.seekg(0, input_file.end); // determining file length
//         capacity = input_file.tellg();       // determining file length
//         input_file.seekg(0, input_file.beg); // determining file length

//         char *arr = new char[capacity];

//         while (!input_file.eof()) // while not end of file, read the characters
//         {
//             input_file.read(arr, capacity);
//         }

//         frequency_table = new FrequencyCounter[capacity];

//         unsigned *index_holder = new unsigned[capacity];

//         for (int i = 0; i < capacity; i++)
//         {

//             bool same_value_found = false;
//             unsigned counter = 0;

//             for (int j = i; j < capacity - 1; j++)
//             {
//                 if (arr[i] == arr[j]) // if there is more than once occurance count how many
//                 {
//                     counter++;
//                     same_value_found = true;
//                 }
//                 if (same_value_found) //copy the char and how many of them total in the arr
//                 {

//                     frequency_table[i].letter = arr[i];
//                     frequency_table[i].frequency = counter;
//                 }
//                 else // if there is occurance more than once then copy char and set freq to 1
//                 {
//                     frequency_table[i].letter = arr[i];
//                     frequency_table[i].frequency = 1;
//                 }
//             }
//         }

//         // for(int i=0; i<capacity; i++)
//         // {
//         //     frequency_table[i].letter = arr[i];
//         // }

//         // for(int i = 0; i<capacity; i++)
//         // {
//         //     unsigned counter = 0;
//         //     for(int j=i, k=0; j<capacity-1; j++)
//         //     {
//         //         if(frequency_table[i].letter == frequency_table[j].letter)
//         //         {
//         //             counter++;
//         //             frequency_table[i].frequency = counter;
//         //             index_holder[k]=j;
//         //             k++;
//         //         }
//         //     }
//     }

//     // copy chars and find count their frequency
//     // no char should repeat inside frequency table so dont copy the char if its already in frequency table, instead increase the frequency

// }

bool operator<=(const FrequencyCounter& arr1, const FrequencyCounter& arr2)
{
    return (arr1.get_frequency() <= arr2.get_frequency());
}

bool operator>=(const FrequencyCounter& arr1, const FrequencyCounter& arr2)
{
    return (arr1.get_frequency() >= arr2.get_frequency());
}

void merge(FrequencyCounter *arr, unsigned first, unsigned mid, unsigned last)
{

       int i, j, k; 
    int n1 = mid - first + 1; 
    int n2 =  last - mid; 
  
    /* create temp arrays */
    FrequencyCounter L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[first + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
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
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }


    // unsigned len = last - first + 1;

    // FrequencyCounter temp_arr[len];

    // unsigned left_pos = first;
    // unsigned rigth_pos = mid + 1;
    // unsigned temp_arr_pos = 0;

    // while (left_pos <= mid && rigth_pos <= last)
    // {
    //     if (arr[left_pos] <= arr[rigth_pos])
    //     {
    //         temp_arr[temp_arr_pos++] = arr[left_pos++];
    //     }
    //     else
    //     {
    //         temp_arr[temp_arr_pos++] = arr[rigth_pos++];
    //     }
    // }
    // for(int k = 0, i = first+1; i <= last; ++i, ++k)
    // {
    //     arr[i] = temp_arr[k];
    // }
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

