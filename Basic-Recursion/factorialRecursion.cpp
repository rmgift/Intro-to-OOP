/* implements the recursive and iterative versions of calculating
 * a factorial value, n!
 */
#include <iostream>

using namespace std;

/* iterative version */
long factorial(int n)
{
	long fact;
	if (n == 0)
	{
		fact = 1;
	}
	else
	{
		for (fact = n; n > 1; n--)
		{
			fact = fact*(n - 1);
		}
	}
	return fact;
}

/* recursive verison */
long factorial_Recursive(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * factorial_Recursive(n - 1);
}

int main()
{
	int factLoop, factRecur;
	cout << "This is calling the long loop factorial: " << endl;
	factLoop = factorial(4);
	cout << factLoop << endl;

	cout << "This is calling the shorter recursive factorial: " << endl;
	factRecur = factorial_Recursive(10);
	cout << factRecur;

	cin.get();
	return 0;
}