/*
 * FrequencyCounter.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek, Hao Ran Wei
 * Date:  16/MAR/2019
 */

#pragma once

#include <fstream>
#include <iostream>

using namespace std;

class FrequencyCounter
{
public:
  FrequencyCounter(); // Default constructor
  FrequencyCounter(ifstream &input_file); // Read input file and create frequency table

  friend bool operator<=(const FrequencyCounter &arr1, const FrequencyCounter &arr2);
  friend bool operator>=(const FrequencyCounter &arr1, const FrequencyCounter &arr2);

// Sorting the frequency table with merge sort
  friend void merge(FrequencyCounter *arr, unsigned first, unsigned mid, unsigned last);
  friend void merge_sort(FrequencyCounter *arr, unsigned first, unsigned last);

  FrequencyCounter &operator[](const unsigned &index) const;


// Getters
  unsigned get_capacity() const { return capacity; };
  unsigned get_frequency() const { return frequency; };
  unsigned get_letter() const { return letter; };
  char *get_text() { return text; };
  unsigned get_text_len() const { return text_len; };

// Destructor
  ~FrequencyCounter();

private:
  char letter;
  unsigned frequency;
  char *text;
  unsigned text_len;
  static const unsigned INITIAL_SIZE = 10;
  unsigned size;
  unsigned capacity;

  FrequencyCounter *frequency_table;
};