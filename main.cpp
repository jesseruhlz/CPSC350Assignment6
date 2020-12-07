#include <iostream>
#include "Sortings.h"
using namespace std;

int main(int argc, char** argv){
  Sortings s;

  if(argc == 2){
    if (s.setFile(argv[1])){
      s.scanFile();
    }
    else{
      cout << "Error loading in file" << endl;
    }
  }
  else{
    cout << "Please give a file name in the command line" << endl;
  }
  return 0;
}
