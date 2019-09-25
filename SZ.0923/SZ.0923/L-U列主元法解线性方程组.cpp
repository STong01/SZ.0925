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
	//�����������
	cout << "�����������" << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<column; j++)
			cin >> aug[i][j];
	}
	//��˹����Ԫ����Ԫ                             
	for (i = 0; i<n - 1; i++)
	{
		//����Ԫ����Ԫ���ڵ���m_row
		cout << "����Ԫ:";
		maxu = fabs(aug[i][i]);
		m_row = i;
		for (k = i; k<n; k++)
		if (maxu<fabs(aug[k][i]))
		{
			maxu = fabs(aug[k][i]);
			m_row = k;
		}
		cout << "��Ԫλ�ڵ�" << m_row + 1 << "�С���"
			<< i + 1 << "��," << "��Ԫ��ֵ��:";
		cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<
			setprecision(4) << setw(10) << aug[m_row][i];
		cout << endl;
		//������i�к���Ԫ���ڵ���
		cout << "������" << i + 1 << "�к���Ԫ���ڵ���--����"
			<< m_row + 1 << "��" << endl;
		for (j = i; j<column; j++)
		{
			temp = aug[i][j];
			aug[i][j] = aug[m_row][j];
			aug[m_row][j] = temp;
		}
		cout << "���к�����������:" << endl;
		for (u = 0; u<n; u++)
		{
			for (j = 0; j<column; j++)
				cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<
				setprecision(4) << setw(10) << aug[u][j];
			cout << endl;
		}
		//���ڿ�ʼ�����Ե�i��Ϊ�����У�ʵʩ��Ԫ
		for (k1 = i + 1; k1<n; k1++)
		{
			s = -aug[k1][i] / aug[i][i];
			for (j = i; j<column; j++)
				aug[k1][j] = aug[k1][j] + s*aug[i][j];
		}
		//�Ե�i��Ϊ�����У�ʵʩ��Ԫ����������������
		cout << "�Ե�" << i + 1 << "��Ϊ�����У�ʵʩ��Ԫ" << endl;
		for (u = 0; u<n; u++)
		{
			for (j = 0; j<column; j++)
				cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<
				setprecision(4) << setw(10) << aug[u][j];
			cout << endl;
		}
	}
	//����Ԫ��Ԫ��������ɣ�������лش����
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