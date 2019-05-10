#ifndef PROG3_H
#define PROG3_H
/************************************************************************
    CSCI 340 section 1
    TA: Daniel Baker
    James Wilson
    z1739305
    Assignment: 1
    Date Due: 9-21-17

    Description: To implement the sieve of Eratosthenes
*************************************************************************/
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

int NO_ITEMS = 16;
int ITEM_W = 4;

//prototypes
void sieve(set<int>&, int);
void print_primes(const set<int>&);

#endif
