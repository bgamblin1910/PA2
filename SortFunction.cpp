/*
 Name: Ben Gamblin
 Class: CptS 122, Spring 2022
 Date: 2/8/2022
 Programming Assignment: PA2                                                                      
 Description: This program tracks time and operation counts for sorting algorithms and outputs them to csv files
 Help: StarterCode
*/
#include "SortFunction.h"
/*************************************************************
 * Function: fillVectorAscend()                 	
 * Date Created: 2/6/2022                  	        
 * Date Last Modified: 2/7/2022                      
 * Description: This function fills a vector so it ascends in values                    	
 * Input parameters: the vector being filled, and the wanted length of said vector   	
 * Returns: Nothing          	
 * Pre: need to type in what length you want     	
 * Post: fills a vector 
 *************************************************************/

void fillVectorAscend(vector<int> &filling, int length )
{
    
    for(int i = 0; i < length; i++)
    {
       filling.push_back(i);
    }
}
/*************************************************************
 * Function: fillVectorDescend()                	
 * Date Created: 2/6/2022                  	        
 * Date Last Modified: 2/7/2022                      
 * Description: This function fills a vector so it descends in values                    	
 * Input parameters: the vector being filled, and the wanted length of said vector   	
 * Returns: Nothing          	
 * Pre: need to type in what length you want     	
 * Post: fills a vector 
 *************************************************************/
void fillVectorDescend(vector<int> &filling, int length)
{

    
    for(int i = length-1; i > -1; i--)
    {
       filling.push_back(i);

    }
}
/*************************************************************
 * Function: fillVectorRand()                	
 * Date Created: 2/6/2022                  	        
 * Date Last Modified: 2/7/2022                      
 * Description: This function fills a vector so it random in value order                    	
 * Input parameters: the vector being filled, and the wanted length of said vector   	
 * Returns: Nothing          	
 * Pre: need to type in what length you want     	
 * Post: fills a vector 
 *************************************************************/
void fillVectorRand(vector<int> &filling, int length)
{
    
    
    for(int i = 0; i < length; i++)
    {
        int y = (rand()%length);
       filling.push_back(y);
       
    }
}
/*************************************************************
 * Function: selectionSortVec()                	
 * Date Created: 2/7/2022                  	        
 * Date Last Modified: 2/8/2022                      
 * Description: This function sorts a vector in ascending order from front to back.                 	
 * Input parameters: the vector being sorted, the length of the vector, array for counting operations  	
 * Returns: Nothing          	
 * Pre: need to make array for counting operation     	
 * Post: sorts a vector
 *************************************************************/
void selectionSortVec(vector<int> &vec, int length,long arr[])
{
    auto start = high_resolution_clock::now();
    arr[4] += 2;
    int minIndex, minValue;
    arr[3] += 1;
   for (int i = 0; i < (length - 1); i++) {
    arr[1] += 1;
    arr[3] += 1;
      minIndex = i;
      minValue = vec[i];
      arr[2] += 1;
      arr[4] += 1;
      arr[3] += 1;
      for (int index = i + 1; index < length; index++) {
        arr[1] += 1;
        arr[3] += 1;
        
         if (vec[index] < minValue) {
            
            minValue = vec[index];
            minIndex = index;
            arr[2] += 1;
            arr[4] += 1;
         }
         arr[0] += 1;
      }
      arr[1] += 1;
      swap(vec[minIndex], vec[i]);
      arr[2] += 3;
   
    } 
    arr[1] += 1;  
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    arr[5] += duration.count();
}
/*************************************************************
 * Function: bubbleSortVec()                	
 * Date Created: 2/7/2022                  	        
 * Date Last Modified: 2/8/2022                      
 * Description: This function sorts a vector in, ascending order, from back to front.                 	
 * Input parameters: the vector being sorted, the length of the vector, array for counting operations  	
 * Returns: Nothing          	
 * Pre: need to make array for counting operation     	
 * Post: sorts a vector
 *************************************************************/
void bubbleSortVec(vector<int> &vec, int length, long arr[])
{
    auto start = high_resolution_clock::now();

    int maxIndex, maxValue;

    arr[4] +=2;
    arr[3] +=1;

   for (int i = length -1; i > -1; i--) {

    arr[1] += 1;
    arr[3] += 1;

      maxIndex = i;
      maxValue = vec[i];

      arr[2] += 1;
      arr[4] += 1;
      arr[3] += 1;

      for (int index = i -1; index > -1; index--) {
        
        arr[1] += 1;
        arr[3] += 1;

         if (vec[index] > maxValue) {

            maxValue = vec[index];
            maxIndex = index;

            arr[2] += 2;
        
         }
         arr[0] += 1;
      }
      arr[1] += 1;

      swap(vec[maxIndex], vec[i]);

      arr[2] += 3;
   
    }   
    arr[1] += 1; 
auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    arr[5] = duration.count();
}
/*************************************************************
 * Function: selectionSortVec()                	
 * Date Created: 2/7/2022                  	        
 * Date Last Modified: 2/8/2022                      
 * Description: This function sorts a vector in ascending order by putting cards in a sorted section like when you play cards.                	
 * Input parameters: the vector being sorted, the length of the vector, array for counting operations  	
 * Returns: Nothing          	
 * Pre: need to make array for counting operation     	
 * Post: sorts a vector
 *************************************************************/
void insertionSortVec(vector<int> &vec, int length, long arr[]) {
	
    auto start = high_resolution_clock::now();
    int i,j,currValue;

    arr[4] +=3;
    arr[3] += 1;

    	for ( i = 1; i < length; i++) {

        arr[1] +=1;
        arr[3] += 1;

		currValue = vec[i];

        arr[2] += 1;
		j = i - 1;
        arr[4] += 1;
		while (j >= 0 && currValue < vec[j]) {
			arr[1] += 2;
            vec[j + 1] = vec[j];
            arr[2] += 1;
			j--;
            arr[3] +=1;
		}
        arr[1] += 1;
		vec[j + 1] = currValue;
        arr[2] += 1;
	}
    arr[1] += 1;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    arr[5] = duration.count();
}
/*************************************************************
 * MAINLY USED FOR TESTING. KEEP FOR FURTHER TESTING IF NEED BE
 * Function: printVec()                	
 * Date Created: 2/7/2022                  	        
 * Date Last Modified: 2/8/2022                      
 * Description: This function prints a vectors content                	
 * Input parameters: vector being printed	
 * Returns: vector contents printed         	
 * Pre: vector with contents    	
 * Post: nothing.
 *************************************************************/
// void printVec(vector<int> &vec)
// {
//     for(int i = 0; i < vec.size(); i ++)
//     {
//         cout << vec[i]<<endl;
//     }
// }
/*************************************************************
 * Function: totalReset()                	
 * Date Created: 2/7/2022                  	        
 * Date Last Modified: 2/8/2022                      
 * Description: This function outputs the vector contents and other contents to an output file                	
 * Input parameters: array, File, filename, title array contents and number of array inputs	
 * Returns: File with array contents         	
 * Pre:File is emptied and array has contents    	
 * Post: array is emptied
 *************************************************************/
void totalReset(long arr[], ofstream& File, string fileName, string title, int num)
{
    
    File.open(fileName,_S_app);
    File << title << " ," << num << ",";
    int total = 0;
    File << arr[5]<< ",";
    arr[5] =0;
    for(int i = 0; i < 5; i++)
    {
        total += arr[i];
        File << arr[i]<< ",";
        arr[i] = 0 ;
        
        
    }
    File << total<< ","<< endl;
    File.close();
}