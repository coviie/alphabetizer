/*
 *  Alphabetizer.cpp
 *  Alphabetizer Implementation
 *  	   Written by : Jia Wen Goh
 *                 On : 14-03-2017
 * 
 *  Alphabetizer - Program that orders stored input strings based on
 *  their ASCII character values.
 */

#include "Alphabetizer.h"
#include "StringBST.h"
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
using namespace std;

/*******************************
 *  Constructors & Destructors *
 *******************************/
/* [Name]:		Alphabetizer
 * [Purpose]:		Constructor; (no variables need to be initialized)
 * [Parameters]:	-
 * [Returns]:		-
 */
Alphabetizer::Alphabetizer()
{
	
}

/* [Name]:		~Alphabetizer
 * [Purpose]:		Destructor; (no variables need to be destroyed)
 * [Parameters]:	-
 * [Returns]:		-
 */
Alphabetizer::~Alphabetizer()
{
	
}

/*******************************
 *         Run Functions       *
 *******************************/
/* [Name]:		run
 * [Purpose]:		v1 run that takes in input from the command line.
 * 			If the 1st input (sort order determined) isn't "r" or
 * 			"f", throw an exception.
 * 			Prints the contents after end of input
 * [Parameters]:	-
 * [Returns]:		void
 */
void Alphabetizer::run()
{
	string sortOrder;
	cin >> sortOrder;
	if (sortOrder != "r" and sortOrder != "f")
		throw runtime_error("Invalid input");
	read(cin);
	print(sortOrder);
}

/* [Name]:		run
 * [Purpose]:		v2 run that takes in input from a file.
 * 			Prints the contents after end of file
 * [Parameters]:	1 string (filename), 1 string (sortOrder)
 * [Returns]:		void
 */
void Alphabetizer::run(string filename, string sortOrder)
{
	readFile(filename);
	print(filename, sortOrder);
}

/*******************************
 *        Read Functions       *
 *******************************/
/* [Name]:		read
 * [Purpose]:		Reads in and stores input from the given istream
 * [Parameters]:	1 istream
 * [Returns]:		void
 */
void Alphabetizer::read(istream &input)
{
	string stringInput;
	input >> stringInput;
	while (!input.eof()) {
		tree.add(stringInput);
		input >> stringInput;
	}
}

/* [Name]:		readFile
 * [Purpose]:		Reads in input from the given filename. Throws an
 * 			exception if the file is invalid/nonexistent.
 * [Parameters]:	1 string (filename)
 * [Returns]:		void
 */
void Alphabetizer::readFile(string filename)
{
	ifstream inf;
	inf.open(filename);
	if (!inf.is_open())
		throw runtime_error("Invalid file " + filename);
	
	while (!inf.eof())
		read(inf);
	
	inf.close();
}

/*******************************
 *        Print Functions      *
 *******************************/
/* [Name]:		print
 * [Purpose]:		Prints all stored inputs (if istream was cin)
 * [Parameters]:	1 string (sortOrder)
 * [Returns]:		void
 */
void Alphabetizer::print(string sortOrder)
{
	cout << "[ cin, " << sortOrder << " : ";
	if (sortOrder == "f")
		printForward();
	else
		printReverse();
	cout << "]";
}

/* [Name]:		print
 * [Purpose]:		Prints all stored inputs (if istream was an ifstream)
 * [Parameters]:	2 strings (filename and sortOrder)
 * [Returns]:		void
 */
void Alphabetizer::print(string filename, string sortOrder)
{
	cout << "[ " << filename << ", " << sortOrder << " : ";
	if (sortOrder == "f")
		printForward();
	else
		printReverse();
	cout << "]";
}

/* [Name]:		printForward
 * [Purpose]:		Prints all stored inputs by alphabetical-order
 * [Parameters]:	-
 * [Returns]:		void
 */
void Alphabetizer::printForward()
{
	while(!tree.isEmpty()) {
		cout << tree.getMin();
		if (tree.size() != 1)
			cout << ",";
		cout << " ";
		tree.removeMin();
	}
}

/* [Name]:		printReverse
 * [Purpose]:		Prints all stored inputs by reverse-alphabetical-order
 * [Parameters]:	-
 * [Returns]:		void
 */
void Alphabetizer::printReverse()
{
	while(!tree.isEmpty()) {
		cout << tree.getMax();
		if (tree.size() != 1)
			cout << ",";
		cout << " ";
		tree.removeMax();
	}
}
