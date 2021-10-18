/*
 * Name: Christopher Weaver
 * Date Submitted: 9/29/2021
 * Lab Section: 05
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once
#include <vector>

using namespace std;

template <class T>
int linearSearch(std::vector<T> data, T target) 
{
    //create template variable
    //loop though vector
    //if variable = target, return position
    //if no hit, return -1
	T hit;
	for (int i = 0; i < data.size(); i++)
	{
		hit = data.at(i);
        if (hit == target) return i;
	}
	return -1;
}

template <class T>
int binarySearch(std::vector<T> data, T target) 
{
    //initial data 
    int low = 0;
    int high = data.size();
    int mid = (high + low) / 2;

    //loops though vector and divides until half is equal to target
    while (low <= high) 
    {
        mid = (high + low) / 2;

        if (target > data[mid]) low = mid + 1;
        else if (target < data[mid]) high = mid - 1;
        else if (target == data[mid]) return mid;
    }
	return -1;
}