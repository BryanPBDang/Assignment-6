/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 6: Sorting algorithms
 Purpose:
 Methods: quicksort, insertion sort, bubble sort, and selection Sort
*/

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class SortAlgorithms
{
  public:
    SortAlgorithms(); // constructor
    ~SortAlgorithms(); // deconstructor

    //quickSort
    void quickSort(double arr[], int low, int high);
    void swap(double a, double b);
    int partition (double arr[], int low, int high);



    void insertSort(double arr[]);
    void bubbleSort(double myArray[]);
    void selectionSort(double arr[], int n);





    // executes all the swaping algorithms
    void mainSort(string name);

    double *temp;
    double *quickArr;
    double *insertArr;
    double *bubbleArr;
    double *selectionArr;

    // stores length of the array
    int length;
};

SortAlgorithms::SortAlgorithms()
{
  // constructor
}

SortAlgorithms::~SortAlgorithms()
{
  delete [] temp;
  delete [] quickArr;
  delete [] insertArr;
  delete [] bubbleArr;
  delete [] selectionArr;
}

//quickSort
void SortAlgorithms::swap(double a, double b)
{
    double t = a;
    a = b;
    b = t;
}

void SortAlgorithms::quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); // recursive function
        quickSort(arr, pi + 1, high); // recursive function
    }
}



int SortAlgorithms::partition (double arr[], int low, int high)
{
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//insertion
void SortAlgorithms::insertSort(double arr[]){
  for (int j = 1; j < length; ++j){
    double temp = arr[length];
    int k = j;
    while (k > 0 && arr[k-1] >= temp)
    {
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp;
  }
}

//bubble
void SortAlgorithms::bubbleSort(double myArray[])
{
  for (int i; i < length; ++i){
    int temp = 0;
    for (int j = 1; j < length - 1; ++j){
      if (myArray[j] > myArray[j+1]){
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

//selection
void SortAlgorithms::selectionSort(double arr[], int n){
  int i, j, minIndex, tmp;

  for (i = 0; i < n-1; i++){
    minIndex = i;
    for (j = i + 1; j < n; j++){
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    if (minIndex != i){
      tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
}

//Use all sorting
void SortAlgorithms::mainSort(string file)
{
  ifstream myFile;
  double data;
  string line;
  clock_t t; // for checking the time

  myFile.open(file);

  if (!myFile) { // file checking
    cerr << "Unable to open file " << file << endl;;
    exit(1);
  }

  getline(myFile, line);
  length = atof(line.c_str());


  double *temp = new double[length];
  double *quickArr = new double[length];
  double *insertArr = new double[length];
  double *bubbleArr = new double[length];
  double *selectionArr = new double[length];

  for( std::string line; getline( myFile, line ); )
  {
    for (int i = 0; i < line.length(); i++)
    {
      getline(myFile, line);
      data = atof(line.c_str());

      temp[i] = data;
    }
  }

  quickArr = temp;
  insertArr = temp;
  bubbleArr = temp;
  selectionArr = temp;

  myFile.close();

  srand(time(NULL));

  // cout time start
  t = clock();
  quickSort(quickArr, 0, length - 1);
  t = clock()-t;
  cout << "Quick Sort: " << t << " milliseconds!" << endl;

  t = clock();
  insertSort(insertArr);
  t = clock()-t;
  cout << "Insert Sort: " << t << " milliseconds!" << endl;

  t = clock();
  bubbleSort(bubbleArr);
  t = clock()-t;
  cout << "Bubble Sort: " << t << " milliseconds!" << endl;

  t = clock();
  selectionSort(selectionArr, length);
  t = clock()-t;
  cout << "Selection Sort: " << t << " milliseconds!" << endl;


  cout << "Done" << endl;
}
