/*
 * BitStream.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include<fstream> // ifstream, ofstream
using namespace std;

// 8 bits = one char
class BitStream
{
    public:
    BitStream(); // read file?
    void read_input(ifstream& input_file);
    void write_output();
    unsigned get_file_length() const;

    private:
    unsigned file_length;

}