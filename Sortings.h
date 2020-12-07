//sortings.h header file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Sortings{
  private:
    string fileName;
    int numElements;

    //array for quick sort
    double *quickSortArray;
    //array for insertion sort
    double *insertionSortArray;
    //array for bubble sort
    double *bubbleSortArray;
    //array for selection sort
    double *selectionSortArray;

  public:
    Sortings();
    ~Sortings();

    bool setFile(string file);
    void scanFile();
    string getFileName();

    void quickSort(double array[], int left, int right);
    int partition(double array[], int left, int right);
    void swap(double array[], int a, int b);

    void insertionSort(double array[]);

    void bubbleSort(double array[]);
    void swapBubble(double *xp, double *yp);

    void selectionSort(double array[]);

    void sortAll();

};
