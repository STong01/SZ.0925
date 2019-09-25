#include <iostream>
#include <cmath>
using namespace std;

int main4()
{
	int i, j, k;
	float x[4] = { -3, -2, 1, 4 }, y[4] = { 2, 0, 3, 1 }, dx0 = -2, dxn = -1,
		t, h[3], d[3], u[2], a[2], b[2], c[2], m[4], s[3][4];
	for (i = 0; i <= 2; i++)
	{
		h[i] = x[i + 1] - x[i];
		d[i] = (y[i + 1] - y[i]) / h[i];
	}
	for (i = 0; i <= 1; i++)
	{
		u[i] = 6 * (d[i + 1] - d[i]);
		a[0] = h[1];
		b[i] = 2 * (h[i] + h[i + 1]);
		c[i] = h[i + 1];
	}
	u[0] = u[0] - 3 * (d[0] - dx0);
	b[0] = b[0] - h[0] / 2;
	u[1] = u[1] - 3 * (dxn - d[2]);
	b[1] = b[1] - h[2] / 2;
	for (j = 1; j <= 1; j++)
	{
		t = a[j - 1] / b[j - 1];
		b[j] = b[j] - t*c[j - 1];
		u[j] = u[j] - t*u[j - 1];
	}
	m[2] = u[1] / b[1];
	m[1] = (u[0] - c[0] * m[2]) / b[0];
	m[0] = 3 * (d[0] - dx0) / h[0] - m[1] / 2;
	m[3] = 3 * (dxn - d[2]) / h[2] - m[2] / 2;
	for (k = 0; k <= 2; k++)
	{
		s[k][0] = (m[k + 1] - m[k]) / (6 * h[k]);
		s[k][1] = m[k] / 2;
		s[k][2] = d[k] - h[k] * (2 * m[k] + m[k + 1]) / 6;
		s[k][3] = y[k];
		for (i = 1; i <= 3; i++)
			cout << "s[k][i]=" << s[k][i] << endl;
	}
	system("pause");
	return 0;
}