// ThuatToanLuyThuaNhanh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

long modexp(long a, long x, long n)
{
	long r = 1;
	while (x > 0) {
		if (x % 2 == 1) /* is x odd? */
			r = (r * a) % n;
		a = (a*a) % n;
		x /= 2;
		cout << a << " " << x << " " << n << " " << r;
		cout << "\n";
	}
	return r;
}


int main()
{
	long a, n, x;
    cout << "Nhap vao a , x , N ( a ^ x mod N) : ";
	cin >> a >> x >> n;
	cout << modexp(a, x, n);
}


