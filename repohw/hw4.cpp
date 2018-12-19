#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> numbers;

void sortNumbers()
{
	// run a loop from first to the second last element in the vector
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		// start with this element as the minimum element.
		int minIdx = i;
		// run another loop from next element till the last element to look for smaller number.
		for (int j = i+1; j < numbers.size(); j++)
		{
			// if this number is smaller than minimum index number, make this as minimum.
			if (numbers[j] < numbers[minIdx])
			{
				minIdx = j;
			}
		}
		// we have the minimum index here for this iteration. Swap the numbers
		if (minIdx != i)
		{
			int temp = numbers[i];
			numbers[i] = numbers[minIdx];
			numbers[minIdx] = temp;
		}
	}
}

int binarySearch(int key)
{
    cout << endl << "Searching for " << key << endl;
    cout << "Total count of numbers: " << numbers.size();
	int midIdx = 0;
	int leftIdx = 0;
	int rightIdx = numbers.size();

	// run the loop to keep shifting to the remaining half
	// at each iteration if the key is not yet found
	while (leftIdx < rightIdx)
	{
		midIdx = leftIdx + (rightIdx - leftIdx) / 2;
                cout << endl << "The middle element: " << numbers[midIdx];
		// see if key is same as the midIdx element.
		if (key == numbers[midIdx])
		{
                    cout << " matched; the key found";
			return 1;
		}
		else if (key < numbers[midIdx])
		{
			// shift to the lower half
                    cout << " is greater than the key, shifting to the lower half";
			rightIdx = midIdx;
		}
		else
		{
			// key is bigger than mid, shift to the upper half
                    cout << " is less than the key, shifting to the upper half";
			leftIdx = midIdx + 1;
		}
	}
	
	// if we are here, means the key was not found.
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: hw4.exe <filename containing integers for binary search>" << endl;
		return -1;
	}

	ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		cout << "Error in opening the file. Please check file exists and file name is correct." << endl;
		return -1;
	}

	int num;
	while (inFile >> num)
	{
		numbers.push_back(num);
	}
	inFile.close();

	cout << "Numbers from the file have been read." << endl << "Please enter the number to search for >> ";
	int key;
	cin >> key;

	sortNumbers();
        
        // print the numbers (only for debugging purposes).
//        cout << endl << "The numbers (from file) in sorted order are: " << endl;
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		cout << numbers[i] << endl;
//	}

	int found = binarySearch(key);
	if (found == 1)
	{
		cout << endl << "The number exists in the file." << endl;
	}
	else cout << endl << "The number does not exist in the file." << endl;

	return 0;
}
