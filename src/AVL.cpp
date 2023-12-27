#include "../include/AVL.h"
#include <string>
#include <algorithm>

template class AVL<int>;
template class AVL<float>;
template class AVL<double>;
template class AVL<char>;
template class AVL<std::string>;
template class AVL<short>;
template class AVL<long>;

static const int ALLOWED_IMBALANCE = 1;

template <class Comparable>
AVL<Comparable>::AVL() {}

template <class Comparable>
AVL<Comparable>::AVL(const AVL<Comparable>  &t) : BST<Comparable>(t) {}

template <class Comparable>
int AVL<Comparable>::height(BinaryNode<Comparable>* root) const
{
    return root == NULL ? -1 : root->height;
}

template <class Comparable>
void AVL<Comparable>::insert(const Comparable x)
{
    insert(x, BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
void AVL<Comparable>::insert(const Comparable x, BinaryNode<Comparable>* &root)
{
    if (root == NULL)
    {
        root = new BinaryNode<Comparable>;
        root->element = x;
        root->priority = 0;
        root->left = root->right = NULL;
    }
    else if (x < root->element)
        insert(x, root->left);
    else if (x > root->element)
        insert(x, root->right);
    AVL<Comparable>::balance(root);
}
template <class Comparable>
void AVL<Comparable>::balance(BinaryNode<Comparable>* &root)
{
    if(root == NULL)
    {
        return;
    }
    if(height(root->left) - height(root->right) > ALLOWED_IMBALANCE)
    {
        if(height(root->left->left) >= height(root->left->right))
            singleLeftRotation(root);
        else
            doubleLeftRotation(root);
    }
    else if(height(root->right) - height(root->left) > ALLOWED_IMBALANCE)
    {
        if(height(root->right->right) >= height(root->right->left))
            singleRightRotation(root);
        else
        {
            doubleRightRotation(root);
        }
    }
    root->height = max(height(root->left), height(root->right)) + 1; //Get the max height from left and right and increment by 1
}
template <class Comparable>
void AVL<Comparable>::singleLeftRotation(BinaryNode<Comparable>* &k2)
{
    BinaryNode<Comparable>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <class Comparable>
void AVL<Comparable>::singleRightRotation(BinaryNode<Comparable>* &k2)
{
    BinaryNode<Comparable>* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->right), height(k2->left)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

template <class Comparable>
void AVL<Comparable>::doubleLeftRotation(BinaryNode<Comparable>* &k3)
{
    singleRightRotation(k3->left);
    singleLeftRotation(k3);
}

template <class Comparable>
void AVL<Comparable>::doubleRightRotation(BinaryNode<Comparable>* &k3)
{
    singleLeftRotation(k3->right);
    singleRightRotation(k3);
}

template <class Comparable>
void AVL<Comparable>::remove(const Comparable x)
{
    remove(x, BinaryTree<Comparable>::tree_root);
}
template <class Comparable>
void AVL<Comparable>::remove(const Comparable &x, BinaryNode<Comparable>* &root)
{
    if(root == NULL)
        return;
    if(x < root->element)
        remove(x, root->left);
    else if(x > root->element)
        remove(x, root->right);
    else if (root->left != NULL && root->right != NULL)
    {
        root->element = BST<Comparable>::findMin(root->right)->element;
        remove(root->element, root->right);
    }
    else
    {
        BinaryNode<Comparable>* oldNode = root;
        root = (root->left != NULL) ? root->left : root->right;
        delete oldNode;
    }
    balance(root);
}
template <class Comparable>
AVL<Comparable>::~AVL() {}
