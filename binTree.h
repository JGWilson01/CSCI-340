#ifndef PROG6_H
#define PROG6_H
/************************************************************************
    CSCI 340 section 1
    TA: Daniel Baker
    James Wilson
    z1739305
    Assignment: 6
    Date Due: 10/24/17

    Description: Implement a binary tree class to deal with multple data
                 types
*************************************************************************/
#include <iostream>
#include <string>
#include "/home/cs340/progs/17f/p6/Node.h"
using namespace std;

template <class T> class binTree {
   public:
   binTree(); // default constructor
   unsigned height() const; // returns height of tree
   virtual void insert(const T&); // inserts a node in tree
   void inorder(void (*)(const T&)); // inorder traversal of tree

   protected:
   Node <T>* root; // root of tree

   private:
   unsigned height(Node<T>*) const; // private version of height ( )
   void insert(Node<T>*&, const T&); // private version of insert ( )
   void inorder(Node <T>*, void(*)(const T&)); // private version of inorder ( )
   };

   template <class T> void print(const T& x); //prototypes for main file
   template <class T> void print_vals(binTree<T>&, const string&);

   typedef enum {left_side, right_side} SIDE;
   SIDE rnd () {return rand () % 2 ? right_side : left_side;}
   
/************************************************
    FUNCTION: binTree()

    ARGUMENTS: none

    RETURNS: none

    NOTES: default constructor
************************************************/
   template <class T>
   binTree<T>::binTree()
      {
      root = 0; //initilizing root to 0
      }

/************************************************
    FUNCTION: unsigned height() const

    ARGUMENTS: Pointer to a template node

    RETURNS: unsigned int

    NOTES: find the height of the tree
************************************************/
   template <class T>
   unsigned binTree<T>::height() const
      {
      return height(root); //recursive call
      }

   //private version
   template <class T>
   unsigned binTree<T>::height(Node <T>* ptr) const
      {
      if(ptr == nullptr)
         {
         return 0; //if tree empty, then no tree
         }
         }
      else
         {
         int lH = height(ptr->left); //starts at the left
         int rH = height(ptr->right); //starts at the right
         if(lH > rH) //which side is longer
            {
            return (lH + 1); //if left is longer
            }
         else
            {
            return (rH + 1); //if right is longer
            }
         }
      }

/************************************************
    FUNCTION: void insert(Node <T>* &, const T&)

    ARGUMENTS: Pointer to a node ref, const Template ref

    RETURNS: none

    NOTES: Inserts new nodes into binary tree
************************************************/
   template <class T>
   void binTree<T>::insert(const T& x)
      {
      insert(root, x); //recursive call
      }

   //private version
   template <class T>
   void binTree<T>::insert(Node <T>* &ptr, const T& x)
      {
      if(ptr == nullptr)
         {
         ptr = new Node<T>(x); //start a new node if empty
         }
      else
         {
         SIDE a = rnd(); //fill the node with random stuff
         if(a == left_side)
            {
            insert(ptr->left, x); //start on left if == left
            }
         else
            {
            insert(ptr->right, x); //start on right if != right
            }
         }
      }

/************************************************
    FUNCTION: void inOrder(void (*)(const T&))

    ARGUMENTS: Node pointer, function print to print nodes

    RETURNS: none

    NOTES: Prints out the data of the nodes in inorder sequence
************************************************/
   template <class T>
   void binTree<T>::inorder(void (*print)(const T&))
      {
      inorder(root, print); //recursive call
      }

   //private version
   template <class T>
   void binTree<T>::inorder(Node <T>* a, void (*print)(const T&))
      {
      if(a != nullptr)
         {
         inorder(a->left, print); //starts on the left hand side of the tree
         print(a->data); //prints out the conents of the node
         inorder(a->right, print); //moves to the right hand side
         }
      }
#endif
