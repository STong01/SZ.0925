#include<iostream>
#include<iomanip>
#include<cmath>
#define   N 5
using namespace std;

void main5()
{
	double f(double x);
	static double R[N][N], H[N], h;
	double result;
	int i = 0, j = 0;
	double a, b, ep;
	a = 0.0;
	b = 1.0;
	ep = 0.0001;
	R[0][0] = (b - a)*(f(a) + f(b)) / 2;
	H[0] = (b - a)*f((a + b) / 2);
	cout << setw(7) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << R[i][i] << endl;
	do
	{
		i = i + 1;
		if (i >= N)
		{
			cout << "I am sorry! To exceed R's upper bound of row" << endl;
			break;
		};
		for (j = 0; j <= i; j++)
		if (j == 0)
		{
			R[i][j] = (R[i - 1][j] + H[i - 1]) / 2;
			cout << setw(7) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << R[i][j] << "  ";
		}
		else
		{
			R[i][j] = (pow(4.0, j)*R[i][j - 1] - R[i - 1][j - 1]) / (pow(4.0, j) - 1);
			cout << setw(7) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << R[i][j] << "  ";
		}
		cout << endl;

		h = (b - a) / pow(2.0, i); H[i] = 0;
		for (j = 1; j <= pow(2.0, i); j++)
			H[i] = H[i] + h*f(a + (2 * j - 1)*h / 2);

		j = 0;
	} while (fabs(R[i][i] - R[i - 1][i - 1])>ep);
	if (i<N)
	{
		result = R[i][i];
		cout << "i=" << i << "  积分结果是：" << result << endl;
	}
	system("pause");
}

double f(double x)
{
	return x*x;
}