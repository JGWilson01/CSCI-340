#ifndef PROG7BST_H
#define PROG7BST_H
/************************************************************************
    CSCI 340 section 1
    TA: Daniel Baker
    James Wilson
    z1739305
    Assignment: 7
    Date Due: 11/2/17

    Description: Implementing a binary search tree and its functions
*************************************************************************/
#include "binTree.h"

template <class T>
class binSTree : public binTree <T>
   {
   public:
   void insert(const T& x); // inserts node with value x
   void remove(const T& x); // removes node with value x

   private:
   void insert(Node <T>*&, const T&); // private version of insert
   void remove(Node <T>*&, const T&); // private version of remove
   Node <T>* pred(Node <T>*); // returns predecessor of node
   };

/************************************************
    FUNCTION: void insert(Node <T>*&, const T&)
    ARGUMENTS: Node template pointer/reference, constant template reference
    RETURNS: nothing
    NOTES: Inserts nodes into the binary search tree, makes sure they're
           in correct placement
************************************************/
template <class T>
void binSTree<T>::insert(const T& x)
   {
   insert(this->root, x); //recursive function
   }

template <class T>
void binSTree<T>::insert(Node <T>*& ptr, const T& ref)
   {
   if(ptr == NULL)
      {
      ptr = new Node<T>(ref); //start a new tree
      }
   else if(ref < ptr->data)
      {
      insert(ptr->left, ref); //start on left
      }
   else
      {
      insert(ptr->right, ref); //start on right
      }
   }

/************************************************
    FUNCTION: void remove(Node <T>*&, const T&)
    ARGUMENTS: Template node pointer and reference, const template reference
    RETURNS: nothing
    NOTES: Removes a node in the binary search tree, making sure to
           correctly remove it and find the predecessor if necessary
************************************************/
template <class T>
void binSTree<T>::remove(const T& x)
   {
   remove(this->root, x); //recursive call
   }

template <class T>
void binSTree<T>::remove(Node <T>*& ptr, const T& ref)
   {
   if(ptr != NULL) //got this from piazza lol
      {
      if(ref < ptr->data)
         {
         remove(ptr->left, ref); //start on left
         }
      else if(ref > ptr->data)
         {
         remove(ptr->right, ref); //start on right
         }
      else
         {
         int data;
         Node<T> * tempptr = ptr; //temp storage
         if(ptr->left == NULL)
            {
            ptr = ptr->right; //if no left child, check the right
            delete tempptr; //remove temp
            }
         else if(ptr->right == NULL)
            {
            ptr = ptr->left; //if no right child, check the left
            delete tempptr; //remove temp
            }
         else
            {
            pred(ptr->left); //find the predecessor
            ptr->data = data; //point to new node
            remove(ptr->left, data); //delete old node
            }
         }
      }
   }

/************************************************
    FUNCTION: pred(Node <T>*)
    ARGUMENTS: Node template pointer
    RETURNS: predecessor node
    NOTES: finds the predecessor of the deleted node
************************************************/
template <class T>
Node<T>* binSTree<T>::pred(Node <T>* ptr)
   {
   while(ptr->right != NULL) //finding predecessor
      {
      ptr = ptr->right; //point new node to the right
      }
   return ptr; //return the new node
   }
#endif
