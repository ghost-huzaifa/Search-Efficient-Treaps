#include <cstdlib>
#include <iostream>
#include "include/Treap.h"
#include <chrono>
using namespace std;

int main(){
  /*long int size = 10000;

 for(int i = 0; i < 4; i++){
   Treap<int>* treap = new Treap<int>;
   for(int i = 0; i < size; i++)
    {
      treap->insert(rand());
    }
   treap->insert(1000);
    cout << "Root Value at the beginning: ";
    treap->printRootValue();
    auto startTime = std::chrono::high_resolution_clock::now();
    bool f = treap->search(1000);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsedTime = endTime - startTime;
    cout << "N = " << size << endl;
    cout << "Time Taken: " <<  elapsedTime.count() << endl;
    treap->printRootValue();
    auto startTime1 = std::chrono::high_resolution_clock::now();
    treap->search(50);
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto startTime2 = std::chrono::high_resolution_clock::now();
    treap->search(50);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto startTime3 = std::chrono::high_resolution_clock::now();
    treap->search(50);
    auto endTime3 = std::chrono::high_resolution_clock::now();
    auto startTime4 = std::chrono::high_resolution_clock::now();
    treap->search(1000);
    auto endTime4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsedTime4 = endTime4 - startTime4;
    cout << "Second Time Taken by 1000: " << elapsedTime4.count();
    treap->printRootValue();
    delete treap;
    size *= 10;
  }
*/
    Treap<int> treap;
    treap.readCSV("dataset.csv");
    bool flag = 0;
    do
    {
        int element, option;
        cout << "1. Insert Element" << endl
            << "2. Remove Element" << endl
            << "3. Search Element" << endl
            << "4. InOrder Traversal" << endl
            << "5. Print Root Value" << endl
            << "6. Exit" << endl << endl
            << "Option : ";
        cin >> option;
        switch(option)
        {
        case 1:
            cout << "Enter Element to Insert : ";
            cin >> element;
            treap.insert(element);
            break;
        case 2:
            cout << "Enter Element to Remove : ";
            cin >> element;
            treap.remove(element);
            break;
        case 3:
            cout << "Enter Element to Search : ";
            cin >> element;
            cout << "Search Result : " << treap.search(element) << endl;
            break;
        case 4:
            treap.traverse_inOrder();
            break;
        case 5:
            treap.printRootValue();
            break;
        case 6:
            flag = 1;
            break;
        default:
            cout << "Invalid Input! try again!" << endl;
        }
    }while (!flag);

  return 0;
}
