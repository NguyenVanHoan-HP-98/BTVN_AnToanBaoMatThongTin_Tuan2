// TimPhanTuNghichDao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int check_number(long a, long  b)
{
	if (a == 0 || b == 0) {
		return a + b;
	}
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

int modulo_inverse(int a, int b) {
	for (int i = 1; i < b; i++) {
		if (((long long)a * i) % b == 1) {
			return i;
		}
	}
	return -1; // not exist
}

int main()
{
	long a, modulo;
	cout << "Nhap vao so can tim nghich dao";
	cin >> a;
	do
	{
		cout << "Nhap vao vanh dong du modulo lon hon a : ";
		cin >> modulo;
	} while (a > modulo);

	if (check_number(a, modulo) != 1)
	{
		cout << "Khong ton tai so nghich dao cua " << a;
	}
	else
	{
		cout << "phan tu nghich dao la : " << modulo_inverse(a, modulo);
	}
}