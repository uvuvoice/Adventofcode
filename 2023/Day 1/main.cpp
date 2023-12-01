// Part 1: 54388 //
// Part 2: 53515 //
///////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int compareWord(string);

int main()
{
	vector <string> arrayOfValInLine = {};
	string c;
	string sumDigit;
	string line;

	int count = 0;	
	int temp = 0;
	int check = 0;
	int NLine = 1;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	
	fstream file("yourPathToFile/input.txt");
	if (file.is_open())
	{
		while (getline(file, line)) {
			for (int i = 0; i < line.length(); i++) {
				int temp = line[i] - '0';
				for (int j = 0; j < 9; j++) {
					if (temp == arr[j]) {
						arrayOfValInLine.push_back(to_string(line[i] - '0'));
						check = 1;
						break;
					}
				}
				if (check == 0) {
					for (int k = i; k < line.length(); k++) {
						sumDigit += line[k];
						if (compareWord(sumDigit) > 0) {
							arrayOfValInLine.push_back(to_string(compareWord(sumDigit)));
							break;
						}
					}	
					sumDigit.clear();
				}
				check = 0;
			}

			if (arrayOfValInLine.size() == 1)
				c = arrayOfValInLine[0] + arrayOfValInLine[0];
			else
				c = arrayOfValInLine[0] + arrayOfValInLine[arrayOfValInLine.size() - 1];

			count += stoi(c);			
			arrayOfValInLine.clear();
		}
	}
	cout << count << endl;
	file.close();
	return 0;
}

int compareWord(string word)
{
	int temp = 0;
	string arrOfDigits[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	for (int i = 0; i < 10; i++)
	{
		if (word == arrOfDigits[i]) {
			temp = 1;
			return i + 1;
		}
	}
	if (temp == 0)
		return 0;
}