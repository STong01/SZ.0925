#include<iostream>
#include<iomanip>
#include<cmath>
#define N 2               // 非线性方程组中方程个数、未知量个数 
#define Epsilon 0.0001    // 差向量1范数的上限
#define Max     100       //最大迭代次数
using namespace std;

const int N2 = 2 * N;

void ff(float xx[N], float yy[N])
{
	float x, y;
	int i;
	x = xx[0];
	y = xx[1];
	yy[0] = x*x - 2 * x - y + 0.5;
	yy[1] = x*x + 4 * y*y - 4;
	cout << "当前自变量向量为：" ;
	for (i = 0; i<N; i++)
		cout << setw(10) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << xx[i] << "  ";
	cout << endl;
	cout << endl;
	cout << "当前因变量向量为：" ;
	for (i = 0; i<N; i++)
		cout << setw(10) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << yy[i] << "  ";
	cout << endl;
	cout << endl;
}

void ffjacobian(float xx[N], float yy[N][N])
{
	float x, y;
	int i, j;
	x = xx[0];
	y = xx[1];
	yy[0][0] = 2 * x - 2;
	yy[0][1] = -1;
	yy[1][0] = 2 * x;
	yy[1][1] = 8 * y;
	cout << "当前的雅克比矩阵是： " << endl;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			cout << setw(10) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << yy[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

void inv_jacobian(float yy[N][N], float inv[N][N])
{
	float aug[N][N2], L;
	int i, j, k;
	// "计算雅克比矩阵的逆矩阵"
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			aug[i][j] = yy[i][j];
		for (j = N; j<N2; j++)
		if (j == i + N)
			aug[i][j] = 1;
		else
			aug[i][j] = 0;
	}
	for (i = 0; i<N; i++)
	{
		for (k = i + 1; k<N; k++)
		{
			L = -aug[k][i] / aug[i][i];
			for (j = i; j<N2; j++)
				aug[k][j] = aug[k][j] + L*aug[i][j];
		}
	}
	for (i = N - 1; i>0; i--)
	{
		for (k = i - 1; k >= 0; k--)
		{
			L = -aug[k][i] / aug[i][i];
			for (j = N2 - 1; j >= 0; j--)
				aug[k][j] = aug[k][j] + L*aug[i][j];
		}
	}
	for (i = N - 1; i >= 0; i--)
	for (j = N2 - 1; j >= 0; j--)
		aug[i][j] = aug[i][j] / aug[i][i];
	for (i = 0; i<N; i++)
	{
		for (j = N; j<N2; j++)
			inv[i][j - N] = aug[i][j];
	}
	cout << endl;
	cout << "雅克比矩阵的逆矩阵是（Inverse of Jacobian is） " << endl;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			cout << setw(10) << setiosflags(ios::right) << setprecision(5) << setiosflags(ios::fixed) << inv[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

void newdundiedai(float x0[N], float inv[N][N], float y0[N], float x1[N])
{
	int i, j;
	float sum = 0;
	for (i = 0; i<N; i++)
	{
		sum = 0;
		for (j = 0; j<N; j++)
			sum = sum + inv[i][j] * y0[j];
		x1[i] = x0[i] - sum;
	}
	cout << "近似解向量" ;
	for (i = 0; i<N; i++)
		cout << x1[i] << "  ";
	cout << endl; cout << endl;
}

int main2()
{
	void ff(float xx[N], float yy[N]);
	void ffjacobian(float xx[N], float yy[N][N]);
	void inv_jacobian(float yy[N][N], float inv[N][N]);
	void newdundiedai(float x0[N], float inv[N][N], float y0[N], float x1[N]);
	float x0[N] = { 2.0, 0.25 }, y0[N], jacobian[N][N], invjacobian[N][N], x1[N], errornorm;
	int i, j, iter = 0;
	cout << "初始解向量是：" ;
	for (i = 0; i<N; i++)
		cout << x0[i] << "  ";
	cout << endl; cout << endl;
	do
	{
		iter = iter + 1;
		cout << "第 " << iter << " 次迭代开始" << endl;
		//计算向量函数值---因变量向量存放在一维数组y0中，y0做函数ff的实参，ff(x0,y0)的调用将传出因变量向量
		ff(x0, y0);
		//计算雅克比矩阵，二维数组jacobian作为ffjacobian的实参;调用ffjacobian(x0,jacobian)，
		//按照地址传送方式，二维数组jacobian将传出雅克比矩阵的计算结果
		ffjacobian(x0, jacobian);
		//调用函数inv_jacobian计算雅克比矩阵的逆矩阵，计算结果存放在实参invjacobian中
		inv_jacobian(jacobian, invjacobian);
		//由近似解向量x0迭代计算近似解向量x1
		cout << "第 " << iter << " 次迭代得到";
		newdundiedai(x0, invjacobian, y0, x1);
		//计算x1与x0的差向量的1范数
		errornorm = 0;
		for (i = 0; i<N; i++)
			errornorm = errornorm + fabs(x1[i] - x0[i]);
		if (errornorm<Epsilon)
			break;
		//为下次循环计算准备新的x0
		for (i = 0; i<N; i++)
			x0[i] = x1[i];
	} while (iter<Max);
	cin >> iter;
	system("pause");
	return 0;
}
