// Ron Landagan CS310
// 10/11/2019

#include "stdafx.h"
#include "Decoder.h"

#include<iostream>
using namespace std;

Decoder::Decoder()
{
}


Decoder::~Decoder()
{
}

/**
* Returns a MyQueue of MILES codes found from the passed-in MyQueue input and pattern.
* The specifics of the patterns is determined from the passed-in gapSpacing and milesWordLength
*
* @param patterns of MILES codes to be matched up with
* @param input of values to be analyzed
* @return MyQueue containing MILES codes found in the input
*/
MyQueue Decoder::decode(MyQueue patterns, MyQueue input)
{
	MyQueue output;
	int patternArr[11] = {}, inputSize = MILES_WORD_LENGTH + 1;
	
	while (input.size() >= MILES_WORD_LENGTH)
	{
		input.normalize();

		//Create Binary Array to compare with Pattern
		if (input.size() == MILES_WORD_LENGTH)
			inputSize = MILES_WORD_LENGTH;
		int* inputToLookAt = input.peek(inputSize);
		int* inputBinaryArr = createBinaryArray(inputToLookAt, GAP_SPACING);

		//Compare Binary Array with Pattern
		int code = compareInputAndPattern(inputBinaryArr, patterns);
		if(code != -1)
		{
			output.loadValue(code);
			input = removeMILESWord(input, GAP_SPACING);
		}
		else
			input.nextValue();
	}
	return output;
}

/**
* 
* Searches the passed-in array for values to be found from the passed-in gap spacing
* and returns them as an array of binary values 
*
* @param array of input values
* @param value of the gap between
* @return array of binary values found in input array according to gap spacing.
*/
int* Decoder::createBinaryArray(int* input, int gapSpacing)
{
	int* binaryArr = new int[11]();

	for (int targetGap = 0, i = 0; targetGap <= gapSpacing*10; targetGap += gapSpacing, i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (targetGap == input[j])
				binaryArr[i] = 1;
		}
	}
	return binaryArr;
}

/**
* Compares the array of binary values to the patterns of MILES codes and returns 
* the corresponding MILES code.
*
* @param array of binary values to compare
* @return appropriate MILES code, -1 if there is no match
*/
int Decoder::compareInputAndPattern(int* input, MyQueue patterns)
{
	int code = -1;
	int* binaryPattern = new int[patterns.size()];
	binaryPattern = patterns.peek(patterns.size());
	bool matchingCode;

	for (int row = 0; row < patterns.size() / 12; row++)
	{
		matchingCode = true;
		for (int col = 0; col < 11; col++)
		{
			if (input[col] != binaryPattern[(row * 12) + col])
				matchingCode = false;
		}

		if (matchingCode)
			code = binaryPattern[(row * 12) + 11];
	}
	return code;
}

/**
* Removes a full MILES word from the front of passed-in MyQueue.
*
* @param Current state of MyQueue input
* @param int value of gap spacing
* @return MyQueue containing input without MILES word in front
*/
MyQueue Decoder::removeMILESWord(MyQueue input, int gapSpacing)
{
	int peeked;
	do{
		input.nextValue();
		if(input.size() > 0)
			peeked = input.peek(1)[0];
	} while (peeked < gapSpacing * 10 && !input.isEmpty());
	input.nextValue();
	return input;
}
