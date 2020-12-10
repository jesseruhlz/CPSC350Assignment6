//sortings implementaion file
#include "Sortings.h"
using namespace std;

Sortings::Sortings(){};

Sortings::~Sortings(){
  delete [] quickSortArray;
}

bool Sortings::setFile(string name){
  ifstream inFile;
  inFile.open(name.c_str());

  if (inFile.is_open()){
  cout << endl;
  cout << "File: " << name.c_str() << " was loaded." << endl;
  inFile.close();
  fileName = name;
  return true;
  }
  else{
    return false;
  }
}

void Sortings::scanFile(){
  ifstream inputFile;
  inputFile.open(fileName.c_str());

  string numElementsString;
  string line;
  double size;
  int lineNumber = 1;

  getline(inputFile, numElementsString);

  try{
    numElements = stoi(numElementsString);
  }

  catch(exception e){
    cout << "Error Reading File" << endl;
    return;
  }

  quickSortArray = new double[numElements];
  insertionSortArray = new double[numElements];
  bubbleSortArray = new double[numElements];
  selectionSortArray = new double[numElements];

  //populate arrays
  for (int i = 0; i < numElements; ++i){
    lineNumber++;
    getline(inputFile, line);

    try{
      size = stod(line);
    }
    catch(exception e){
      cout << "Error Reading File: Invalid Format" << endl;
      return;
    }
    quickSortArray[i] = size;
    insertionSortArray[i] = size;
    bubbleSortArray[i] = size;
    selectionSortArray[i] = size;
  }
  inputFile.close();
  sortAll();
}

string Sortings::getFileName(){
  return fileName;
}

void Sortings::quickSort(double array[], int left, int right){
  int index = partition(array, left, right);

  //sort left half
  if (left < index - 1){
    quickSort(array, left, index - 1);
  }
  if (right > index){
    quickSort(array, index, right);
  }
}

int Sortings::partition(double array[], int left, int right){
  int pivot = array[(left + right) / 2];
  while (left <= right){
    //objects to left of pivot
    while (array[left] < pivot){
      left++;
    }

    //objects to right of pivot in array
    while (array[right] > pivot){
      right--;
    }

    //swap elements and move left and right objects
    if (left <= right){
      swap(array, left, right);
      left++;
      right--;
    }
  }
  return left;
}

void Sortings::insertionSort(double array[]){
  for (int j = 1; j < numElements; ++j){
    //store marked item
    double temp = array[j];
    //where to start shifitng
    int k = j;

    while (k > 0 && array[k-1] >= temp){
      array[k] = array[k-1];
      --k;
    }
    //place marked item in correct spot
    array[k] = temp;
  }
}

void Sortings::bubbleSort(double array[]){
  for (int i = 0; i < numElements - 1; ++i){
    //last i elements are already in place
    for (int j = 0; j < numElements-i-1; ++j){
      if (array[j] > array[j+1]){
        swapBubble(&array[j], &array[j+1]);
        //or could implement the swap here like so
        //int temp = array[j];
        //array[j] = array[j+1];
        //array[j+1] = temp;
      }
    }
  }
}

void Sortings::selectionSort(double array[]){
  int minIndex;
  for (int i = 0; i < numElements - 1; ++i){
    //double minIndex;
    minIndex = i;
    for (int j = i + 1; j < numElements; ++j){
      if (array[j] < array[minIndex]){
        minIndex = j;
      }
      swapBubble(&array[minIndex], & array[i]);
    }
  }
}


void Sortings::merge(double array[], int left, int middle, int right){
  /*
  cout << "merge code" << endl;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  double leftArray[n1], rightArray[n2];
  cout << "copy data to temp arrays" << endl;
  for (int i = 0; i < n1; ++i){
    leftArray[i] = array[left + i];
  }
  for (int j = 0; j < n2; ++j){
    rightArray[j] = array[middle + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;
  cout << "merge temp arrays to real arrays" << endl;
  while (i < n1 && j < n2){
    cout << "merging arrays" << endl;
    if (leftArray[i] <= rightArray[j]){
      array[k] = leftArray[i];
      i++;
    }
    else{
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }
  cout << "copy remaining elements of leftArr if any" << endl;
  while (i < n1){
    array[k] = leftArray[i];
    i++;
    k++;
  }
  cout << "copy of remaining elements of rightArr" << endl;
  while (j < n2){
    array[k] = rightArray[j];
    j++;
    k++;
  }
  */

  double temp[(right - left) + 1];
  int i = left;
  int j = middle + 1;
  int k = 0;
  //cout << "traverse both array and each iteration add smaller of both items" << endl;
  while (i <= middle && j <= right){
    if (array[i] <= array[j]){
      temp[k] = array[i];
      k++;
      i++;
    }
    else{
      temp[k] = array[j];
      k++;
      j++;
    }
  }
  //cout << "add elements left in the first interval" << endl;
  while (i <= middle){
    temp[k] = array[i];
    k++;
    i++;
  }
  //cout << "add elements left in the second interval" << endl;
  while (j <= right){
    temp[k] = array[j];
    k++;
    j++;
  }
  cout << "copy temp to original interval" << endl;
  for (i = left; i < k; ++i){
    //cout << "copying temp" << endl;
    array[i] = temp[i];
    //array[i + k] = temp[k];
  }
}


void Sortings::mergeSort(double array[], int left, int right){
  //cout << "mergeSort code" << endl;
  /*
  if(left >= right){
    return;
  }
  int middle = (left + right) / 2;
  mergeSort(array,left,middle);
  mergeSort(array,middle+1,right);
  merge(array,left,middle,right);
  */
  int middle = 0;
  if (right > left){
    return;
  }
  if (left < right){
    middle = (left + right) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
  }
}

void Sortings::swap(double array[], int a, int b){
  double tempArray = array[a];
  array[a] = array[b];
  array[b] = tempArray;
}

void Sortings::swapBubble(double *xp, double *yp){
  double temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void Sortings::sortAll(){
  clock_t timeStart;
  clock_t timeEnd;
  float calculatedTime;

  cout << "\n   -SORTING -\n* ------------ *\n";

  //quick sort
  timeStart = clock();
  quickSort(quickSortArray, 0, numElements -1);
  timeEnd = clock();

  calculatedTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
  cout << endl;
  cout << "Quick Sort took " << calculatedTime << " ms to sort " << numElements << " numbers." << endl;

  //insertion sort
  timeStart = clock();
  insertionSort(insertionSortArray);
  timeEnd = clock();
  calculatedTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
  cout << endl;
  cout << "Insertion Sort took " << calculatedTime << " ms to sort " << numElements << " numbers." << endl;

  //bubble sort
  timeStart = clock();
  bubbleSort(bubbleSortArray);
  timeEnd = clock();
  calculatedTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
  cout << endl;
  cout << "Bubble Sort took " << calculatedTime << " ms to sort " << numElements << " numbers." << endl;

  //selection sort
  timeStart = clock();
  selectionSort(selectionSortArray);
  timeEnd = clock();
  calculatedTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
  cout << endl;
  cout << "Selection Sort took " << calculatedTime << " ms to sort " << numElements << " numbers." << endl;

  //merge sort
  timeStart = clock();
  mergeSort(mergeSortArray, 0, numElements -1);
  timeEnd = clock();

  calculatedTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
  cout << endl;
  cout << "Merge Sort took " << calculatedTime << " ms to sort " << numElements << " numbers." << endl;

}
