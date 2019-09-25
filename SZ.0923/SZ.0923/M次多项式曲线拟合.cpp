#include <iostream> 
#include <stdlib.h> 
using namespace std;

float p[4][4] = { { 0 }, { 0 }, { 0 }, { 0 } };
float x[5], f[5];

float vl(int i, float s)
{
	float a;
	a = p[i][0] + p[i][1] * s + p[i][2] * s*s + p[i][3] * s*s*s;
	return a;
}

float q1(int k)
{
	float a, b = 0.0;
	int i = 0;
	while (i<5)
	{
		a = x[i] * vl(k, x[i])*vl(k, x[i]);
		b = b + a;
		i++;
	}
	return b;
}

float q2(int k)
{
	float a, b = 0.0;
	int i = 0;
	while (i<5)
	{
		a = vl(k, x[i])*vl(k, x[i]);
		b = b + a;
		i++;
	}
	return b;
}

float q3(int k)
{
	float a, b = 0.0;
	int i = 0;
	while (i<5)
	{
		a = f[i] * vl(k, x[i]);
		b = b + a;
		i++;
	}
	return b;
}

float at(int k)
{
	float aa;
	aa = q1(k - 1) / q2(k - 1);
	return aa;
}

float bt(int k)
{
	float bb;
	bb = q2(k) / q2(k - 1);
	return bb;
}

void pp(int i)
{
	int j = 0;
	if (i == 0)
		p[i][0] = 1;
	else if (i == 1)
		p[i][0] = -at(1);
	else if (i >= 2)
	{
		if (j == 0)
			p[i][j] = -p[i - 1][j] * at(i) - p[i - 2][j] * bt(i - 1);
		j++;
		while (j<4)
		{
			p[i][j] = p[i - 1][j - 1] - p[i - 1][j] * at(i) - p[i - 2][j] * bt(i - 1);
			j++;
		}
	}
}

int main()
{
	float a[4], y[4];
	int i, j;
	cout << "请输入离散点(x,y):" << endl;
	for (i = 0; i<5; i++)
	{
		cin >> x[i] >> f[i];
	}
	for (i = 0; i<4; i++)
		p[i][i] = 1;
	i = 0;
	while (i<4)
	{
		pp(i);
		i++;
	}
	for (i = 0; i<4; i++)
		a[i] = q3(i) / q2(i);
	for (i = 0; i<4; i++)
	{
		y[i] = 0;
		j = 0;
		while (j<4)
		{
			y[i] += a[j] * p[j][i];
			j++;
		}
	}
	cout << "拟合多项式为：" << endl;
	cout << y[3] << "x^3+(" << y[2] << ")*x^2+" << y[1] << "x+(" << y[0] << ")" << endl;
	system("pause");
	return 0;
}