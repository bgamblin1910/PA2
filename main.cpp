/*
 Name: Ben Gamblin
 Class: CptS 122, Spring 2022
 Date: 2/8/2022
 Programming Assignment: PA2                                                                      
 Description: This program tracks time and operation counts for sorting algorithms and outputs them to csv files
*/
#include "SortFunction.h"

int main() {
    //this part clears the file out of any previous contents.
    ofstream myFile;
    ofstream myFile2;
    ofstream myFile3;
    myFile.open("selection_sort_results.csv");
    myFile2.open("bubble_sort_results.csv");
    myFile3.open("insertion_sort_results.csv");
    myFile << "";
    myFile2 << "";
    myFile3 <<"";
    myFile.close();
    myFile2.close();
    myFile3.close();



    //1st is Data Comp, 2nd is loopcomp, 3rd is data assignment, 4th is loop assignment, 5th is other and 6th stores time
    long counter [6] = {0,0,0,0,0,0};

    //array for each input value
    int number[4] = {500,1000,5000,10000};
    
    // three nodes are used so that we use the same values for each sorting algorithm
    vector<int> node;
    vector<int> node2;
    vector<int> node3;
    
    // loop so it goes through each number input value
    for(int i = 0; i < 4; i++)
    {
    fillVectorAscend( node, number[i]);
    node2 = node;
    node3 = node;
    selectionSortVec(node, node.size(), counter);
        totalReset(counter, myFile, "selection_sort_results.csv", "Selection Ascend", number[i]);
    bubbleSortVec(node2, node2.size(), counter);
    totalReset(counter, myFile2, "bubble_sort_results.csv", "Bubble Ascend", number[i]);
    insertionSortVec(node3, node3.size(), counter);
    totalReset(counter, myFile3, "insertion_sort_results.csv", "Insertion Ascend", number[i]);
    node.clear();}
    
    for(int j = 0; j < 4; j++)
    {
    fillVectorDescend( node, number[j]);
    node2 = node;
    node3 = node;
    selectionSortVec(node, node.size(), counter);
        totalReset(counter, myFile, "selection_sort_results.csv", "Selection Descend", number[j]);
    bubbleSortVec(node2, node2.size(), counter);
    totalReset(counter, myFile2, "bubble_sort_results.csv", "Bubble Descend", number[j]);
    insertionSortVec(node3, node3.size(), counter);
    totalReset(counter, myFile3, "insertion_sort_results.csv", "Insertion Descend", number[j]);
    node.clear();
    }
    
    for(int L = 0; L < 4; L++)
    {fillVectorRand( node, number[L]);
    node2 = node;
    node3 = node;
    selectionSortVec(node, node.size(), counter);
    totalReset(counter, myFile, "selection_sort_results.csv", "Selection Rand", number[L]);
    bubbleSortVec(node2, node2.size(), counter);
    totalReset(counter, myFile2, "bubble_sort_results.csv", "Bubble Rand", number[L]);
    insertionSortVec(node3, node3.size(), counter);
    totalReset(counter, myFile3, "insertion_sort_results.csv", "Insertion Rand", number[L]);
    node.clear();
    
    }

    return 0;
}