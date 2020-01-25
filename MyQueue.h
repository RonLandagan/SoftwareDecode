// Ron Landagan CS310
// 10/11/2019

#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>

class MyQueue
{
private:
	std::vector<int> _myList;

public:

	MyQueue();
	~MyQueue();

	bool isEmpty();
	void loadValue(int);
	int nextValue();
	void normalize();
	int* peek(int);
	int size();
};

