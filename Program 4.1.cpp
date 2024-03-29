#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;


int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	ofstream output; //opens output file
	output.open("Output.txt");
	ifstream file; //opens input file
	file.open("file.txt");

	if (file.fail())
	{
		cout << "Input file failed to open.: " << endl;
		exit(1);
	}
	else
	{
		int limit1;
		int limit2;
		file >> limit1;
		file >> limit2;
		cout << limit1 << " " << limit2 << endl;

		string** grades = new string*[limit1];
		for (int i = 0; i < limit1; i++)
			grades[i] = new string[limit2+4];
		for (int x = 0; x < limit1; x++) // fill array with file
		{
			for (int y = 0; y < limit2+1; y++)
			{
				file >> grades[x][y];
			}
		}


		//find average and add to the end of the array
		int A = 0, B = 0, C = 0, D = 0, F = 0;
		for (int q = 0; q < limit1; q++)
		{
			int sum = 0;
			for (int w = 1; w < limit2 + 1; w++)
			{
				int x = stoi(grades[q][w]);
				sum += x;
			}
			int average = sum / limit2;
			grades[q][limit2 + 2] = to_string(average);
			string LetterGrade;
			if (average >= 90)
			{
				LetterGrade = "A";
				A++;
			}
			else if (average >= 80)
			{
				LetterGrade = "B";
				B++;
			}
			else if (average >= 70)
			{
				LetterGrade = "C";
				C++;
			}
			else if (average >= 60)
			{
				LetterGrade = "D";
				D++;
			}
			else
			{
				LetterGrade = "F";
				F++;
			}
			grades[q][limit2 + 3] = LetterGrade;
		}
		
		//Dislay Array

		//Heading 
		cout << "Name\t\t";
		output << "Name\t\t";
		int hw=1;
		for (int HW = 0; HW < limit2; HW++) //displays homework numbers
		{
			cout << "HW #" << hw << "\t";
			output << "HW #" << hw << "\t";
			hw++;
		}
		cout << "\tAverage" << "A-F";
		cout << endl;
		output << "\tAverage" << "A-F";
		output << endl;
		
	

		for (int lcv = 0; lcv < limit1; lcv++) 
		{
			cout << grades[lcv][0] << "\t\t";
			output << grades[lcv][0] << "\t\t";
			for (int lcv1 = 1; lcv1 <= limit2 + 3; lcv1++)
			{
				cout << grades[lcv][lcv1] << "\t";
				output << grades[lcv][lcv1] << "\t";
			}
			cout << endl;
			output << endl;
		}

		cout << "A's: " << A << endl << "B's: " << B << endl << "C's: " << C << endl << "D's: " << D << endl << "F's: " << F << endl; 

		output << "A's: " << A << endl << "B's: " << B << endl << "C's: " << C << endl << "D's: " << D << endl << "F's: " << F << endl;
	}
	

}
