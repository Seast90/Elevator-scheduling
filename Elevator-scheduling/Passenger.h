#pragma once
#include <iostream>
#include <string>
const int  Maxfloor = 3;



class Passenger
{
public:
	int time;      // ��������ʱ��
	int position;  // ��ʼλ��
	int destination; // Ŀ�ĵ�
	friend std::istream &operator>> (std::istream &is, Passenger &qwe);// ����>>�����
};
bool cmp(Passenger a, Passenger b);
