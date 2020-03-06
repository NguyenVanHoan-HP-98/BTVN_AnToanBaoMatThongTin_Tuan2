#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>


using namespace std;
class solon
{
private:
	int *so;
	int sopt;
	bool soam;
public:
	solon() { so = new int[100]; soam = false; }
	void ChuyenSo(int mang[], char so[])
	{
		for (int i = 0; i < strlen(so); i++)
		{
			char tam = so[strlen(so) - i - 1];
			mang[i] = atoi(&tam);
		}
	}
	friend ostream & operator <<(ostream &out, solon &p);
	friend istream & operator >>(istream &cn, solon &p);
	///////////////////////////////////////////////////////////////////
	//Phép cộng
	///////////////////////////////////////////////////////////////////
	solon operator+(solon p)
	{
		solon kq;
		if (p.sopt > sopt)
		{
			int m = p.sopt - sopt;
			for (int i = 1; i <= m; i++)
			{
				so[sopt - 1 + i] = 0;
			}
			sopt = p.sopt;
		}
		else
		{
			int m = sopt - p.sopt;
			for (int i = 1; i <= m; i++)
			{
				p.so[p.sopt - 1 + i] = 0;
			}
			p.sopt = sopt;
		}
		kq.sopt = sopt + 1;
		int nho = 0;
		for (int i = 0; i < sopt; i++)
		{
			kq.so[i] = (so[i] + p.so[i] + nho) % 10;
			nho = (so[i] + p.so[i] + nho) / 10;
		}
		if (nho > 0)
		{
			kq.so[sopt] = nho;
		}
		else
		{
			kq.sopt = sopt;
		}
		return kq;
	}
	//////////////////////////////////////////////////////////
	//phep trừ
	//////////////////////////////////////////////////////////
	solon operator-(solon p)
	{
		//cân bằng số phần tử
		solon kq;
		if (p.sopt > sopt)
		{
			int m = p.sopt - sopt;
			for (int i = 1; i <= m; i++)
			{
				so[sopt - 1 + i] = 0;
			}
			sopt = p.sopt;
		}
		else
		{
			int m = sopt - p.sopt;
			for (int i = 1; i <= m; i++)
			{
				p.so[p.sopt - 1 + i] = 0;
			}
			p.sopt = sopt;
		}
		kq.sopt = sopt;
		for (int i = sopt - 1; i >= 0; i--)
		{
			if (so[i] > p.so[i])//kt so nao lon hon( ss 2 so)
			{
				soam = false;
				p.soam = false;
				kq.soam = false;
				break;
			}
			else if (so[i] < p.so[i])
			{
				soam = true;
				p.soam = true;
				kq.soam = true;
				break;
			}
		}
		//phép trừ
		int vay = 0;
		if (soam)
		{
			for (int i = 0; i < sopt; i++)
			{
				if (p.so[i] < so[i])
				{
					kq.so[i] = 10 + p.so[i] - so[i] - vay;
					if (i != sopt - 1)
						vay = 1;
				}
				else
				{
					kq.so[i] = p.so[i] - so[i] - vay;
					vay = 0;
				}
			}
		}
		else
		{
			for (int i = 0; i < sopt; i++)
			{
				if (so[i] < p.so[i])
				{
					kq.so[i] = 10 + so[i] - p.so[i] - vay;
					if (i != sopt - 1)
						vay = 1;
				}
				else
				{
					kq.so[i] = so[i] - p.so[i] - vay;
					vay = 0;
				}
			}
		}


		return kq;
	}
	/////////////////////////////////////////////////////////////////////
	//Phép nhân
	/////////////////////////////////////////////////////////////////////
	solon operator *(solon p)
	{
		solon kq;
		int bac = 0;
		//////////// buoc 1 //////////
		if (sopt < p.sopt)//đổi lại 2 số để phép nhân được tối ưu hơn vì sẽ nhân số lớn với lần lượt sopt
			//( sẽ chọn số pt nhỏ hơn để nhân)
		{
			solon x;
			x.sopt = sopt;
			for (int i = 0; i < sopt; i++)
				x.so[i] = so[i];
			sopt = p.sopt;
			for (int i = 0; i < sopt; i++)
				so[i] = p.so[i];
			p.sopt = x.sopt;
			for (int i = 0; i < p.sopt; i++)
				p.so[i] = x.so[i];
		}
		bac = p.sopt;
		int x = sopt;
		solon *mang = new solon[bac];
		//mảng các số lớn --> sẽ cộng đồn vào sau các phép nhân với từng chữ số
		for (int i = 0; i < bac; i++)
		{
			mang[i].sopt = x + 1;
			for (int j = 0; j < x + 1; j++)//gán cho tất cả các mảng =0
				mang[i].so[j] = 0;
			x++;
		}
		int l = 0;//xác định xem làm với mảng nào
		for (int j = 0; j < p.sopt; j++)
		{
			int nho = 0, g = 0;
			for (int k = 0; k < sopt; k++)
			{
				mang[l].so[g + l] = (so[k] * p.so[j] + nho) % 10;
				nho = (so[k] * p.so[j] + nho) / 10;
				g++;
			}
			//hết vòng for nếu vẫn còn nhớ thì phải thêm 1 pt nữa
			if (nho != 0)
			{
				mang[l].so[g + l] = nho;
			}
			else
			{
				mang[l].sopt = g + l;
			}
			l++;
		}

		//////// can = so pt ////////////

		for (int i = 0; i < bac; i++)
		{
			int z = mang[bac - 1].sopt - mang[i].sopt;
			for (int j = 1; j <= z; j++)
			{
				mang[i].so[mang[i].sopt - 1 + j] = 0;
			}
			mang[i].sopt = mang[bac - 1].sopt;
		}
		kq.sopt = mang[bac - 1].sopt + 1;
		int nhokq = 0;
		//phép cộng tất cả các số trong mảng vào
		for (int i = 0; i < mang[bac - 1].sopt; i++)
		{
			int w = 0;
			for (int j = 0; j < bac; j++)
			{
				w += mang[j].so[i];
			}
			kq.so[i] = (w + nhokq) % 10;
			nhokq = (w + nhokq) / 10;
		}
		if (nhokq != 0)
		{
			kq.so[mang[bac - 1].sopt] = nhokq;
		}
		else
			kq.sopt = mang[bac - 1].sopt;
		return kq;
	}

	////////////////////////////////////////////////////////////////////
	//Phép chia
	////////////////////////////////////////////////////////////////////
	solon operator /(solon p)
	{
		solon kq;

	


	}
};
ostream &operator <<(ostream &out, solon &p)
{
	out << "Ket qua la: ";
	if (p.soam)
	{
		int x = 0;
		out << "-";
		for (int i = p.sopt - 1; i >= 0; i--)
		{
			if (p.so[i] != 0)
			{
				x = i;
				break;
			}
		}
		for (int i = x; i >= 0; i--)
			out << p.so[i];
		out << "\n";
	}
	else
	{
		for (int i = p.sopt - 1; i >= 0; i--)
			out << p.so[i];
		out << "\n";
	}
	return out;
}
istream &operator >>(istream &cn, solon &p)
{
	char a[100];
	cout << "nhap so lon: ";
	gets_s(a);
	p.sopt = strlen(a);
	p.ChuyenSo(p.so, a);
	return cn;
}
void main()
{
	solon p, p1, p2;
	cin >> p1;
	cin >> p2;
	p = p1 + p2;
	cout << "ket qua cong: " << p;
	p = p1 - p2;
	cout << "ket qua tru: " << p;
	p = p1 * p2;
	cout << "ket qua nhan: " << p;
	//getch();
}
