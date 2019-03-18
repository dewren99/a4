/*
 * Node.h
 *
 * Class Description:
 *
 *
 * Author: Deniz Evrendilek
 * Date:  16/MAR/2019
 */
#include <cstdio>

template <class T>
class Node
{
  public:
    char chr;
    unsigned frequency;
    // Node* right;
    // Node* left;


    Node();
    Node(char chr, unsigned frequency);
    Node(FrequencyCounter chr_n_time);
    //Node(char chr, Node *rigth, Node* left);

    // Getters
    char get_chr() const;
    unsigned get_freq() const;
    
    // Setters
    void set_chr(char chr);
    void set_freq(unsigned frequency);
};

template <class T>
Node<T>::Node()
{
    //rigth = NULL;
    //left = NULL;
    this->chr = NULL;
    this->frequency = NULL;
}

template <class T>
Node<T>::Node(char chr, unsigned frequency)
{
    this->chr = chr;
    this->frequency = frequency;
}

// template <class T>
// Node<T>::Node(char chr, Node *rigth, Node* left)
// {
//     this->chr = chr;
//     left = NULL;
//     rigth = NULL;
// }

 // Getters
 template <class T>
char Node<T>::get_chr() const
{
return chr;
}

template <class T>
unsigned Node<T>::get_freq() const
{
return frequency;
}
    
// Setters
template <class T>
void Node<T>::set_chr(char chr)
{
this->chr = chr;
}

template <class T>
void Node<T>::set_freq(unsigned frequency)
{
this->frequency = frequency;
}

