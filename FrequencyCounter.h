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
  FrequencyCounter();
  //FrequencyCounter(unsigned capacity);
  FrequencyCounter(ifstream &input_file);
  //void input(ifstream& input_file);

  friend bool operator<=(const FrequencyCounter &arr1, const FrequencyCounter &arr2);
  friend bool operator>=(const FrequencyCounter &arr1, const FrequencyCounter &arr2);

  friend void merge(FrequencyCounter *arr, unsigned first, unsigned mid, unsigned last);
  friend void merge_sort(FrequencyCounter *arr, unsigned first, unsigned last);

  FrequencyCounter &operator[](const unsigned &index) const;

  unsigned get_capacity() const { return capacity; };
  unsigned get_frequency() const { return frequency; };
  unsigned get_letter() const { return letter; };

  char *get_text() { return text; };
  unsigned get_text_len() const { return text_len; };

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