#ifndef PROG2_H
#define PROG2_H
////////////////////////////////////////////////////////
// File: PROG2
// Name: James Wilson
// Date: 9/8/17
// Section: 1
// Due Date: 9/14/17
// Logon ID: z1739305
////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int TEST_ARR_SIZE = 100;
const int ARR_SIZE = 200;
const int SEED1 = 1;
const int SEED2 = 3;
const int LOW = 1;
const int HIGH = 1000;

//prototypes
void Vectors(vector<int>&, vector<int>&, int, int);
bool linearSearch(const vector<int>&, int);
bool binarySearch(const vector<int>&, int);
int search(const vector<int>&, const vector<int>&, bool (*p)(const vector<int>&, int));
void sortVector(vector<int>&);
void printVector(const vector<int>&);
void printStat(int, int);

#endif
