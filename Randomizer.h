/*
* @authors - Oleksiy Al-saadi and Joshua Thurston
* 
* @overview - Header class for Randomizer
*/

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "Randomizer.h"

class Randomizer
{
  private:
    static Randomizer* instance;
    Randomizer();
    Randomizer(unsigned int List[], int s);
    int count;
    int m_size;
    unsigned int *list;

  public:
    static Randomizer* getInstance();
    static Randomizer* getInstance(unsigned int List[], int s);
    
    unsigned int randomBetween(unsigned int minimum, unsigned int maximum);
};
#endif
