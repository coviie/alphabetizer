/*
 *  StringBST.cpp
 *  StringBST Implementation
 *  	   Written by : Jia Wen Goh
 *                 On : 14-03-2017
 * 
 *  StringBST - Binary Search Tree that stores strings and their frequencies.
 */

#include "StringBST.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

/*******************************
 *  Constructors & Destructors *
 *******************************/
/* [Name]:		StringBST
 * [Purpose]:		Constructor; Initializes an empty tree
 * [Parameters]:	-
 * [Returns]:		-
 */
StringBST::StringBST()
{
	root = NULL;
}

/* [Name]:		StringBST
 * [Purpose]:		Constructor; Initializes a tree that contains the given
 * 			string array
 * [Parameters]:	-
 * [Returns]:		-
 */
StringBST::StringBST(string stringArray[], int arraySize)
{
	root = NULL;
	for (int i = 0; i < arraySize; i++)
		add(stringArray[i]);
}

/* [Name]:		~StringBST
 * [Purpose]:		Destructor; Deletes heap-allocated data (delete
 * 			all the nodes in the tree)
 * [Parameters]:	-
 * [Returns]:		-
 */
StringBST::~StringBST()
{
	clear();
}

/* [Name]:		newNode
 * [Purpose]:		Creates a node with the given string, and initializes
 * 			the L/R children with the given pointers
 * [Parameters]:	1 string (input), 2 BSTNode* (left and right pointers)
 * [Returns]:		BSTNode* (pointer to the new node)
 */
StringBST::BSTNode* StringBST::newNode(string input, BSTNode *left, 
                                       BSTNode *right)
{
	BSTNode *newNode    	= new BSTNode;
	newNode->value		= input;
	newNode->frequency	= 1;
	newNode->left		= left;
	newNode->right		= right;

	return newNode;
}

/*******************************
 *       State Functions       *
 *******************************/
/* [Name]:		isEmpty
 * [Purpose]:		Checks if the BST is empty
 * [Parameters]:	-
 * [Returns]:		bool (true if it's empty, false if not)
 */
bool StringBST::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

/* [Name]:		size
 * [Purpose]:		Returns the size of the tree
 * [Parameters]:	-
 * [Returns]:		int (number of nodes in the tree)
 */
int StringBST::size()
{
	if (isEmpty())
		return 0;
	else
		return size(root);
}

/* [Name]:		size (recursive helper function)
 * [Purpose]:		Recursively finds the size of the tree
 * [Parameters]:	BSTNode* (pointer to a node)
 * [Returns]:		int (number of nodes in the tree)
 */
int StringBST::size(BSTNode *node)
{
	int timesAppeared = 0;
	
	if (node != NULL) 
		timesAppeared += node->frequency;

	if (node->left != NULL)
		timesAppeared += size(node->left);
		
	if (node->right != NULL)
		timesAppeared += size(node->right);

	return timesAppeared;
}

/* [Name]:		contains
 * [Purpose]:		Determines if the given string input is in the tree
 * [Parameters]:	-
 * [Returns]:		bool (true if found, false if not)
 */
bool StringBST::contains(string target)
{
	return contains(target, root);
}

/* [Name]:		contains (recursive helper function)
 * [Purpose]:		Recursively determines if the given string is in 
 * 			the tree
 * [Parameters]:	1 string (input to search), 1 BSTNode* (node
 * 			that will be searched)
 * [Returns]:		bool (true if found, false if not)
 */
bool StringBST::contains(string target, BSTNode* node)
{
	if (node == NULL)
		return false;
	if (target == node->value)
		return true;
	if (target < node->value)
		return contains(target, node->left);
	else
		return contains(target, node->right);
}

/*******************************
 *       Print Functions       *
 *******************************/
/* [Name]:		print
 * [Purpose]:		Prints binary search tree in order (with their
 * 			frequencies)
 * [Parameters]:	-
 * [Returns]:		void
 */
void StringBST::print()
{
	print(root);
}

/* [Name]:		print (recursive helper function)
 * [Purpose]:		Recursively prints binary search tree in order (with
 * 			their frequencies)
 * [Parameters]:	-
 * [Returns]:		void
 */
void StringBST::print(BSTNode *node)
{
	cout << "[";
	
	if (node != NULL) {
		print(node->left);
		cout << " " << node->value << " " << node->frequency << " ";
		print(node->right);
	}
	
	cout << "]";
}

/*******************************
 *         Add Functions       *
 *******************************/
/* [Name]:		add
 * [Purpose]:		Adds an element into the binary tree in the correct
 * 			location. If a duplicate is added, increase the
 * 			frequency.
 * [Parameters]:	1 string (input)
 * [Returns]:		void
 */
void StringBST::add(string input)
{
	if (root == NULL)
		root = newNode(input, NULL, NULL);
	else
		add(input, root);
}

/* [Name]:		add (recursive helper function)
 * [Purpose]:		Recursively adds an element into the binary tree in the
 * 			correct location. If input is < than node's value, 
 * 			continue searching down the left subtree to find 
 * 			the correct spot, else go down the right subtree.
 * [Parameters]:	1 string (input), 1 BSTNode* (next node to process
 * 			if the input isn't added to the current node)
 * [Returns]:		void
 */
void StringBST::add(string input, BSTNode *node)
{
	// String is the same
	if (input == node->value)
		(node->frequency)++;
        
	else if (input < node->value) {
		if (node->left == NULL)
			node->left = newNode(input, NULL, NULL);
		else 
			add(input, node->left);
	}
	
	else if (input > node->value) {
		if (node->right == NULL)
			node->right = newNode(input, NULL, NULL);
		else
			add(input, node->right);
	}
}

/*******************************
 *       Delete Functions      *
 *******************************/
/* [Name]:		clear
 * [Purpose]:		Clears all nodes from the tree
 * [Parameters]:	-
 * [Returns]:		void
 */
void StringBST::clear()
{
	clear(root);
}

/* [Name]:		clear (recursive helper function)
 * [Purpose]:		Recursively clears all nodes from the tree
 * [Parameters]:	1 BSTNode* (the root of the tree)
 * [Returns]:		void
 */
void StringBST::clear(BSTNode *node)
{
	if (node != NULL and node->left != NULL) 
		clear(node->left);

	if (node != NULL and node->right != NULL)
		clear(node->right);
	
	if (node != NULL)
		delete node;
	
	root = NULL;
}

/* [Name]:		remove
 * [Purpose]:		Recursively removes an instance of the given string 
 * 			input from the tree. There are 2 cases:
 * 			1. Removed node is a leaf -> call removeLeaf
 * 			2. Removed node is an internal node -> call 
 * 			   removeInternalNode, which checks if it has 1 or 2
 * 			   children.
 * [Parameters]:	1 string (the string to remove)
 * [Returns]:		bool (true if removal is successful, false if not)
 */
bool StringBST::remove(string target)
{
	if (contains(target) == false)
		return false;
	else {
		BSTNode *removedNode = nodeToRemove(target, root);
		
		// if there is only 1 instance of the string
		if (removedNode->frequency == 1) {
			// if removedNode is a leaf
			if (removedNode->left == NULL and 
			    removedNode->right == NULL)
				return removeLeaf(removedNode);

			//if removedNode has 2 children
			else
				return removeInternalNode(removedNode);

		}
		
		// if there are multiple instances
		else {
			(removedNode->frequency)--;
			return true;
		}
	}
}

/* [Name]:		removeLeaf
 * [Purpose]:		Removes a leaf. Does:
 * 			1. If the removedNode is the root (i.e. 1-element 
 * 			   tree), set root to NULL and delete the root.
 * 			2. Else, changes the L or R pointer of the parentNode
 * [Parameters]:	1 BSTNode* (node removed)
 * [Returns]:		bool (true, since function is called only if string
 * 			input exists in the tree)
 */
bool StringBST::removeLeaf(BSTNode* removedNode) 
{
	if (removedNode == root) {
		root = NULL;
		delete removedNode;
	}
	
	else {
		BSTNode *parentNode  = getParent(removedNode->value, root);
		
		if (removedNode->value > parentNode->value)
			parentNode->right = NULL;
		else
			parentNode->left = NULL;
			
		delete removedNode;
	}
	
	return true;
}

/* [Name]:		removeInternalNode
 * [Purpose]:		Removes an internal node, doing different functions if
 * 			1. Internal node has 2 children
 * 			2. Internal node has 1 child
 * [Parameters]:	1 BSTNode* (node removed)
 * [Returns]:		bool (true, since function is called only if string
 * 			input exists in the tree)
 */
bool StringBST::removeInternalNode(BSTNode *removedNode)
{
	if (removedNode->left != NULL and removedNode->right != NULL) 
		remove2ChildNode(removedNode);
	else 	
		remove1ChildNode(removedNode);
	
	return true;
}

/* [Name]:		remove1ChildNode
 * [Purpose]:		Removes a 1-child node. Does:
 * 			1. If the removedNode is the root, set the L/R 
 * 			   (whichever exists) node as the root, and delete
 * 			   the node.
 * 			2. Else, point the parent's L/R pointer to the
 * 			   node's child, and delete the removedNode
 * [Parameters]:	1 BSTNode* (node removed)
 * [Returns]:		void
 */
void StringBST::remove1ChildNode(BSTNode *removedNode)
{
	if (removedNode == root) {
		BSTNode *temp = root;
		if (removedNode->right != NULL)
			root = removedNode->right;
		else
			root = removedNode->left;
		delete temp;
	}
	
	else {
		reestablishParent(removedNode);
		delete removedNode;
	}
	
}

/* [Name]:		remove2ChildNode
 * [Purpose]:		Removes a 2-child node. Does:
 * 			1. Replaces the data in removedNode with the smallest
 * 			   node in the right subtree (replacedNode).
 * 			2. Removes replacedNode (checks if it's a 1 or
 * 			   2 child subtree).
 * [Parameters]:	1 BSTNode* (node removed)
 * [Returns]:		void
 */
void StringBST::remove2ChildNode(BSTNode *removedNode)
{
	BSTNode *replacedNode = getMinNode(removedNode->right);

	string	tempVal = replacedNode->value;
	int	tempFreq = replacedNode->frequency;
	
	// if replacedNode is a leaf
	if (replacedNode->left == NULL and replacedNode->right == NULL)
		removeLeaf(replacedNode);

	//if replacedNode has 1 child
	else
		remove1ChildNode(replacedNode);
	
	removedNode->value = tempVal;
	removedNode->frequency = tempFreq;
}

/* [Name]:		getParent
 * [Purpose]:		Returns the parentNode of the given node
 * [Parameters]:	1 string (string of the given node), 1 BSTNode*
 * [Returns]:		BSTNode* (the parent of the given node)
 */
StringBST::BSTNode* StringBST::getParent(string target, BSTNode *node) 
{
	// Check if parent is root
	if (target == node->value)
		return NULL;
		
	// All other cases
	if ((node->right != NULL and target == node->right->value) or
	    (node->left != NULL and target == node->left->value))
		return node;
	else if (target < node->value)
		return getParent(target, node->left);
	else
		return getParent(target, node->right);
}

/* [Name]:		reestablishParent
 * [Purpose]:		Re-establishes the parent node of the removed node 
 * 			(given that the removed node only has 1 child)
 * [Parameters]:	1 BSTNode* (node that will be removed)
 * [Returns]:		void
 */
void StringBST::reestablishParent(BSTNode *removedNode) 
{
	BSTNode *parentNode = getParent(removedNode->value, root);
	
	if (removedNode == parentNode->right) {
		if (removedNode->right != NULL)
			parentNode->right = removedNode->right;
	
		else 
			parentNode->right = removedNode->left;
	}
	
	else {
		if (removedNode->right != NULL) 
			parentNode->left = removedNode->right;
	
		else 
			parentNode->left = removedNode->left;
	}
}

/* [Name]:		nodeToRemove
 * [Purpose]:		Gets the node that will be removed
 * [Parameters]:	1 string (string of the given node), 1 BSTNode*
 * [Returns]:		BSTNode* (the node that will be removed)
 */
StringBST::BSTNode* StringBST::nodeToRemove(string target, BSTNode *node)
{
	if (target == node->value)
		return node;
	else if (target < node->value)
		return nodeToRemove(target, node->left);
	else
		return nodeToRemove(target, node->right);
}

/* [Name]:		getMinNode
 * [Purpose]:		Gets the minimum node of the (sub)tree
 * [Parameters]:	1 BSTNode* (root of subtree)
 * [Returns]:		BSTNode* (minimum node)
 */
StringBST::BSTNode* StringBST::getMinNode(BSTNode *node)
{
	if (node->left == NULL)
		return node;
	else
		return getMinNode(node->left);
}

/*******************************
 *       Min/Max Functions     *
 *******************************/
/* [Name]:		getMin
 * [Purpose]:		Returns the left-most (smallest) string in the BST
 * 			(if the tree is empty, return a runtimeError)
 * [Parameters]:	-
 * [Returns]:		string (smallest string)
 */
string StringBST::getMin()
{
	runtimeErrorCheck();
	return getMin(root);
}

/* [Name]:		getMin (recursive helper function)
 * [Purpose]:		Recursively find the left-most (smallest) string in 
 * 			the BST
 * [Parameters]:	1 BSTNode* (the next node to search in)
 * [Returns]:		string (smallest string)
 */
string StringBST::getMin(BSTNode *node)
{
	if (node->left != NULL)
		return getMin(node->left);
	else
		return node->value;
}

/* [Name]:		removeMin
 * [Purpose]:		Removes an instance of the smallest string in the BST
 * [Parameters]:	-
 * [Returns]:		void
 */
void StringBST::removeMin()
{
	remove(getMin());
}

/* [Name]:		getMax
 * [Purpose]:		Returns the right-most (largest) string in the BST
 * 			(if the tree is empty, return a runtimeError)
 * [Parameters]:	-
 * [Returns]:		string (largest string)
 */
string StringBST::getMax()
{
	runtimeErrorCheck();
	return getMax(root);
}

/* [Name]:		getMax (recursive helper function)
 * [Purpose]:		Recursively find the right-most (largest) string in 
 * 			the BST
 * [Parameters]:	1 BSTNode* (the next node to search in)
 * [Returns]:		string (largest string)
 */
string StringBST::getMax(BSTNode *node)
{
	if (node->right != NULL)
		return getMax(node->right);
	else
		return node->value;
}

/* [Name]:		removeMax
 * [Purpose]:		Removes an instance of the largest string in the BST
 * [Parameters]:	-
 * [Returns]:		void
 */
void StringBST::removeMax()
{
	remove(getMax());
}

/* [Name]:		runtimeErrorCheck
 * [Purpose]:		Throws a runtime error if an empty tree is accessed
 * [Parameters]:	-
 * [Returns]:		void
 */
void StringBST::runtimeErrorCheck()
{
	if (isEmpty())
		throw runtime_error("empty_tree");
}