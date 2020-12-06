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

  public:
    Sortings();
    ~Sortings();

    bool setFile(string file);
    void scanFile();

    void quickSort(double array[], int left, int right);
    int partition(double array[], int left, int right);
    void swap(double array[], int a, int b);
};
