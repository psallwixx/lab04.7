#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n = 0;
    const double PI = 3.141592653589793238;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "acos(x)" << " |"
		<< setw(7) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		n = 1; 
		a = x*x*x/6; 
		S = a;
		do {
			n++;
			R = (x * (2 * n - 1) * (2 * n - 1)) / ((2 * n + 1) * (2 * n - 2));
			a *= R;
			S += a;
			S = PI / 2 - (x + S);
		} while (abs(a) >= eps);
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << acos(x) << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	return 0;
}
