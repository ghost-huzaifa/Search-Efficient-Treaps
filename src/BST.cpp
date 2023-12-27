#include "BST.h"


template class BST<int>;
template class BST<float>;
template class BST<double>;
template class BST<char>;
template class BST<string>;
template class BST<short>;
template class BST<long>;


template <class Comparable>
BST<Comparable> :: BST()                         //Constructors
{
}

template <class Comparable>
BST<Comparable> :: BST(BinaryNode<Comparable>* root) : BinaryTree<Comparable>(root)
{
}

template <class Comparable>
BST<Comparable> :: ~BST()                            //Destructor
{

}

template <class Comparable>
bool BST<Comparable> :: search(const Comparable data)           //Contains
{
    if (BinaryTree<Comparable>::tree_root != NULL)
    {
        BinaryNode<Comparable> *current = BinaryTree<Comparable>::tree_root;
        while (current != NULL)
        {
            if (current->element == data)
                return true;
            else if (current->element < data)
                current = current->right;
            else 
                current = current->left;
        }
    }
    return false;    
}

template <class Comparable>
void BST<Comparable> :: insert(const Comparable data)           //Compose element into a tree
{
    insert(data, BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
void BST<Comparable> :: remove(const Comparable data)           //decompose element from a tree
{
    remove(data, BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMin(){
    BinaryNode<Comparable>* min = findMin(BinaryTree<Comparable>::tree_root);
    return min;
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMax(){
    BinaryNode<Comparable>* max =  findMax(BinaryTree<Comparable>::tree_root);
    return max;
}

template <class Comparable>
void BST<Comparable> :: insert(const Comparable data, BinaryNode<Comparable>*& root)           //Compose element into a tree
{
    if (root == NULL)
    {
        root = new BinaryNode<Comparable>;
        root->element = data;
        root->priority = 0;
        root->left = root->right = NULL;
    }

    else if (data < root->element)
        insert(data, root->left);
    else if (data > root->element)
        insert(data, root->right);
    else
        return;
}

template <class Comparable>
void BST<Comparable> :: remove(const Comparable data, BinaryNode<Comparable>*& root)           //decompose element from a tree
{
    if (root == NULL)
        return;
    else if (data < root->element)
        remove(data, root->left);
    else if (data > root->element)
        remove(data, root->right);
    else if (root->left != NULL && root->right != NULL)   //Node to be deleted has 2 children
    {
        root->element = findMin(root->right) ->element;
        remove(root->element, root->right);
    }
    else                                            //Node has 1 or no children
    {
        BinaryNode<Comparable>* oldNode = root;
        if (root->left != NULL)
            root = root->left;
        else if (root->right != NULL)
            root = root->right;
        delete oldNode;
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMin(BinaryNode<Comparable>* root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMax(BinaryNode<Comparable>* root)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}


