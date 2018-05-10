/*************************************************************************
Author: Ryan Gift
Date: 03/09/17
Description: The postfixEval file contains a function that converts a 
 Cstring passed to it in the format of a postfix expression into its
 equivalent double value. The function utilizes a stack<double> from the
 STL to evaluate the expression.
*************************************************************************/
#include <iostream>
#include <stack>	// used for stack processing
#include <cctype>	// used for isdigit
#include <cstring>	// used for strlen function
using std::stack;
using std::cout;
using std::cin;
using std::endl;

// Function prototypes
double postfixEval(char arr[]);

/*************************************************************************
* The postfixEval function uses a stack<double> (from the STL) to        *
* evaluate postfix expressions. It takes a C-style string parameter that *
* represents a postfix expression and returns a double value.            *
* The only allowable symbols in the strings are + , -, *, / , digits and *
* spaces. The + and - operators will only be used as binary operators.   *
*************************************************************************/
double postfixEval(char arr[])
{
	stack<double> calc;		// stack variable
	double postFix = 0;		// final return value
	unsigned int size = strlen(arr);	// finds Cstring initial size
	double oper1, oper2;	// operand calc variables
	int myFlag = 0;			// digit flag, greater than single digit
	int dotFlag = 0;		// decimal flag, evaluation of . numbers
	double x = 0;			// decimal position holder, .1, .01, .001, etc.

	for (unsigned int i = 0; i < size; i++)
	{
		// if array is not empty continue to process
		if (arr[i] != '\0')
		{
			// if element is a digit push to stack
			if (isdigit(arr[i]))
			{
				// if back to back digits pop previous value and tack on new amount
				if (myFlag == 1)
				{
					// if previous element was a decimal value
					if (dotFlag == 1)
					{
						oper1 = calc.top();
						calc.pop();
						calc.push(oper1 + ((arr[i] - 48)*(x)));
						x *= 0.1;
					}
					// back to back digits
					else
					{
						oper1 = calc.top();
						calc.pop();
						calc.push((oper1 * 10) + (arr[i] - 48));
					}
				}
				// single digit, push to stack
				else
				{
					calc.push(arr[i] - 48);
					myFlag = 1;
				}
			}
			// not a digit, process space and reset flags
			else if (arr[i] == ' ')
			{
				myFlag = 0;
				dotFlag = 0;
				x = 0;
			}
			// not a digit, process decimal and set flags
			else if (arr[i] == '.')
			{
				dotFlag = 1;
				x = 0.1;
			}
			// operator, pop stack and process evaluation
			else
			{
				oper2 = calc.top();
				calc.pop();
				oper1 = calc.top();
				calc.pop();
				switch (arr[i])
				{
					case '+':calc.push((oper1+oper2));
						break;
					case '-':calc.push((oper1-oper2));
						break;
					case '*':calc.push((oper1*oper2));
						break;
					case '/':calc.push((oper1/oper2));
						break;
				}
			}
		}
	}

	// pull final representations off the stack 
	// and assign to postFix for return value
	while (!calc.empty())
	{
		postFix += calc.top();
		calc.pop();
	}

	return postFix;
}

int main()
{
	double result1;
	char myCstring[6] = "4 5 +";
	result1 = postfixEval(myCstring);
	cout << endl;
	cout << "String: 4 5 +" << endl;
	cout << "Expected: 4 + 5 = 9" << endl;
	cout << "Result: " << result1 << endl;
	cout << endl;

	double result2;
	char myCstring2[6] = "4 5 *";
	result2 = postfixEval(myCstring2);
	cout << endl;
	cout << "String: 4 5 *" << endl;
	cout << "Expected: 4 * 5 = 20" << endl;
	cout << "Result: " << result2 << endl;
	cout << endl;

	double result3;
	char myCstring3[6] = "4 5 -";
	result3 = postfixEval(myCstring3);
	cout << endl;
	cout << "String: 4 5 -" << endl;
	cout << "Expected: 4 - 5 = -1" << endl;
	cout << "Result: " << result3 << endl;
	cout << endl;

	double result4;
	char myCstring4[6] = "4 5 /";
	result4 = postfixEval(myCstring4);
	cout << endl;
	cout << "String: 4 5 /" << endl;
	cout << "Expected: 4 / 5 = 0.8" << endl;
	cout << "Result: " << result4 << endl;
	cout << endl;

	double result5;
	char myCstring5[14] = "9 8 7 - 3 * /";
	result5 = postfixEval(myCstring5);
	cout << endl;
	cout << "String: 9 8 7 - 3 * /" << endl;
	cout << "Expected: 9 / ((8-7) * 3) = 3" << endl;
	cout << "Result: " << result5 << endl;
	cout << endl;
	
	double result6;
	char myCstring6[16] = "25 12 7 - 2 * /";
	result6 = postfixEval(myCstring6);
	cout << endl;
	cout << "String: 25 12 7 - 2 * /" << endl;
	cout << "Expected: 25 / ((12 - 7) * 2) = 2.5" << endl;
	cout << "Result: " << result6 << endl;
	cout << endl;

	double result7;
	char myCstring7[18] = "59 26 12 + 19 / *";
	result7 = postfixEval(myCstring7);
	cout << endl;
	cout << "String: 59 26 12 + 19 / *" << endl;
	cout << "Expected: 59 * ((26+12) / 19) = 118" << endl;
	cout << "Result: " << result7 << endl;
	cout << endl;

	double result8;
	char myCstring8[21] = "100 4 2 * 47 + 5 - /";
	result8 = postfixEval(myCstring8);
	cout << endl;
	cout << "String: 100 4 2 * 47 + 5 - /" << endl;
	cout << "Expected: 100 / (((4*2) + 47) - 5) = 2" << endl;
	cout << "Result: " << result8 << endl;
	cout << endl;

	double result9;
	char myCstring9[10] = "9.5 6.2 *";
	result9 = postfixEval(myCstring9);
	cout << endl;
	cout << "String: 9.5 6.2 *" << endl;
	cout << "Expected: 9.5 * 6.2 = 58.9" << endl;
	cout << "Result: " << result9 << endl;
	cout << endl;

	double result10;
	char myCstring10[17] = "251.89 3287.35 +";
	result10 = postfixEval(myCstring10);
	cout << endl;
	cout << "String: 251.89 3287.35 + " << endl;
	cout << "Expected: 251.89 + 3287.35 = 3539.24" << endl;
	cout << "Result: " << result10 << endl;
	cout << endl;

	double result11;
	char myCstring11[20] = "251.893 32.351 -";
	result11 = postfixEval(myCstring11);
	cout << endl;
	cout << "String: 251.893 32.351 -" << endl;
	cout << "Expected: 251.893 - 32.351 = 219.542" << endl;
	cout << "Result: " << result11 << endl;
	cout << endl;

	double result12;
	char myCstring12[22] = "11.62 2.518 6.371 * +";
	result12 = postfixEval(myCstring12);
	cout << endl;
	cout << "String: 11.62 2.518 6.371 * +" << endl;
	cout << "Expected: 11.62 + (2.518 * 6.371) = 27.6622" << endl;
	cout << "Result: " << result12 << endl;
	cout << endl;

	system("pause");
	return 0;
}