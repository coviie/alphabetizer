/*
 *  StringBST.h
 *  StringBST Class Header and Definition
 *  	   Written by : Jia Wen Goh
 *                 On : 14-03-2017
 * 
 *  StringBST - Binary Search Tree that stores strings and their frequencies.
 */

#ifndef STRINGBST_H_
#define STRINGBST_H_

#include <iostream>
#include <string>
using namespace std;

class StringBST {
private:
	/******************************** 
	 *    BSTNode Variables/Funcs   *
	 ********************************/
	// BSTNode Struct
	struct BSTNode {
        	string  value;
        	int     frequency;
        	BSTNode *left, *right;
	};

	// Pointer to the root of the StringBST
	BSTNode		*root;
	
	// Helper function to create a BSTNode
	BSTNode*	newNode(string, BSTNode*, BSTNode*);
	
	// Throws a runtime_error if an empty tree is accessed
	void		runtimeErrorCheck();
    
	/******************************** 
	 *  Recursive Helper Functions  *
	 ********************************/
	// Recursive helper function for the clear() function
	void		clear(BSTNode*);
    
	// Recursive helper function for the size() function
	int 		size(BSTNode*);
	
	// Recursive helper function for the contains() function
	bool		contains(string, BSTNode*);

	// Recursive helper function for the print() function
	void    	print(BSTNode*);
    
	// Recursive helper function for the add() function
	void		add(string, BSTNode*);
	
	// Recursive helper function for the getMin() function
	string  	getMin(BSTNode*);
	
	// Recursive helper function for the getMax() function
	string		getMax(BSTNode*);
   
	/******************************** 
	 *   Removal Helper Functions   *
	 ********************************/	
	// Removes the leaf
	bool		removeLeaf(BSTNode*);
	
	// Removes the internal node
	bool		removeInternalNode(BSTNode*);
	
	// Removes a 1-child node
	void		remove1ChildNode(BSTNode*);
	
	// Removes a 2-child node 
	void		remove2ChildNode(BSTNode*);
    
	/******************************** 
	 *     Node Helper Functions    *
	 ********************************/
	// Returns the parent node of the given node
	BSTNode*	getParent(string,BSTNode*);
	
	// Reestablishes the parent node of the given, removed node
	void		reestablishParent(BSTNode*);
	
	// Returns the node that will be removed
	BSTNode*	nodeToRemove(string,BSTNode*);
	
	// Returns the minimum node of the tree rooted at the given ndoe
	BSTNode*	getMinNode(BSTNode*);

public:
	/******************************** 
	 * Constructors and Destructors *
	 ********************************/
	// Initializes an empty binary search tree.
	StringBST();

	// Initializes a BST with an array of strings .
	StringBST(string[],int);

	// Destructor that destroys heap-allocated data.
	~StringBST();
	
	 // Makes the current binary search tree into an empty one.
	void    clear();

	/******************************** 
	 *        State Functions       *
	 ********************************/
	// Checks if the BST is empty; true if empty, false if otherwise.
	bool    isEmpty();

	// Returns the number of strings (should take duplicates into account).
	int     size();
	
	// Searches the BST - return true if query is found, false if otherwise.
	bool    contains(string);

	/******************************** 
	 *        Print Functions       *
	 ********************************/
	// Prints binary search tree in order (with their frequencies).
	void    print();

	/******************************** 
	 *         Add Functions        *
	 ********************************/
	// Adds an element into the binary tree in the correct location. 
	// If a duplicate is added, increase the frequency.
	void    add(string);

	/******************************** 
	 *        Delete Functions      *
	 ********************************/
	// Searches for the target remove one instance of it from the tree. 
	// Returns true if the target exists, false if it doesn't.
	bool    remove(string);

	/******************************** 
	 *       Min/Max Functions      *
	 ********************************/
	// Returns the left most (smallest) string in the BST.
	string  getMin();    

	// Returns the right most (largest) string in BST.
	string  getMax();

	// Removes the left most (smallest) string in BST.
	void    removeMin();

	// Removes the right most (largest) string in BST.
	void    removeMax();
};

#endif