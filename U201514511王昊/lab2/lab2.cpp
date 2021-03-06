// lab2.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;


string removeprezero(string x)//去除字符串的无意义高位0
{
	while (x[0] == '0')
	{
		x.erase(0, 1);
	}
	if (x.size() == 0)	x = "0";
	return x;
}

void makeequel(string &sx, string&sy)//字符串对齐操作
{
	int lx = sx.length(), ly = sy.length(), lmax;
	lmax = lx >= ly ? lx : ly;
	if (lmax % 2 == 1)
	{
		lmax++;
		sx.insert(0, "0");
		sy.insert(0, "0");
	}
	if (lx != ly)
	{
		if (lx > ly)
		{
			for (int i = 0; i < lx - ly; i++)sy.insert(0, "0");
		}
		if (lx < ly)
		{
			for (int i = 0; i < ly - lx; i++)sx.insert(0, "0");
		}
	}
}

string add(string x, string y)//无符号对其加法
{

	string z = "";
	int lmax = x.length(),tag=0;
	for (int i = lmax - 1; i >= 0; i--)
	{
		z.insert(0,1,(x[i] - '0' + y[i] - '0' + tag)%10+'0');
		tag = (x[i] - '0' + y[i] - '0' + tag) / 10;
	}
	if (tag)	z.insert(0, 1, tag + '0');
	if (z.size() == 0)	z = "0";
	return z;
}

string sub(string x, string y)//无符号对齐减法
{
	string z = "";
	int lmax = x.length(),tag = 0;
	for (int i = lmax - 1; i >= 0; i--)
	{
		z.insert(0, 1, (x[i]  - y[i]  +10 + tag) % 10 + '0');
		if (x[i] - y[i] + tag < 0) tag = -1;
		else tag = 0;
	}
	if (tag!=0)	z.insert(0, 1, tag+10 + '0');
	if (z.size() == 0)	z = "0";
	return z;
}

string addstr(string sx, string sy)//字符串加法
{
	string strresult;
	if (sx[0] == '-'&&sy[0] == '-')
	{
		makeequel(sx, sy);
		strresult=add(sx, sy);
		strresult = removeprezero(strresult);
		strresult.insert(0, 1, '-');
	}
	else
	{	
		if (sx[0] == '-')
		{
			sx.erase(0, 1);
			makeequel(sx, sy);
			if (sx > sy)
			{
				strresult=sub(sx, sy);
				strresult = removeprezero(strresult);
				strresult.insert(0, 1, '-');
			}
			else
			{
				strresult=sub(sy, sx);
				strresult = removeprezero(strresult);
			}
		}
		else
		{
			if (sy[0] == '-')
			{
				sy.erase(0, 1);
				makeequel(sx, sy);
				if (sx > sy)
				{
					strresult=sub(sx, sy);
					strresult = removeprezero(strresult);
					
				}
				else
				{
					strresult=sub(sy,sx);
					strresult = removeprezero(strresult);
					strresult.insert(0, 1, '-');
				}
			}
			else
			{
				makeequel(sx, sy);
				strresult=add(sx, sy);
				strresult = removeprezero(strresult);
			}
		}
	}
	return strresult;
}

string substr(string sx, string sy)//字符串减法
{
	string strresult;
	if (sx[0] == '-'&&sy[0] == '-')
	{
		sx.erase(0,1);
		sy.erase(0,1);
		makeequel(sx, sy);
		if (sx > sy)
		{
			strresult=sub(sx, sy);
			strresult = removeprezero(strresult);
			strresult.insert(0, 1, '-');
		}
		else
		{
			strresult=sub(sy, sx);
			strresult = removeprezero(strresult);
		}
	}
	else
	{
		if (sx[0] == '-')
		{
			sx.erase(0, 1);
			makeequel(sx, sy);
			strresult=add(sx, sy);
			strresult = removeprezero(strresult);
			strresult.insert(0, 1, '-');
		}
		else
		{
			if (sy[0] == '-')
			{
				sy.erase(0, 1);
				makeequel(sx, sy);
				strresult=add(sx, sy);
				strresult = removeprezero(strresult);
			}
			else
			{
				makeequel(sx, sy);
				if (sx > sy)
				{
					strresult=sub(sx, sy);
					strresult = removeprezero(strresult);
				}
				else
				{
					strresult=sub(sy, sx);
					strresult = removeprezero(strresult);
					strresult.insert(0, 1, '-');
				}
			}
		}
	}
	return strresult;
}


string multi(string x, string y)//字符串乘法
{
	int tag;
	string sx = x,sy=y;
	if (sx[0] == '-'&&sy[0] == '-')
	{
		sx.erase(0,1);
		sy.erase(0,1);
		tag = 1;
	}
	else
	{
		if (sx[0] == '-')
		{
			sx.erase(0, 1);
			tag = 0;
		}
		else
		{
			if (sy[0] == '-')
			{
				sy.erase(0, 1);
				tag = 0;
			}
			else
			{
				tag = 1;
			}
		}

	}
	makeequel(sx, sy);
	int n = sx.size();
	string result, A, B, C, D;
	if (n > 1)
	{
		A = sx.substr(0, n / 2);
		B = sx.substr(n / 2, n);
		if (A == "0"&&B == "0")
		{
			result.insert(0, 1, '0');
			return result;
		}
		C = sy.substr(0, n / 2);
		D = sy.substr(n / 2, n);
		if (C == "0"&&D == "0")
		{
			result.insert(0, 1, '0');
			return result;
		}

	}
	if (n == 2)
	{
		int a = stoi(A);
		int b = stoi(B);
		int c = stoi(C);
		int d = stoi(D);
		int reint = (a * 10 + b)*(c * 10 + d);
		while (reint)
		{
			int i = reint % 10;
			result.insert(0, 1, i + '0');
			reint = reint / 10;
		}
	}
	else
	{
		string AC = multi(A, C);
		string BD = multi(B, D);
		string AandB = addstr(A, B);
		string CandD = addstr(C, D);
		string ABandCD = addstr(AC, BD);
		string AaBCaD= multi(AandB, CandD);
		string mid = substr(AaBCaD, ABandCD);
		for (int i = 1; i <= n / 2; i++) mid = mid + "0";
		for (int i = 1; i <= n; i++) AC = AC + "0";
		result = addstr(addstr(AC, BD), mid);
	}
	if (result[0] == '-')
	{
		result.erase(0, 1);
	}
	if (tag == 0) result.insert(0, "-");
	return result;
}

int main()
{
	char *charresult;
	string strresult,sx,sy;
	cout << "enter X\n";
	cin >> sx;
	cout << "enter Y\n";
	cin >> sy;
	strresult = addstr(sx, sy);
	charresult = (char*)strresult.c_str();
	cout <<"X + Y = " <<charresult <<"\n";
	strresult = substr(sx, sy);
	charresult = (char*)strresult.c_str();
	cout <<"X - Y = "<< charresult << "\n";
	strresult = multi(sx, sy);
	charresult = (char*)strresult.c_str();
	cout << "X * Y = "<<charresult << "\n";
	getchar();
	getchar();
    return 0;
}

