#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "Randomizer.h"

class Randomizer
{
  private:
    static Randomizer* instance;
    Randomizer();
    Randomizer(unsigned int list);
    int count;

  public:
    static Randomizer* getInstance();

    unsigned int randomBetween(unsigned int minimum, unsigned int maximum);
};
#endif
