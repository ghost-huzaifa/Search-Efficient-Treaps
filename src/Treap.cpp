#include "Treap.h"                  // Included Libraries / Header Files
#include <string>
#include <sstream>
#include <fstream>
#include <type_traits>

template class Treap<int>;          //Template classes of Treap
template class Treap<float>;
template class Treap<double>;
template class Treap<char>;
template class Treap<std::string>;
template class Treap<short>;
template class Treap<long>;
template <class Comparable>
Comparable convertFromString(const std::string& str);


/*************************************************** PUBLIC Functions *********************************************************/

/** \brief
 * Non- parametrized constructor of Treap data structure, which calls constructor of base class BST (sets tree_root = NULL)
 * \param void
 * \return void
 *
 */
template <class Comparable>
Treap<Comparable> :: Treap() : BST<Comparable>() {}



/** \brief
 * Parametrized constructor (copy constructor) of Treap, which calls copy constructor of base class BST (makes a deep copy of given tree)
 * \param Treap to be copied
 * \return deep copied Treap
 *
 */
template <class Comparable>
Treap<Comparable> :: Treap(const Treap<Comparable> &t) : BST<Comparable>(t) {}



/** \brief
 * Public Insert function to insert key into treap, which calls private insert function
 * \param x = Key to be inserted
 * \param priority = priority of that Key in Treap
 * \return void
 *
 */
template <class Comparable>
void Treap<Comparable> :: insert(const Comparable x)
{
    insert(x, BinaryTree<Comparable> :: tree_root);
}


/** \brief
 * Public Remove function to delete key from treap, which calls private remove function
 * \param x = Key to be deleted
 * \return void
 *
 */
template <class Comparable>
void Treap<Comparable> :: remove(const Comparable x)
{
    remove(x, BinaryTree<Comparable>::tree_root);
}



/** \brief
 * Public Search function to search key from treap, which calls private search function
 * \param x = Key to be searched
 * \return void
 *
 */
template <class Comparable>
bool Treap<Comparable> :: search(const Comparable x)
{
    return search(x, BinaryTree<Comparable>::tree_root);
}



/** \brief
 * Destructor of Treap data structure, which calls destructor of base class BST (delete all nodes)
 * \param void
 * \return void
 *
 */
template <class Comparable>
Treap<Comparable> :: ~Treap() {}




/*************************************************** PRIVATE Functions *********************************************************/

/** \brief
 * Private Insert function to insert key into treap, which inserts value using BST property and maintains max. heap property for priorities
 * \param x = Key to be inserted
 * \param priority = priority of that Key in Treap
 * \param root = root of given tree (type BinaryNode)
 * \return void
 *
 */
template <class Comparable>
void Treap<Comparable> :: insert(const Comparable x, BinaryNode<Comparable>* &root)
{
    if (root == NULL)                                                       //No node exists at given root
    {
        root = new BinaryNode<Comparable>;
        root->element = x;
        root->priority = rand()%_nsePriorityLimit;
        root->left = root->right = NULL;
    }
    else if (x < root->element)                                             //Search Left sub-tree for insertion
    {
        insert(x, root->left);
        if (root->left != NULL && root->left->priority > root->priority)    //Priorities Max Heap Imbalance check
            root = singleRightRotation(root);
    }
    else if (x > root->element)                                             //Search Right sub-tree for insertion
    {
        insert(x, root->right);
        if (root->right != NULL && root->right->priority > root->priority)  //Priorities Max Heap Imbalance check
            root = singleLeftRotation(root);
    }
    else
    {                                                                       // Key already exists, increase priority by 1
        root->priority++;
    }

                                                                            // Check max heap property and perform rotation if needed
    if (root->left != NULL && root->left->priority > root->priority)
        root = singleRightRotation(root);
    else if (root->right != NULL && root->right->priority > root->priority)
        root = singleLeftRotation(root);
}



/** \brief
 * Private Remove function to remove key from treap, which deletes key using BST property and maintains max. heap property for priorities
 * \param x = Key to be deleted
 * \param root = root of given tree (type BinaryNode)
 * \return void
 *
 */
template <class Comparable>
void Treap<Comparable> :: remove(const Comparable x, BinaryNode<Comparable>* &root)
{
    if(root == NULL)
        return;
    if(x < root->element)
        remove(x, root->left);
    else if(x > root->element)
        remove(x, root->right);
    else if (root->left != NULL && root->right != NULL)
    {
        bool condition = root->left->priority > root->right->priority;
        if (condition)
        {
            root->element = root->left->element;
            root->priority = root->left->priority;
            remove(root->element, root->left);
        }
        else
        {
            root->element = root->right->element;
            root->priority = root->right->priority;
            remove(root->element, root->right);
        }
    }
    else
    {
        BinaryNode<Comparable>* oldNode = root;
        root = (root->left != NULL) ? root->left : root->right;
        delete oldNode;
        cout << "Element has been deleted ! " << endl;
    }

}



/** \brief
 * Private Search function to search key from treap, which searches key using BST property
 * \param x = Key to be searched
 * \param root = root of given tree (type BinaryNode)
 * \return bool = found (1) or not found (0) in Treap
 *
 */
template <class Comparable>
bool Treap<Comparable> :: search(const Comparable x, BinaryNode<Comparable>* &root)
{
    if (root == NULL)
        return false;
    if (x < root->element)
    {
      bool result = search(x, root->left);

        if (root->left && root->left->priority > root->priority)
        {
            root = singleRightRotation(root);
        }
        else if (root->right && root->right->priority > root->priority)
        {
            root = singleLeftRotation(root);
        }
        return result;

    }
    else if (x > root->element)
    {
      bool result = search(x, root->right);

        if (root->left && root->left->priority > root->priority)
        {
            root = singleRightRotation(root);
        }
        else if (root->right && root->right->priority > root->priority)
        {
            root = singleLeftRotation(root);
        }
        return result;
    }
    else
    {
        // Key found, increase priority by 1
        /*We will have to implement some method so that when an element is searched
         * its priority must change and if it is searched for the first
         * then it must percolate above those elements who are never searched.
         * If it has been searched more than once, then it must percolate above according
         * to its search frequency.*/
        if(root->priority < _nsePriorityLimit){
          root->priority = _nsePriorityLimit;

        }
        else {
          root->priority = (int)((float)root->priority * 1.1);
        }
        // Check max heap property and perform rotation if needed
        if (root->left && root->left->priority > root->priority)
        {
            root = singleRightRotation(root);
        }
        else if (root->right && root->right->priority > root->priority)
        {
            root = singleLeftRotation(root);
        }

        return true;
    }
    return false;
}



/** \brief
 * Single Left Rotation Function which perform SLR on given node
 * \param k2 = node for SLR (type BinaryNode)
 * \return Percolated BinaryNode
 *
 */
template <class Comparable>
BinaryNode<Comparable>* Treap<Comparable> :: singleLeftRotation(BinaryNode<Comparable>* &k2)
{
    if (k2 != NULL)
    {
        BinaryNode<Comparable>* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        return k1;
    }
    return NULL;
}



/** \brief
 * Single Right Rotation Function which perform SRR on given node
 * \param k2 = node for SRR (type BinaryNode)
 * \return Percolated BinaryNode
 *
 */
template <class Comparable>
BinaryNode<Comparable>* Treap<Comparable> :: singleRightRotation(BinaryNode<Comparable>* &k2)
{
    if (k2 != NULL)
    {
        BinaryNode<Comparable>* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        return k1;
    }
    return NULL;
}



/** \brief
 * Print the key at the top of tree (root)
 * \param void
 * \return void
 *
 */
 template <class Comparable>
 void Treap<Comparable> :: printRootValue()
 {
     cout << " " << BinaryTree<Comparable> :: tree_root->element << " Priority: " << BinaryTree<Comparable> :: tree_root->priority << endl;
 }



 /** \brief
 * Read the provided .csv file and insert its content into treap
 * \param .csv file
 * \param treap for insertion
 * \return void
 *
 */
template <class Comparable>
void Treap<Comparable> :: readCSV(const std::string& filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        istringstream stringStream(line);
        string valueString;

        while (std::getline(stringStream, valueString, ','))
        {
            Comparable value = convertFromString<Comparable>(valueString);
            insert(value);
        }
    }
    cout << "Values has been inserted from file successfully ! " << endl;
    file.close();
}


/** \brief
 * Convert the string to desirable template type
 * \param string to be converted
 * \return converted comparable value
 *
 */
template <class Comparable>
Comparable convertFromString(const std::string& str)
{
    istringstream stringStream(str);
    Comparable value;
    stringStream >> value;
    return value;
}
