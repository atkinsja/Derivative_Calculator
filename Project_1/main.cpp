/*********************************************************
Jeremy Atkins
MT 191
Project 1
3/1/2018
**********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;
double f(double);
double approximate(double, double);
double const tol = 0.000001;
int main()
{
	double x, h, lim_left, lim_right;
	cout << "f(x) = 3x^3 - 4x^2 + 1" << endl;
	cout << "Input the value at which to find f'(x) at: ";
	cin >> x;
	cout << fixed << setprecision(6) << endl;

	h = 1;
	if (h >= 0)
	{
		cout << "Limit approximation from the right: ";
		lim_right = approximate(x, h);
		cout << "\n\n";
	}
	h = -1;
	if (h <= 0)
	{
		cout << "Limit approximation from the left: ";
		lim_left = approximate(x, h);
		cout << "\n\n";
	}

	if (lim_right - lim_left <= tol * 2)
		cout << "The two sided limit of f(x) = " << lim_right - tol << endl;

	system("pause");
	return 0;
}

double approximate(double x, double h)
{

	double prevApprox, newApprox, diffApprox;
	do {
		prevApprox = (f(x + h) - f(x)) / h;
		h = h / 2;
		newApprox = (f(x + h) - f(x)) / h;
		diffApprox = fabs(prevApprox - newApprox);
		if (diffApprox > tol)
			cout << newApprox << " | ";
		else
			cout << newApprox;

	} while (diffApprox > tol);

	return newApprox;
}

double f(double x)
{
	return (3 * pow(x, 3) - 4 * pow(x, 2) + 1);
}