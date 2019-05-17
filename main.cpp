/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 6: Sorting algorithms
 Purpose:
 Methods: Main/Driver
*/

#include <iostream>
#include <fstream>
#include "SortAlgorithms.h"

using namespace std;

int main(int argc, char** argv)
{
  SortAlgorithms s;
  string file;

  if(argc < 2) {
      cout << "Please Enter Valid File Input" << endl;
  }

  else if(argc >= 2) {
      file = argv[1];
  }
  s.mainSort(file);
}
