#include <iostream>
#include <iomanip>
#include <conio.h>
#include <locale.h>
#include "bitfield.h"
#include "set.h"
#include<algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int n, m,k=1;
	int max = 0;
	
	
	


	/*cout << "������������ ������� ��������� ������� ���������" << endl;
	cout << "              ������ ����������" << endl;*/
	cout << "������� ������� ������� ����� �������� - ";
	cin >> n;
	TSet s1(n + 1), s2(n+1), s3(n+1), s4(n+1), s5(n+1);
	int count1=n;
	for (m = 2; m <= n; m++) s1.InsElem(m);
	for (m = 2; m * m <= n; m++)
		if (s1.IsMember(m))
			for (k = 2 * m; k <= n; k += m)
				if (s1.IsMember(k)) {
					s1.DelElem(k); count1--;
				}

	int count2 = n;
	for (m = 1; m <= n; m++) s2.InsElem(m);
	for (m = 1; m <= n; m++) {
		if (m%3!=0)
		{
			s2.DelElem(m);
			count2--;
		}
	}
	
	if (count1 < count2)
		max = count2;
	else
		max = count1;
	
	int count3 = n;
	for (m = 1; m <= n; m++) s3.InsElem(m);
	for (m = 1; m <= n; m++) {
		int a = 1, k = m;
		int sNum = 0;
		while (a <=n)
		{
			sNum += k % 10;
			k /= 10;
			a *= 10;
		}

		if (sNum%2!=0)
		{
			s3.DelElem(m);
			count3--;
		}
	}

	if (count3 > max)
	{
		max = count3;
	}

	int count4 = n;
	for (m = 1; m <= n; m++) s4.InsElem(m);
	for (m = 1; m <= n; m++) {
		if (m % 2 == 0&&m%3!=0)
		{
			s4.DelElem(m);
			count4--;
		}
	}
	if (count4>max)
	{
		max = count4;
	}
	int choice, choice2;
	cout << "1)������� ����� ������ ���������\n2)����������� �������� ���������" << endl;
	cin >> choice;
	if (choice != 1 && choice != 2)
	{
		cout << "������! ����� �������� ����� ������ ���������!" << endl;
	}
	else if (choice==2)
	{
		cout << "��������� ���������\n1)��������� ������� �����\n2)��������� ����� ������� 3\n3)��������� ����� � ������ ������ ����\n4)��������� �������� ����� ��� ������� 6" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:max = count1; break;
		case 2:max = count2; break;
		case 3:max = count3; break;
		case 4:max = count3; break;
		default:cout << "������! ����� �������� ����� ������ ���������!" << endl; break;
		}
	}
	if (max==count1)
	{
		cout << "������ ������� �����" << endl;
		for (m = 2; m <= n; m++)
			if (s1.IsMember(m)) {
				cout << setw(3) << m << " ";
				if (k++ % 10 == 0) cout << endl;
			}
		cout << endl;
		cout << "� ������ " << n << " ������ " << count1 << " �������" << endl;
	}
	if (max == count2)
	{
		cout << "������ ����� ������� 3" << endl;
		for (m = 1; m <= n; m++)
		{
			if (s2.IsMember(m))
			{
				cout << setw(3) << m << " ";
				if (k++ % 10 == 0) cout << endl;
			}
		}
		cout << endl;
		cout << "� ������ " << n << " ������ " << count2 << " ������� 3" << endl;
	}
	if (max == count3)
	{
		cout << "������ ����� ����� ���� ������� - ������" << endl;
		for (m = 1; m <= n; m++)
		{
			if (s3.IsMember(m))
			{
				cout << setw(3) << m << " ";
				if (k++ % 10 == 0) cout << endl;
			}
		}
		cout << endl;
		cout << "� ������ " << n << " ������ " << count3 << " ����� ���� ������� ������" << endl;
	}
	if (max == count4)
	{
		cout << "������ �������� ����� � ����� ������� 6" << endl;
		for (m = 1; m <= n; m++)
		{
			if (s4.IsMember(m))
			{
				cout << setw(3) << m << " ";
				if (k++ % 10 == 0) cout << endl;
			}
		}
		cout << endl;
		cout << "� ������ " << n << " ������ " << count4 << " �������� ��� ������� 6" << endl;
	}

	return 0;
}