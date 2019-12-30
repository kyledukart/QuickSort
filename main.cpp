#include <vector>
#include <iostream>
#include <stdlib.h>
#include "quicksort.cpp"
#include "arrayOps.cpp"
using namespace std;

extern void partialsort( vector<int> &items, int k );

void partialsort( vector<int> &items, int k ) {
  quicksort(items, 0, items.size(), k);
}

int main( int argc, char* argv[] ) {
  // verify arguments. if you find the median, no need of topK where argc == 2
  if ( argc != 3 ) {
    cerr << "usage: a.out size topK" << endl;
    return -1;
  }

  // verify an array size
  int size = atoi( argv[1] );
  if ( size <= 0 ) {
    cerr << "array size must be positive" << endl;
    return -1;
  }

  // verify top/bottom k. if you find the median, no need of the next 4 lines
  int topK = atoi( argv[2] );
  if ( topK <= 0 ) {
    cerr << "topX must be positive" << endl;
    return -1;
  }

  // array generation
  srand( 1 );
  vector<int> items( size );
  initArray( items, size );

  cout << "initial:" << endl;
  printArray( items, "items" );
  // partial quicksort. if you find the median, no need of the 2nd argument.
  partialsort( items, topK );

  cout << "sorted:" << endl;
  printArray( items, "items" );
  // print out the results here

  return 0;
}

