// ThuatToanLeman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

long modexp(long a, long x, long n)
{
	long r = 1;
	while (x > 0) {
		if (x % 2 == 1) /* is x odd? */
			r = (r * a) % n;
		a = (a*a) % n;
		x /= 2;
	}
	return r;
}
int main()
{
	srand((int)time(0));
	long a, x;
	long arr[101];
	int arrLuuKq[101];
	cout << "Nhap vao so muon kiem tra :";
	cin >> a;
	x = (a - 1) / 2;
	if (a == 2 || a == 3 || a == 5 || a == 7 || a == 9 || a == 11)
	{
		cout << "La so nguyen to ";
	}
	else
	{
		if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0 || a % 9 == 0 || a % 11 == 0 || a<=1)
		{
			cout << "Khong phai so nguyen to";
		}
		else
		{
			for (int i = 0; i < 100; i++)
			{
				long x = 1 + rand() % a - 1;
				arr[i] = x;
			}
			for (int i = 0; i < 100; i++)
			{

				arrLuuKq[i] = modexp(arr[i], x, a);
			}
			int co = 0;
			for (int i = 1; i < 100; i++)
			{
				if (arrLuuKq[i] == 1 || arrLuuKq[i] == a - 1)
				{
					co = 1;
				}
			}
			if (co == 1)
			{
				cout << "La so nguyen to ";
			}
			else
			{
				cout << "Khong la so nguyen to ";
			}
		}
	}
	
}


