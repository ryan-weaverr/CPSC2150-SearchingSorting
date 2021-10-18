/*
 * Name: Christopher Weaver
 * Date Submitted: 9/29/2021
 * Lab Section: 05
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once
#include <vector>
#include <time.h>

using namespace std;

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) 
{
	int size = lst.size();
	
	if (size == 1) return lst;
	//first half
	//calls mergeSort until broken down vector into size 1
	int halfSize = size / 2;
	vector<T> half1;
	for (int i = 0; i < halfSize; i++)
	{
		half1.push_back(lst[i]);
	}
	vector<T> half2;
	for (int i = halfSize; i < size; i++) 
	{
		half2.push_back(lst[i]);
	}
	half1 = mergeSort(half1);
	half2 = mergeSort(half2);

	//second half
	//compares two vectors, puts smaller in result vector and delete from respected vector
	//if size of one is zero, pushes rest of other vector to result vector
	vector <T> results;

	while(half1.size() != 0 || half2.size() != 0) {
		if (half1[0] < half2[0])
		{
			results.push_back(half1[0]);
			half1.erase(half1.begin());
		}
		else
		{
			results.push_back(half2[0]);
			half2.erase(half2.begin());
		}
		if (half1.size() == 0) 
		{
			while (half2.size() != 0) 
			{
				results.push_back(half2[0]);
				half2.erase(half2.begin());
			}
		}
		if (half2.size() == 0) 
		{
			while (half1.size() != 0) 
			{
				results.push_back(half1[0]);
				half1.erase(half1.begin());
			}
		}
	}
	return results;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
	int size = lst.size();

	//base cases to check for size 1 (only one number in vector) 
	//or size 2 (easy to swap without having to go through quicksort)
	if (size == 1) return lst;
	if (size == 2) 
	{
		if (lst[0] > lst[1]) swap(lst[0], lst[1]);
		return lst;
	}

	//get random element in vector, set pivot index and value
	srand(time(NULL));
	int pivot = rand() % size;
	int pivotIndex = 0;
	T pivotValue = lst[pivot];

	//loop through vector, swapping if vector value is less than pivot value
	swap(lst[0], lst[pivot]);
	for (int i = 1; i < size; i++) 
	{

		if (lst[i] < pivotValue)
		{
			pivotIndex++;
			swap(lst[pivotIndex], lst[i]);
		}
	}
	swap(lst[0], lst[pivotIndex]);

	//pivot index value after first sorting
	T holder = lst[pivotIndex];

	//lower part of semi sorted vector
	vector<T> lower;
	for (int i = 0; i < pivotIndex; i++)
	{
		lower.push_back(lst[i]);
	}

	//uper part of semi sorted vector
	vector<T> upper;
	for (int i = (pivotIndex + 1); i < lst.size(); i++)
	{
		upper.push_back(lst[i]);
	}

	//call quicksort for upper and lower if size != 0
	if (lower.size() != 0) {
		lower = quickSort(lower);
	}
	if (upper.size() != 0) {
		upper = quickSort(upper);
	}

	//result vector that combines sorted lower, index value, and sorted upper
	vector<T> results;
	for (int i = 0; i < lower.size(); i++) {
		results.push_back(lower[i]);
	}
	results.push_back(holder);
	for (int i = 0; i < upper.size(); i++) {
		results.push_back(upper[i]);
	}

	return results;
}



