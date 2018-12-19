#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> numbers;

void printNumbers()
{
    cout << "( ";
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i != 0) cout << ", ";
        cout << numbers[i];
    }
    cout << " )";
}

void bubbleSortNumbers()
{
    int n = numbers.size();
    int pass = 1;
    do
    {
        cout << endl << "Pass: " << pass << endl;
        int newn = 0;
        for (int i = 1; i <= n-1; i++)
        {
            if (numbers[i-1] > numbers[i])
            {
                printNumbers();
                cout << " -> ";        

                // swapNumbers
                int tempN = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = tempN;
                
                newn = i;

                printNumbers();
                cout << endl;
            }
        }
        pass++;
        n = newn;
    } while (n > 1);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: hw3.exe <filename containing integers for bubble sort>" << endl;
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

	cout << endl << "Numbers from the file have been read." << endl;
        
        // print the numbers (only for debugging purposes).
        cout << endl << "The numbers (from file) as is are: ";
        printNumbers();
        cout << endl;

	bubbleSortNumbers();
        
        // print the numbers (only for debugging purposes).
        cout << endl << endl << "The numbers (from file) after sorting are: ";
        printNumbers();
        cout << endl;
	return 0;
}
