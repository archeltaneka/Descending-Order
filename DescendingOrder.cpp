// Case Study Modification #2
// Modify Program 9-19 (the United Cause case study program) so the arrptr array is
// sorted in descending order instead of ascending order.

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
#include <fstream>
using namespace std;

// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

// global variables for output file
ofstream outputFile; // output file

int main()
{
const int NUM_DONATIONS = 15; // Number of donations


// An array containing the donation amounts.
int donations[NUM_DONATIONS] = { 5, 100, 5, 25, 10,
								 5, 25, 5, 5, 100,
								 10, 15, 10, 5, 10 };

// An array of pointers to int.
int *arrPtr[NUM_DONATIONS]; /*= {nullptr, nullptr, nullptr, nullptr, nullptr,
							  nullptr, nullptr, nullptr, nullptr, nullptr,
							  nullptr, nullptr, nullptr, nullptr, nullptr };*/

// Each element of arrPtr is a pointer to int. Make each
// element point to an element in the donations array.
for (int count = 0; count < NUM_DONATIONS; count++)
	arrPtr[count] = &donations[count];

// Sort the elements of the array of pointers.
arrSelectSort(arrPtr, NUM_DONATIONS);

// open outputFile
outputFile.open("DescendingOrder.txt");

// Display the donations using the array of pointers. This
// will display them in sorted order.
outputFile << "The donations, sorted in descending order are: \n";
showArrPtr(arrPtr, NUM_DONATIONS);

// Display the donations in their original order.
outputFile << "The donations, in their original order are: \n";
showArray(donations, NUM_DONATIONS);

cout << "The donations are saved in the DescendingOrder.txt file!";

return 0;

// close outputFile
outputFile.close();

}

//****************************************************************
// Definition of function arrSelectSort. *
// This function performs an descending order selection sort on *
// arr, which is an array of pointers. Each element of array *
// points to an element of a second array. After the sort, *
// arr will point to the elements of the second array in *
// descending order. *
//****************************************************************

void arrSelectSort(int *arr[], int size)
{
 int startScan, maxIndex;
 int *maxElem;

 for (startScan = 0; startScan < (size - 1); startScan++)
 {
 maxIndex = startScan;
 maxElem = arr[startScan];
 for(int index = startScan + 1; index < size; index++)
 {
if (*(arr[index]) > *maxElem)
{
 maxElem = arr[index];
 maxIndex = index;
 }
 }
 arr[maxIndex] = arr[startScan];
 arr[startScan] = maxElem;
 }
 }

//***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
//*********************************************************** 
void showArray(const int arr[], int size)
{
 for (int count = 0; count < size; count++)
outputFile << arr[count] << " ";
outputFile << endl;
 }

 //***************************************************************
 // Definition of function showArrPtr. *
 // This function displays the contents of the array pointed to *
 // by arr. size is the number of elements. *
 //***************************************************************

void showArrPtr(int *arr[], int size)
 {
 for (int count = 0; count < size; count++)
 outputFile << *(arr[count]) << " ";
 outputFile << endl;
 }
