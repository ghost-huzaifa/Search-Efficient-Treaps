#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <class Comparable>
struct BinaryNode                               //Node Structure
{
    Comparable element;
    int priority = 0;
    BinaryNode<Comparable>* left;
    BinaryNode<Comparable>* right;
    int height;
};

template <class Comparable>
class BinaryTree
{
public:
    BinaryTree();                               //Constructors
    BinaryTree(BinaryNode<Comparable>* root);
    BinaryTree(const BinaryTree& t);

    virtual ~BinaryTree();                      //Destructor

    virtual void insert(const Comparable x);    //Level-Order Insertion

    Comparable root();                          //Get Attributes of Node Structure as value
    BinaryTree left();
    BinaryTree right();

    void traverse_inOrder();                    //Public Traversal Functions to print Tree
    void traverse_preOrder();
    void traverse_postOrder();

    void make_empty();                          //Deletes all nodes of Tree using deleteTree function

    bool empty() const;                         //Checks if the tree is empty

private:
    void traverse_inOrder(BinaryNode<Comparable>* root);                    //Private Traversal Functions to print Tree
    void traverse_preOrder(BinaryNode<Comparable>* root);
    void traverse_postOrder(BinaryNode<Comparable>* root);

    void deleteTree(BinaryNode<Comparable>* root);                          //deletes the tree in a postOrder method

protected:
    BinaryNode<Comparable>* tree_root;                                      //Stores address of root node of tree

    BinaryNode<Comparable>* create_node(Comparable data);                   //Node Creation functions
    BinaryNode<Comparable>* create_node(Comparable data, int priority);

    BinaryNode<Comparable>* copyTree(BinaryNode<Comparable>* root);         //Make Deep copy of Tree
};
