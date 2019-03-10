/*
 * FrequencyCounter.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */

class FrequencyCounter
{
  public:
  FrequencyCounter();
  FrequencyCounter(char letter, unsigned frequency);
  private:
    char letter;
    unsigned frequency;
};