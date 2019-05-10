#ifndef PROG1_H
#define PROG1_H
////////////////////////////////////////////////////////
// File: PROG1
// Name: James Wilson
// Date: 9/1/17
// Section: 1
// Due Date: 9/7/17
// Logon ID: z1739305
////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int VEC_SIZE = 250;

const int LOW = 1, HIGH = 10000, SEED = 1;

const int NO_ITEMS = 12, ITEM_W = 5;

class Prog1
   {
   void genRndNums(vector<int>&v);
   void printVec(const vector<int>&v);
   };

#endif
