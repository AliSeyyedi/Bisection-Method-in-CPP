#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define EPSILON 0.01 
double func(double a, double b, double t, double s, double y, double x)
{
	return a * pow(x, t) + b * pow(x, s) + y;
}
void bisection(double a, double b, double t, double s, double y, double L, double R)
{
	string ans;
	if (func(a, b, t, s, y, L) * func(a, b, t, s, y, R) >= 0)
	{
		cout << "\nYou have not assumed right a and b \n";
		return;
	}
	cout << "\nDo you wanna set iteration times? (y/n)";
	cin >> ans;
	if (ans == "y" || ans == "Y")
	{
		cout << "\nEnter the iteration you want to perform: ";
		int times;
		cin >> times;
		double c = L;
		for (int i = 1; i <= times; i++)
		{
			c = (L + R) / 2;
			if (func(a, b, t, s, y, c) == 0.0){
				cout << "\nThe value of root after " << i << " iteration is : " << c;
				break;
			}
			else if((R - L) <= EPSILON)
			break;
			else if (func(a, b, t, s, y, c)*func(a, b, t, s, y, L) < 0)
				R = c;
			else
				L = c;
			cout << "\nThe value of root after " << i << " iteration is : " << c;
		}
	}
	else if (ans == "n" || ans == "N")
	{
		double c = L;
		while ((R - L) >= EPSILON)
		{
			c = (L + R) / 2;
			if (func(a, b, t, s, y, c) == 0.0)
				break;
			else if (func(a, b, t, s, y, c)*func(a, b, t, s, y, L) < 0)
				R = c;
			else
				L = c;
		}
		cout << "\nThe value of root is : " << c;
	}
}
int main()
{
	double L, R, f, a, b, t, s, y;
	cout << "Enter 1st value:";
	cin >> L;
	cout << "Enter 2nd value:";
	cin >> R;
	cout << "Considering front format:    a*x^t+b*x^s+y \n";
	cout << "\n a is ";
	cin >> a;
	if (a != 0) {
		cout << "\n t is ";
		cin >> t;
	}
	cout << "\n b is ";
	cin >> b;
	if (b != 0) {
		cout << "\n s is ";
		cin >> s;
	}
	cout << "\n y is ";
	cin >> y;
	bisection(a, b, t, s, y, L, R);
}
