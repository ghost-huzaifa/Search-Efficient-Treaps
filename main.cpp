#include <cstdlib>
#include <iostream>
#include "include/Treap.h"
#include <chrono>
using namespace std;

int main(){
  long int size = 10000;
  Treap<int> treap;
  for(int i = 0; i < 5; i++){
    for(int i = 0; i < size; i++)
    {
      treap.insert(rand(), rand()%1000);
    }
    treap.insert(1000, 1000); 
    auto startTime = std::chrono::high_resolution_clock::now();
    treap.search(1000);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsedTime = endTime - startTime;
    cout << "N = " << size << endl;
    cout << "Time Taken: " <<  elapsedTime.count() << endl;
    size *= 10;
  }


  return 0;
}
