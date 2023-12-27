#include "BinaryTree.h"
#include <queue>


template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<double>;
template class BinaryTree<char>;
template class BinaryTree<string>;
template class BinaryTree<short>;
template class BinaryTree<long>;


template <class Comparable>
BinaryNode<Comparable>* deepCopy(BinaryNode<Comparable>* root);


template <class Comparable>
BinaryTree<Comparable>::BinaryTree()
{
    tree_root = NULL;
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree(BinaryNode<Comparable>* root)
{
    if(root != NULL)
        //create a copy of the given tree into the current tree
        tree_root = copyTree(root);
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree(const BinaryTree& t)
{
    tree_root = copyTree(t.tree_root);
}

template <class Comparable>
//Create copies of the tree from a given node
//All the copies are made recursively
BinaryNode<Comparable>* BinaryTree<Comparable>::copyTree(BinaryNode<Comparable>* root)
{
    if(root == NULL)
        return NULL; //return NULL if the current Node is NULL
    BinaryNode<Comparable>* node = new BinaryNode<Comparable>;
    //populating the Node
    node->element = root->element;
    node->priority = root->priority;
    node->left = copyTree(root->left);
    node->right = copyTree(root->right);
    return node; //return the current Node
}
template <class Comparable>
//A variable is given that is inserted at level order in the tree
void BinaryTree<Comparable>::insert(const Comparable x)
{
    if(tree_root == NULL)
    {
        tree_root = create_node(x);
        return;
    }

    queue<BinaryNode<Comparable>*> q; //A queue of BinaryNode type from the C++ STL
    q.push(tree_root); //push the root of the tree into the queue
    while(!q.empty())  //iterates through the queue until it is emmpty
    {
        BinaryNode<Comparable>* temp = q.front(); //save the front of the queue into a temp
        q.pop(); //remove the front of the queue

        if(temp->left != NULL)  //checks whether the left of the Node is NULL or Not
        {
            q.push(temp->left); //if it is Not NULL, then the left of the Node is pushed onto queue
        }
        else
        {
            temp->left = create_node(x); //if the left of the Node is NULL, a new Node is created with x passed as parameter
            return;
        }
        if(temp->right != NULL)  //Similar to the left of Node
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = create_node(x);
            return;
        }
    }
}
template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::create_node(Comparable data)
{
    BinaryNode<Comparable>* node = new BinaryNode<Comparable>;
    if(!node)
    {
        //if the Node is failed to create then it returns with an error message
        cout << "Memmory Allocation Failed" << endl;
        return NULL;
    }
    //populate the Node with given data
    node->element = data;
    node->priority = 0;
    node->left = node->right = NULL; //sets the left and right children of Node NULL
    return node;
}

template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::create_node(Comparable data, int priority)
{
    BinaryNode<Comparable>* node = new BinaryNode<Comparable>;
    if(!node)
    {
        //if the Node is failed to create then it returns with an error message
        cout << "Memmory Allocation Failed" << endl;
        return NULL;
    }
    //populate the Node with given data
    node->element = data;
    node->priority = priority;
    node->left = node->right = NULL; //sets the left and right children of Node NULL
    return node;
}

template <class Comparable>
Comparable BinaryTree<Comparable>::root()
{
    return tree_root->element; //returns the value at the root of the Tree
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>::left()
{
    BinaryTree<Comparable> leftTree(tree_root->left); //creates a copy of the left part of the tree and returns the left tree
    return leftTree;
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>::right()
{
    BinaryTree<Comparable> rightTree(tree_root->right); //creates a copy of right part of the tree and returns the right of the tree
    return rightTree;
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder()  //public method to traverse Inorder
{
    traverse_inOrder(tree_root); //this public method calls a private method with tree_root passed as a parameter
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder(BinaryNode<Comparable>* root)  //private method to traverse_inOrder
{
    if(root == NULL)
        return;
    traverse_inOrder(root->left); //recursively calls the left of the Node
    cout << " " << root->element << " Priority: " << root->priority << endl; //prints out the data at the Node
    traverse_inOrder(root->right); //recursively calls the right of the Node
}
template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder()  //public method to traverse_preOrder
{
    traverse_preOrder(tree_root); //calls a private method with tree_root passed as a parameter
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder(BinaryNode<Comparable>* root)  //private method to traverse_preOrder
{
    if(root == NULL)
        return;
    cout << " " << root->element; //explores the Root first then calls left and right Nodes
    traverse_preOrder(root->left);
    traverse_preOrder(root->right);
}
template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder()  //public method to explore postOrder
{
    traverse_postOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder(BinaryNode<Comparable>* root)
{
    if(root == NULL)
        return;
    traverse_postOrder(root->left); //explores the left and right Nodes first, then prints out the value at the Node
    traverse_postOrder(root->right);
    cout << " " << root->element;
}

template  <class Comparable>
void BinaryTree<Comparable>::make_empty()  //clears out the tree
{
    deleteTree(tree_root); //deleteTree method delete the tree
}

template <class Comparable>
bool BinaryTree<Comparable>::empty() const
{
    return tree_root != NULL; //returns whether the tree is empty or not
}

//Destructor
template <class Comparable>
BinaryTree<Comparable>::~BinaryTree()
{
    deleteTree(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::deleteTree(BinaryNode<Comparable>* root)  //deletes the tree in a postOrder method
{
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}




