/*
 * FrequencyCounter.cpp
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include"FrequencyCounter.h"

FrequencyCounter::FrequencyCounter()
{}

FrequencyCounter::FrequencyCounter(char letter, unsigned frequency)
{
    this->letter = letter;
    this->frequency = frequency;
}