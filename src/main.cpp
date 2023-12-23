#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double multiply(int LHS, int RHS) {
	return LHS * RHS;
}

double add(int LHS, int RHS) {
	return LHS + RHS;
}

double subtract(int LHS, int RHS) {
	return LHS - RHS;
}

double divide(int LHS, int RHS) {
	return LHS / RHS;
}

string parseString(string operation) {
	// Takes the input and parses it to determine operation and variables
	std::stringstream ss(operation);
	int LHS,
	RHS;
	char operand;
	ss >> LHS >> operand >>	RHS;
	// Calculate the result based on operand
	double resultingOperation;
	string answer;
	{
		if (operand == '*') {
			resultingOperation = multiply(LHS, RHS);
		} else if (operand == '+') {
			resultingOperation = add(LHS, RHS);
		} else if (operand == '-') {
			resultingOperation = subtract(LHS, RHS);
		} else if (operand == '/') {
			resultingOperation = divide(LHS, RHS);
		} else {
			answer = "Invalid operation";
			return answer;
		}
		answer = operation + " = " + to_string(resultingOperation);
	}
	return answer;
}

int main(int argc, char* argv[]) {
	// intro
	cout << endl << "Welcome to Calc" << endl;
	cout << "Multply  *" << endl;
	cout << "Add      +" << endl;
	cout << "Subtract -" << endl;
	cout << "Divide   /" << endl;
	// Input handling
	string answer;
	{
		string operation;
		cout << "Complete an operation: ";
		getline(cin, operation);
		// parse string returns the answer
		answer = parseString(operation);
	}
	cout << endl << answer << endl;
	return 0;
}