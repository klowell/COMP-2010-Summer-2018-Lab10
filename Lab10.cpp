/*****************************************************************************************
Project Name: Lab 10
Name: Kristopher Lowell
Date Completed: 8/9/2018
Purpose: Using a template, have the user build an array and be able to add, delete, and
search the array.  The search must be an iterative binary search.
*****************************************************************************************/

#include <iostream>
#include <chrono>
#include <string>
#include "SortedArray.h"

using namespace std;

char get_command(void);

int main(int argc, char *argv[])
{
	char cmd;
	string type, entry;
	int index;

	chrono::time_point<chrono::system_clock> start, end;
	chrono::duration<double> elapsed;

	do
	{
		cout << "Enter the type of data you are entering (string/int): ";		// Accepting input if user is going to enter strings or integers
		cin >> type;
	} while (type != "string" && type != "int");

	SortedArray<string> strArr;													// Initializing the arrays of both types
	SortedArray<int> intArr;

	do
	{
		cmd = get_command();													// Gets the command letter the user wants

		switch (cmd)
		{
		case 'A':																// Inserting data into array
			cout << "Enter the data you would like to insert: ";
			cin >> entry;

			if (type == "string")												// Inserting a string
			{
				strArr.Insert(entry);
				strArr.Print();
			}

			else if (type == "int")												// Inserting an integer
			{
				index = stoi(entry);											// Converting "string" into integer
				intArr.Insert(index);
				intArr.Print();
			}

			cout << endl;
			break;

		case 'B':																// Deleting data from array
			if ((type == "string" && !strArr.Empty()) || (type == "int" && !intArr.Empty()))	// Can't delete from an empty array
			{
				cout << "Enter the data you would like to delete: ";
				cin >> entry;

				if (type == "string")											// Deleting a string
				{
					strArr.Delete(entry);
					strArr.Print();
				}

				else if (type == "int")											// Deleting an integer
				{
					index = stoi(entry);										// Converting "string" into integer
					intArr.Delete(index);
					intArr.Print();
				}
			}
			else																// In case of an empty array, do nothing and prompt user
			{
				cout << "The array is empty." << endl;
			}

			cout << endl;
			break;

		case 'C':																// Searching for data from array
			cout << "Enter the data you would like to search for: ";
			cin >> entry;

			if (type == "string")												// Searching for string
			{
				start = chrono::system_clock::now();							// Start "timer"

				index = strArr.Search(entry);

				end = chrono::system_clock::now();								// End "timer"
			}

			if (type == "int")
			{
				index = stoi(entry);											// Converting "string" into integer

				start = chrono::system_clock::now();							// Start "timer"

				index = intArr.Search(index);

				end = chrono::system_clock::now();								// End "timer"
			}

			elapsed = end - start;												// Calculate the number of seconds to search

			if (index >= 0)
				cout << endl << "'" << entry << "' found at index " << index << "." << endl;

			cout << "It took " << elapsed.count() * 1000000 << " microseconds to search the array." << endl;

			cout << endl;
			break;

		default:
			break;
		}
	} while (cmd != 'D');

	return 0;
}

char get_command(void)
{
	char cmd;

	cout << "A - Add Data" << endl << "B - Delete Data" << endl << "C - Search Data" << endl << "D - Exit" << endl;
	cout << endl << "Enter a command: ";

	do
	{
		cin >> cmd;
		cin.ignore(INT_MAX, '\n');
		cmd = toupper(cmd);
	} while (cmd != 'A' && cmd != 'B' && cmd != 'C' && cmd != 'D');

	return cmd;
}