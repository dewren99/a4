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
  FrequencyCounter(ifstream& input_file);
  //void input(ifstream& input_file);

unsigned get_capacity(){return capacity;};

  private:
    char letter;
    unsigned frequency;

    static const unsigned INITIAL_SIZE = 10;
    unsigned size;
    unsigned capacity;

    FrequencyCounter* frequency_table;

};