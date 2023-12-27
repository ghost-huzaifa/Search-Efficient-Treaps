#pragma once
#include "BInaryTree.h"


template <class Comparable>
class BST : public BinaryTree<Comparable>
{
public:
//constructors
    BST();
    BST(BinaryNode<Comparable>* root);
//destructor
    virtual ~BST();
//search an element
    bool search(const Comparable data);
//find minimum element
    BinaryNode<Comparable>* findMin();
//find maximum element
    BinaryNode<Comparable>* findMax();
//compose x into a tree
    virtual void insert(const Comparable data);
//decompose x from a tree
    void remove(const Comparable data);
private:
//compose x into a tree (recursive insert)
    void insert(const Comparable data, BinaryNode<Comparable>*& root);
//decompose x from a tree (recursive delete)
    void remove(const Comparable data, BinaryNode<Comparable>*& root);
protected:
//find minimum element recursively
    BinaryNode<Comparable>* findMin(BinaryNode<Comparable>* root);
//find maximum element recursively
    BinaryNode<Comparable>* findMax(BinaryNode<Comparable>* root);
};

