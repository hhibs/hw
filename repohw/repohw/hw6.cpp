#include <iostream>
#include <fstream>
#include <vector>

#include "userdata.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: hw6.exe <filename containing userdata>" << endl;
		return -1;
	}

	ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		cout << "Error in opening the file. Please check file exists and file name is correct." << endl;
		return -1;
	}

	vector<UserData*> usersInfo;
        
        string line;
        while(getline(inFile, line))
        {
            int lineL = line.length();
            if (line[lineL - 1] == '\r' || line[lineL - 1] == '\n') lineL--;
            vector<string> values;
            string word = "";
            for (int i = 0; i < lineL; i++)
            {
                if (line[i] == ';')
                {
                    values.push_back(word);
                    word = "";
                }
                else word += line[i];
            }
            values.push_back(word);
            
            UserData* ud = new UserData(values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
            usersInfo.push_back(ud);
        }
        
	inFile.close();

        vector<UserData*> sortFName;
        vector<UserData*> sortLName;
        vector<UserData*> sortZip;
        
        cout << "User Info read from file: " << endl;
        for (int i = 0; i < usersInfo.size(); i++)
        {
            UserData *temp = usersInfo[i];
            cout << *temp << endl;
            sortFName.push_back(usersInfo[i]);
            sortLName.push_back(usersInfo[i]);
            sortZip.push_back(usersInfo[i]);
        }

        // sort on first name
        for (int i = 0; i < sortFName.size() - 1; i++)
        {
            int minIdx = i;
            for (int j = i+1; j < sortFName.size(); j++)
            {
                if (sortFName[j]->compareFirstName(*(sortFName[minIdx])) < 0)
                {
                    minIdx = j;
                }
            }
            
            // swap.
            UserData* temp = sortFName[minIdx];
            sortFName[minIdx] = sortFName[i];
            sortFName[i] = temp;
        }
        
        cout << "Sorted on FirstName: " << endl;
        ofstream fnF("sortedFirstNames.txt");
        for (int i = 0; i < sortFName.size(); i++)
        {
            cout << *(sortFName[i]) << endl;
            fnF << *(sortFName[i]) << endl;
        }
        fnF.close();

       
        // sort on last name
        for (int i = 0; i < sortLName.size() - 1; i++)
        {
            int minIdx = i;
            for (int j = i+1; j < sortLName.size(); j++)
            {
                if (sortLName[j]->compareLastName(*(sortLName[minIdx])) < 0)
                {
                    minIdx = j;
                }
            }
            
            // swap.
            UserData* temp = sortLName[minIdx];
            sortLName[minIdx] = sortLName[i];
            sortLName[i] = temp;
        }
        cout << "Sorted on LastName: " << endl;
        ofstream lnF("sortedLastNames.txt");
        for (int i = 0; i < sortLName.size(); i++)
        {
            cout << *(sortLName[i]) << endl;        
            lnF << *(sortLName[i]) << endl;
        }
        lnF.close();
      
        // sort on zip
        for (int i = 0; i < sortZip.size() - 1; i++)
        {
            int minIdx = i;
            for (int j = i+1; j < sortZip.size(); j++)
            {
                if (sortZip[j]->compareZip(*(sortZip[minIdx])) < 0)
                {
                    minIdx = j;
                }
            }
            
            // swap.
            UserData* temp = sortZip[minIdx];
            sortZip[minIdx] = sortZip[i];
            sortZip[i] = temp;
        }
        cout << "Sorted on Zip: " << endl;
        ofstream zipF("sortedZips.txt");
        for (int i = 0; i < sortZip.size(); i++)
        {
            cout << *(sortZip[i]) << endl;
            zipF << *(sortZip[i]) << endl;
        }
        zipF.close();
        
        cout << "Original is still:: " << endl;
        for (int i = 0; i < usersInfo.size(); i++)
        {
            UserData *temp = usersInfo[i];
            cout << *temp << endl;
            delete temp;
        }

	return 0;
}
