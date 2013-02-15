#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	int line, qAmount, length, numRand, period, qPoint, bar;
	cout << "\nEnter total number of questions: ";
	while (!(cin >> line))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "\n> Error: Numbers only"
			 << endl;
	}
	//cout << "\nEnter desired number of questions: ";
	//while (!(cin >> qAmount))
	//{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//cerr << "\n> Error: Numbers only"
			 //<< endl;
	//}
	fstream qlib;
	qlib.open("q.lib");
	string qlibStr, qlibHold, number, question, answer, answerIn;

	vector <string> asked;
	for (int i = 0; i < line; i++)
	{
		//cout << ".";

		bool used = false;

		numRand = rand() % (line + 1);

		stringstream randSS;
		randSS << numRand;

		getline(qlib, qlibHold);

		period = qlibHold.find('.');
		qPoint = qlibHold.find('?');
		bar = qlibHold.find('|');
		number = qlibHold.substr(0, period);
		question = qlibHold.substr(period + 2, qPoint - period);
		answer = qlibHold.substr(bar + 1, qlibHold.length() - bar);

		for (int x = 0; x < asked.size(); x++)
		{
			if (asked[x] == number) used = true;
		}

		if ((number == randSS.str()) && (!used))
		{
			asked.push_back(number);
			cout << "\n> Question " << number << ": " << question;
			//cout << "\n>     Answer: " << answer << endl;
			cout << "\n>     Answer: ";
			cin >> answerIn;
			if (answerIn == answer)
			{
				cout << ">---------------Correct"
				 	<< endl;
			}
			else
			{
				cout << ">---------------Incorrect"
					 << endl;
				break;
			}
		}

		//cout << asked.size();
		if ((i == (line - 1)) && (asked.size() < line))
		{
			i = 0;
			qlib.seekg(0, ios::beg);
		}
		//qlibStr.append(qlibHold);
		//if (i != (line - 1)) qlibStr.append("\n");
			//cout << qlibIn << endl << qlibHold << endl;
		//cout << qlibStr << endl;
	}
	//qlib.seekg(0, ios::beg);
	//while (qlib >> qlibIn)
	//{
		//qlibHold.append(qlibIn);
		//qlibHold.append("\n");
		//cout << qlibHold << endl;
		//if ()
	//}
	char hold;
	cin >> hold;
	if (hold == 'r') main();
	return 0;
}