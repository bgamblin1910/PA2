/*
 Name: Ben Gamblin
 Class: CptS 122, Spring 2022
 Date: 2/8/2022
 Programming Assignment: PA2                                                                      
 Description: This program tracks time and operation counts for sorting algorithms and outputs them to csv files
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
void fillVectorAscend(vector<int> &filling, int length);
void fillVectorDescend(vector<int> &filling, int length);
void fillVectorRand(vector<int> &filling, int length);
void selectionSortVec(vector<int> &vec, int length, long arr[]);
void bubbleSortVec(vector<int> &vec, int length,long arr[]);
void insertionSortVec(vector<int> &vec, int length,long arr[]);
void printVec(vector<int> &vec);
void totalReset(long arr[], ofstream& File, string fileName, string title, int num);
