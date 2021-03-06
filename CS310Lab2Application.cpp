// Ron Landagan CS310
// 10/11/2019

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "MyQueue.h"
#include "Decoder.h"

using namespace std;

string getPatternFilename(int, char**);
string getInputFilename(int, char**);
MyQueue CSVToMyQueue(string filename);
void printOutput(MyQueue);

int main(int argc, char*argv[])
{
	MyQueue patternQueue, inputQueue, outputQueue;
	string patternFilename, inputFilename;

    patternFilename = getPatternFilename(argc, argv);
    inputFilename = getInputFilename(argc, argv);
		
	patternQueue = CSVToMyQueue(patternFilename);
	inputQueue = CSVToMyQueue(inputFilename);

	outputQueue = Decoder::decode(patternQueue, inputQueue);

	printOutput(outputQueue);
    return 0;
}

/**
* Gets the filename of the pattern file.
*
* @param int of number of command-line arguments
* @param array of strings containing the command-line arguments
* @return string containing the filename
*/
string getPatternFilename(int argc, char** argv)
{
    string patternFilename = "";

    if (argc < 2)
        patternFilename = "Patterns.csv";
    else
        patternFilename = argv[1];

    return patternFilename;
}

/**
* Gets the filename of the input file.
*
* @param int of number of command-line arguments
* @param array of strings containing the command-line arguments
* @return string containing the filename
*/
string getInputFilename(int argc, char** argv)
{
    string inputFilename = "";

    if (argc < 2)
        inputFilename = "Input.csv";
    else
        inputFilename = argv[2];

    return inputFilename;
}

/**
* Opens a file according to the passed-in filename, reads each number from the
* .csv file and enqueues it into the returned MyQueue.
*
* @param filename name of .csv file to be opened
* @return MyQueue containing int values from .csv file
*/
MyQueue CSVToMyQueue(string filename)
{
	string line;
	int num;
	ifstream inputFile;
	MyQueue queue;

	inputFile.open(filename);
	if (inputFile.is_open())
	{
		while (getline(inputFile, line, ','))
		{
			num = stoi(line);
			queue.loadValue(num);
		}
		inputFile.close();
	}
	else
		cout << "Unable to open file" << endl;

	return queue;
}

/**
* Opens a file, reads each number from the passed-in MyQueue, and and prints 
* them into the opened file.
*
* @param MyQueue that holds the output codes to be written in output file
*/
void printOutput(MyQueue outputQueue)
{
	ofstream outputFile;

	outputFile.open("Output.csv");

	while (outputQueue.isEmpty() != true)
	{
		if (outputQueue.size() == 1)
			outputFile << to_string(outputQueue.nextValue());
		else
			outputFile << to_string(outputQueue.nextValue()) + ",";
	}
}