#ifndef PROG4_H
#define PROG4_H
/************************************************************************
    CSCI 340 section 1
    TA: Daniel Baker
    James Wilson
    z1739305
    Assignment: 4
    Date Due: 9-28-17

    Description: Program to recieve, clean, and display empty and non empty
                 words
*************************************************************************/
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;

int NO_ITEMS = 3;
int ITEM_W = 16;

void get_words(map <string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);

#endif
