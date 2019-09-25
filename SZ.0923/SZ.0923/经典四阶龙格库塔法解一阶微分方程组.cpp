#include<iostream>
using namespace std;
#define f(x,y)  (x+y)
#define MAX_N    500

int main3()
{
	int n, i;
	double a, b, a0, h, x, w, k1, k2, k3, k4;
	cout << "输入区间[a,b]:" << endl;
	cin >> a >> b;
	cout << "输入初始值f(a0)：" << endl;
	cin >> a0;
	cout << "你想要将区间[" << a << "," << b << "]几等分:" << endl;
	cin >> n;
	if (n>MAX_N)
	{
		cout << "输入大于程序预设最大等分值，请重新输入或设定！" << endl;
		return 1;
	}
	h = (b - a) / n;
	x = a;
	w = a0;
	for (i = 1; i <= n; i++)
	{
		k1 = h*f(x, w);
		k2 = h*f((x + h / 2), (w + k1 / 2));
		k3 = h*f((x + h / 2), (w + k2 / 2));
		k4 = h*f((x + h), (w + k3));
		w = w + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		x = a + i*h;
		cout << i << " " << x << " " << i << " " << w << endl;
	}
	system("pause");
	return 0;
}