/*****************************************************************************************
Project Name: Lab 10
Name: Kristopher Lowell
Date Completed: 8/9/2018
Purpose: Using a template, have the user build an array and be able to add, delete, and
search the array.  The search must be an iterative binary search.
*****************************************************************************************/

#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <vector>

using namespace std;

template <typename T>
class SortedArray
{
public:
	SortedArray() {};							// Default constructor
	~SortedArray() { elements.clear(); };		// Destructor

	void Insert(T elem);						// Mutator functions
	void Delete(T elem);

	int Search(T elem);							// Accessor functions

	T At(unsigned index) { return elements[index]; };
	bool Empty() { return elements.empty(); };

	void Print();								// Display function

private:
	vector <T> elements;
};

template <typename T>
void SortedArray<T>::Insert(T elem)
{
	int index = 0;

	if (elements.empty())									// If array is empty, just add element
		elements.push_back(elem);
	else if (elem >= elements[elements.size() - 1])			// If element is the new largest, just push it into array
		elements.push_back(elem);
	else
	{
		index = (int)elements.size() - 1;					// Since a vector is being used, expand it by one by pushing the last element
		elements.push_back(elements[index]);

		for (; index >= 0 && elements[index] > elem; index--)	// Moving all elements greater than the data to the right in the array
			elements[index + 1] = elements[index];

		elements[index + 1] = elem;							// Inserting the data into the correct element index
	}
}

template <typename T>
void SortedArray<T>::Delete(T elem)
{
	int index = Search(elem);								// Find the data if it's contained in the array

	if (index >= 0)											// index will equal -1 if it's not in array
	{
		for (unsigned i = index; i < elements.size() - 1; i++)
			elements[i] = elements[i + 1];					// Moving all the elements greater than the data to the left

		elements.pop_back();								// Since a vector is being used, contract it by one by popping the last element
	}
}

template <typename T>
int SortedArray<T>::Search(T elem)
{
	if (elements.empty())									// If array is empty, prompt user and return -1
	{
		cout << "The array is empty." << endl;
		return -1;
	}

	unsigned left = 0;										// Setting bounds for search
	unsigned right = elements.size() - 1;
	int  mid;

	while (left <= right)									// Iterative binary search
	{
		mid = (int)((left + right) / 2);

		if (elements[mid] == elem)							// If found, return index of where data is
			return mid;

		if (elements[mid] < elem)
			left = (unsigned)(++mid);
		else
			right = (unsigned)(--mid);
	}

	cout << endl << "Data not found in the array." << endl;	// If data isn't found, prompt user and return -1
	return -1;
}

template <typename T>
void SortedArray<T>::Print()
{
	cout << endl;											// Simple printing of array elements on a single line

	for (unsigned i = 0; i < elements.size(); i++)
		cout << elements[i] << " ";

	cout << endl;
}

#endif