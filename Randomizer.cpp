/*
*
* @authors - Oleksiy Al-saadi and Joshua Thurston
*
* @overview - Singleton Pattern implemented in Randomizer class
*/

#include "Randomizer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Randomizer *Randomizer::instance = NULL;

Randomizer *Randomizer::getInstance()
{
  if(instance == 0)
    instance = new Randomizer();
  return instance;
}

//Overloaded function for getInstance, calls similarly overloaded Randomizer constructor
Randomizer *Randomizer::getInstance(unsigned int List[], int s)
{

  if(instance == 0)
    instance = new Randomizer(List, s);
  return instance;
}


Randomizer::Randomizer()
{
  srand(time(NULL));
}

//Overloaded constructor for Randomizer, allows predefined values to return first.
Randomizer::Randomizer(unsigned int List[], int size){
  srand(time(NULL));
  list = new unsigned int[size];
  for (int n = 0; n < size; n++){
    list[n] = List[n];
  }
  count = size;
  m_size = size;
}


//Returns Random Value between minimum and maximum
unsigned int Randomizer::randomBetween(unsigned int minimum, unsigned int maximum)
{
  //Returns predefined values if they have not been returned yet.
  if (count > 0){
    count--;
    int c = count+1;
    return list[m_size-c];
  }  
  return rand() % (maximum-minimum) + minimum;
}

int main()
{
  unsigned int a[3] = {5,1,0};

  //First 3 calls defined already.
  cout << Randomizer::getInstance(a, sizeof(a))->randomBetween(1, 10) << endl;
  cout << Randomizer::getInstance(a, sizeof(a))->randomBetween(1, 10) << endl;
  cout << Randomizer::getInstance(a, sizeof(a))->randomBetween(1, 10) << endl;
  //Fourth is Random
  cout << Randomizer::getInstance(a, sizeof(a))->randomBetween(1, 10) << endl;


  return 1;
}

