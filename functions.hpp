/*Monte Roybal
Shopping Cart Functions Header File*/

/*Link Section*/
#ifndef functions_h 
#define functions_h
#include <iostream>
#include "cart.hpp"
#include "item.hpp"
using namespace std;

int addSingItems(Cart *s,Item *i,Item *i1,Item *i2,int c,int a,string m);//Add Single Item Function Declaration
int addMultItems(Cart *s,Item *i,Item *i1,Item *i2,int c,int a);//Add Multiple Items Declaration
int printToFile(Cart *s,int c);//Print Cart Contents to File Declaration
#endif