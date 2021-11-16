/*
 * Calculator.cpp
 *
 *  Date: 5/16/2021
 *  Author: Fred Wahab
 */

#include <iostream>

using namespace std;

void main()
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer = 'Y'; // Changed double quotes to single and added ;
		while (answer == 'y' || answer == 'Y') // Added 'or' to 'while' to allow for upper and lower case y.
		{
			cout << "Enter expression" << endl;
			cin >> op1 >> operation >> op2; // Swapped op1 and op2.
			if (operation == '+') { // Changed double quotes to single. Brackets added to 'if'.
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // Change >> to <<.
			}
			if (operation == '-') { // Brackets added to 'if'.
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // Change >> to <<.
			}
			if (operation == '*') { // Add ; to end. Brackets added to 'if'.
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // Add ; to end. Change / to *.
			}
			if (operation == '/') { // Add ; to end. Brackets added to 'if'.
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // Change * to /.
			}

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
		}

		cout << "Program Finished." << endl; // Added string to end of program.
}