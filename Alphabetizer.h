/*
 *  Alphabetizer.h
 *  Alphabetizer Class Header and Definition
 *  	   Written by : Jia Wen Goh
 *                 On : 14-03-2017
 * 
 *  Alphabetizer - Program that orders stored input strings based on
 *  their ASCII character values.
 */

#ifndef ALPHABETIZER_H_
#define ALPHABETIZER_H_

#include "StringBST.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Alphabetizer {
private:
	/******************************** 
	 *    Alphabetizer Variables    *
	 ********************************/
	// StringBST object that holds the strings
	StringBST	tree;
	
	/******************************** 
	 * Alphabetizer Read Functions  *
	 ********************************/
	// Reads in contents in an input-stream (whether cin or infile) 
	void	read(istream&);
	
	// Opens a file and processes the inputs
	void	readFile(string);

	/******************************** 
	 * Alphabetizer Print Functions *
	 ********************************/
	// Print function that prints all stored inputs;
	// Determines if printForward or printReverse based on user input
	void	print(string);
	void	print(string,string);
	
	// Prints the stored input in forward-order
	void	printForward();
	
	// Prints the stored input in backward-order
	void	printReverse();
public:
	/******************************** 
	 * Constructors and Destructors *
	 ********************************/
	Alphabetizer();
	~Alphabetizer();
	
	/******************************** 
	 *         Run Functions        *
	 ********************************/
	// v1 run that takes in input from the CMD line
	void	run();
	
	// v2 run that takes in input from a file
	void	run(string,string);
	
};

#endif