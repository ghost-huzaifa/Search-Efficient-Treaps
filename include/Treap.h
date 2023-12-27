#ifndef TREAP_H
#define TREAP_H

#include "BST.h"

template <class Comparable>
class Treap : public BST <Comparable>
{
public:
    Treap();
    Treap(const Treap<Comparable> &t);
    void insert(const Comparable x);
    void remove(const Comparable x);
    bool search(const Comparable x);
    void printRootValue();
    virtual ~Treap();

private:
    int _nsePriorityLimit = 1000;
    void insert(const Comparable x, BinaryNode<Comparable>* &root);
    void remove(const Comparable x, BinaryNode<Comparable>* &root);
    bool search(const Comparable x, BinaryNode<Comparable>* &root);
    BinaryNode<Comparable>* singleLeftRotation(BinaryNode<Comparable>* &k2);
    BinaryNode<Comparable>* singleRightRotation(BinaryNode<Comparable>* &k2);
};

#endif // TREAP_H
