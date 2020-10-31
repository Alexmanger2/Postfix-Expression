#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedStack.h"

using namespace std;

int main() {

//-------What the program does-----
//Uses a Linked stack to solve a postfix expression for any # of digits


// Create a linkedStack object that holds floats
// ask user for postfix expression
	LinkedStack <float> operandstack;
	float operand1 = 0, operand2 = 0, result = 0;
	string postfixStr;

	cout << "Enter postfix expression" << endl;
	getline(cin, postfixStr);
	//traverse string with conditions
	string holder;
	for (int i = 0; i < postfixStr.length(); i++) {
		// if postfixStr[i] is a digit, store in string holder
		if (isdigit(postfixStr[i])) {
			holder += postfixStr[i];
		}
		//if postfixStr[i] is a space, convert and push string holder onto stack
		else if (isspace(postfixStr[i])) {
			if (holder != "") {
				operandstack.push(stoi(holder));
				holder = "";
			}
		}
		else {
			//pop operand1 and operand2 values off stack for calculations
			operand2 = operandstack.peek();
			operandstack.pop();

			operand1 = operandstack.peek();
			operandstack.pop();

			switch (postfixStr[i]) {
			case '*':
				result = operand1 * operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '+':
				result = operand1 + operand2;
				break;
			case '/':
				if (operand2 != 0)  // Can't divide by zero
					result = operand1 / operand2;
				else
					cout << "operand2 cannot equal zero" << endl;
				break;
			default:
				cout << "Incorrect operator(s) were entered" << endl;


			}
			//push new result onto stack for continued arithmetic
			operandstack.push(result);

		}

	}
	cout << endl;
	if (operand2 == 0) {
		cout << "Error, can't divide by zero" << endl;
	}
	else {
	cout << "Top of stack = " << result << endl << endl;
}
	system("pause");
	return 0;
}