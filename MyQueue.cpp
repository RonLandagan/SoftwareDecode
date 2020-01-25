// Ron Landagan CS310
// 10/11/2019

#include "stdafx.h"
#include "MyQueue.h"
#include <vector>
#include <iostream>
using namespace std;

MyQueue::MyQueue()
{
	vector<int> _myList;
}

MyQueue::~MyQueue()
{
}

bool MyQueue::isEmpty()
{
	return _myList.empty();
}

/**
* Enqueues an int value into the back of the MyQueue
*
* @param int value to be enqueued
*/
void MyQueue::loadValue(int val)
{
	_myList.push_back(val);
}

/**
* Dequeues the int value in the front of the MyQueue and returns it
*
* @return int value found at the front of the MyQueue
*/
int MyQueue::nextValue()
{
	if (_myList.empty() == true)
		return -1;
	int val = _myList[0];
	_myList.erase(_myList.begin());
	return val;
}

/**
* Subtracts the value of the first item in the MyQueue from each value of the 
* MyQueue
*/
void MyQueue::normalize()
{
	int val = _myList[0];
	for (int i = 0; i < _myList.size(); i++)
	{
		_myList[i] -= val;
	}
}

/**
* Returns an array containing a number of values from the front of the MyQueue
* determined by the passed-in value.
*
* @param number of values to be passed into array
* @return array containing the first n values of MyQueue
*/
int* MyQueue::peek(int num)
{
	int* arr = new int[num];

	for (int i = 0; i < num; i++)
	{
		arr[i] = _myList[i];
	}
	return arr;
}

/**
* Returns the quantity of members in this MyQueue.
*
* @return size of array
*/
int MyQueue::size()
{
	return _myList.size();
}