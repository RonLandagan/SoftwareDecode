// Ron Landagan CS310
// 10/11/2019

#pragma once
#include "MyQueue.h"
class Decoder
{
private:
	static int* createBinaryArray(int*, int);
	static int  compareInputAndPattern(int*, MyQueue);
	static MyQueue removeMILESWord(MyQueue, int); 
	static const int GAP_SPACING = 20;
	static const int MILES_WORD_LENGTH = 6;

public:
	Decoder();
	~Decoder();
	static MyQueue decode(MyQueue, MyQueue);
};

