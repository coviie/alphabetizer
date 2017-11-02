#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "StringBST.h"
#include "Alphabetizer.h"
using namespace std;

int main(int argc, char* argv[]) 
{
	Alphabetizer prog;
	if (argc == 3) {
		string sortOrder = argv[1];
		string filename  = argv[2];
		if (sortOrder != "r" and sortOrder != "f") { 
			cerr << "Usage:  alphabetizer [order filename]\n";
			return 1;
		}
		
		try { 
			prog.run(filename, sortOrder);
		} catch (runtime_error &r) {
			cerr << "Invalid file. Enter a valid filename.\n";
		}
	}
	
	else if (argc == 1) {
		try {
			prog.run();
		} catch (runtime_error &r) {
			cerr << "Invalid sort order. Enter 'r' or 'f'.\n";
		}
	}
	
	else {
		cerr << "Usage:  alphabetizer [order filename]\n";
		return 1;
	}
}