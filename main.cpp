#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AVL.h"
#include "Treap.h"

using namespace std;

int main () {
  cout << "Testing the main" << endl;
  Treap<int> tree1;
  cout << "Tree created" << endl;
  srand(time(NULL));
  for(int i = 0; i < 50; i++)
  {
    cout << "Insertion : " << i << endl;
    tree1.insert(rand() % 1000, rand() % 50);
  }
  tree1.insert(1, 1);
  cout << endl;
  tree1.insert(3, 2);
  cout << endl;
  tree1.insert(10001, 88);
  cout << endl;
  cout <<"Traversing InOrder: " << endl;
  tree1.traverse_inOrder();
  cout << "Searching for entered key 1: " << tree1.search(1) << endl;
  cout << "Searching for entered key 3: " << tree1.search(3) << endl;
  cout << "Searching for wrong key: " << tree1.search(10000) << endl;
  cout <<"Traversing InOrder: " << endl;
  tree1.traverse_inOrder();
  cout << "Value at root : ";
  tree1.printRootValue();



  return 0;
}
