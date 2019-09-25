#include<iostream>
#include<cmath>
#include<iomanip>
#define n 4
#define column 5
using namespace std;

double aug[n][column], maxu, temp, s, X[n], sum;

int main1()
{
	int i, j, k, m_row, k1, u, v;
	//输入增广矩阵
	cout << "输入增广矩阵" << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<column; j++)
			cin >> aug[i][j];
	}
	//高斯列主元找主元                             
	for (i = 0; i<n - 1; i++)
	{
		//找主元，主元所在的行m_row
		cout << "找主元:";
		maxu = fabs(aug[i][i]);
		m_row = i;
		for (k = i; k<n; k++)
		if (maxu<fabs(aug[k][i]))
		{
			maxu = fabs(aug[k][i]);
			m_row = k;
		}
		cout << "主元位于第" << m_row + 1 << "行、第"
			<< i + 1 << "列," << "主元的值是:";
		cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<
			setprecision(4) << setw(10) << aug[m_row][i];
		cout << endl;
		//交换第i行和主元所在的行
		cout << "交换第" << i + 1 << "行和主元所在的行--即第"
			<< m_row + 1 << "行" << endl;
		for (j = i; j<column; j++)
		{
			temp = aug[i][j];
			aug[i][j] = aug[m_row][j];
			aug[m_row][j] = temp;
		}
		cout << "换行后的增广矩阵是:" << endl;
		for (u = 0; u<n; u++)
		{
			for (j = 0; j<column; j++)
				cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<
				setprecision(4) << setw(10) << aug[u][j];
			cout << endl;
		}
		//现在开始考虑以第i行为工具行，实施消元
		for (k1 = i + 1; k1<n; k1++)
		{
			s = -aug[k1][i] / aug[i][i];
			for (j = i; j<column; j++)
				aug[k1][j] = aug[k1][j] + s*aug[i][j];
		}
		//以第i行为工具行，实施消元结束，输出增广矩阵
		cout << "以第" << i + 1 << "行为工具行，实施消元" << endl;
		for (u = 0; u<n; u++)
		{
			for (j = 0; j<column; j++)
				cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<
				setprecision(4) << setw(10) << aug[u][j];
			cout << endl;
		}
	}
	//列主元消元过程以完成，下面进行回代求解
	X[n - 1] = aug[n - 1][n] / aug[n - 1][n - 1];
	cout <<"X["<< n - 1 + 1 <<"]="<< X[n - 1];
	cout <<"    ";
	for (u = n - 2; u >= 0; u--)
	{
		sum = 0;
		for (v = u + 1; v<n; v++)
			sum = sum + aug[u][v] * X[v];
		X[u] = (aug[u][n] - sum) / aug[u][u];
		cout << "X[" << u + 1 << "]="<< X[u];
		cout <<"    ";
	}
	system("pause");
	return 0;
}