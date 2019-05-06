// test1.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "iostream"
using namespace std;
class CBagena
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int check();
public:
	CBagena();
	CBagena(int y, int m, int d, int h, int n, int s);
	int setTime(int y, int m, int d, int h, int n, int s);
	void displayTime();
	//void addup();

};
CBagena::CBagena()
{
	year = 2019;
	month = 01;
	day = 01;
}
CBagena::CBagena(int y, int m, int d, int h, int n, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = n;
	second = s;
	/*if (check() == 1 || check() == -1)
	{
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
		cout << "�����˴������ڣ����������ó�ʼ" << endl;
	}*/
}
int CBagena::setTime(int y, int m, int d, int h, int n, int s)
{
	cin >> y >> m >> d >> h >> n >> s;
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = n;
	second = s;
	/*if (check() == 1 || check() == -1)
	{
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
		cout << "�����˴������ڣ���������1" << endl;
		return -1;
	}*/
	check();
	return 0;
}
void CBagena::displayTime()
{
	cout << year << "��" << month << "��" << day << "��" << endl << hour << "ʱ" << minute << "��" << second << "��" << endl;
}
int CBagena::check()
{
	int s, h, m;
	s = second / 60;
	second = second % 60;
	m = minute / 60;
	minute = s + minute % 60;
	h = hour / 24;
	hour = m + hour % 24;
	day = day + h;
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day %= leapYearDays[month - 1];
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day %= flatYearDays[month - 1];
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
	return 0;
}
	/*if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	if (hour > 24 || hour < 0)
		return -1;
	if (minute > 60 || minute < 0)
		return -1;
	if (second > 60 || second < 0)
		return -1;
	return 0;
}*/

int main()
{
	CBagena cm;
	cm.setTime(2019, 12,30,72, 120, 120);
	cm.displayTime();
	system("pause");
	return 0;
}