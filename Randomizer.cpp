#include "Randomizer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Randomizer *Randomizer::instance = NULL;

Randomizer * Randomizer::getInstance()
{
  if(instance == 0)
    instance = new Randomizer();
  return instance;
}

Randomizer::Randomizer()
{
  srand(time(NULL));
}

unsigned int Randomizer::randomBetween(unsigned int minimum, unsigned int maximum)
{
    return rand() % (maximum-minimum) + minimum;
}

int main()
{
  cout << Randomizer::getInstance()->randomBetween(1, 10) << endl;
  return 1;
}

