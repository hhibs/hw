#include <iostream>
#include "BSTree.h"

using namespace std;

BSTree::BSTree() {
    treeRoot = NULL;
}

BSTree::~BSTree() {
    deleteTree(treeRoot);
}

void BSTree::deleteTree(Node* node)
{
    if (node == NULL) return;
    
    delete(node->leftChild());
    delete(node->rightChild());
    
    delete node;    
}

void BSTree::insertValue(int value)
{
    Node* newNode = new Node();
    newNode->setValue(value);
    
    if (treeRoot == NULL)
    {
        treeRoot = newNode;
        return;
    }
    
    Node* tempNode = treeRoot;
    while(tempNode != NULL)
    {
        int tValue = tempNode->value();
        if (tValue == value)
        {
            delete newNode;
            return;
        }
        else if (value < tValue)
        {
            if (tempNode->leftChild() == NULL)
            {
                tempNode->setLeftChild(newNode);
                return;
            }
            else tempNode = tempNode = tempNode->leftChild();
        }
        else
        {
            if (tempNode->rightChild() == NULL)
            {
                tempNode->setRightChild(newNode);
                return;
            }
            else tempNode = tempNode = tempNode->rightChild();
        }
    }
}

void BSTree::preOrderPrint()
{
    if (treeRoot == NULL)
    {
        cout << "There is no element in the tree yet.";
        return;
    }
    
    preOrder(treeRoot);    
}

void BSTree::preOrder(Node* node)
{
    if (node == NULL) return;
    
    cout << endl << "The element visited: " << node->value();
    preOrder(node->leftChild());
    preOrder(node->rightChild());
}
