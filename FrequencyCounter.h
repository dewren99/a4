/*
 * FrequencyCounter.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

#include<fstream>
#include<iostream>

using namespace std;

class FrequencyCounter
{
  public:
  FrequencyCounter();
  //FrequencyCounter(unsigned capacity);
  FrequencyCounter(ifstream input_file);
  private:
    char letter;
    unsigned frequency;

    static const unsigned INITIAL_SIZE = 10;
    unsigned size;
    unsigned capacity;

    FrequencyCounter* frequency_table;

};