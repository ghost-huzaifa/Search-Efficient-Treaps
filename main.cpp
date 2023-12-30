#include <iostream>
#include "include/Treap.h"
using namespace std;

int main(){
    Treap<int> treap;
    treap.readCSV("dataset.csv");       //Read data from csv file

    bool flag = 0;
    do
    {
        int element, option;
        cout << endl << "************************************************************" << endl      //Display Menu
            << "*      FREQSEARCH - A frequency based searching system     *" << endl
            << "************************************************************" << endl
            << "\t1. Insert Element" << endl
            << "\t2. Remove Element" << endl
            << "\t3. Search Element" << endl
            << "\t4. InOrder Traversal" << endl
            << "\t5. Print Root Value" << endl
            << "\t6. Exit" << endl << endl
            << "Option : ";
        cin >> option;
        switch(option)                  //Select operation based on the option selected
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
