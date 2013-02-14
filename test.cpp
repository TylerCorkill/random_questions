#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

using namespace std;

int main()
{
	int line, colon, qPoint;
	cout << "\nEnter the number of questions: ";
	while (!(cin >> line))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "\n> Error: Numbers only"
			 << endl;
	}
	fstream qlib;
	qlib.open("q.lib");
	string qlibHold, question, answer, answerIn;
	for (int i = 0; i < line; i++)
	{
		getline(qlib, qlibHold);

		colon = qlibHold.find(':');
		qPoint = qlibHold.find('?');

		question = qlibHold.substr(colon + 1, qPoint - colon);
		answer = qlibHold.substr(qPoint + 1, qlibHold.length() - qPoint);

		cout << "\n> Question " << i + 1 << ": " << question;
		//cout << "\n>     Answer: " << answer << endl;

		cout << "\n>     Answer: ";
		cin >> answerIn;
		if (answerIn == answer)
		{
			cout << "              Correct"
				 << endl;
		}
		else
		{
			cout << "              Incorrect"
				 << endl;
			break;
		}

		//qlibHold.append(qlibHold);
		//if (i != (line - 1)) qlibHold.append("\n");

		//cout << qlibIn << endl << qlibHold << endl;
		//cout << qlibHold << endl;
	}
	//while (qlib >> qlibIn)
	//{
		//qlibHold.append(qlibIn);
		//qlibHold.append("\n");
		//cout << qlibHold << endl;
		//if ()
	//}
}