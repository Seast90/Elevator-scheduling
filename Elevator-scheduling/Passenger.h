#pragma once
#include <iostream>
#include <string>
const int  Maxfloor = 3;



class Passenger
{
public:
	int time;      // 发出请求时间
	int position;  // 初始位置
	int destination; // 目的地
	friend std::istream &operator>> (std::istream &is, Passenger &qwe);// 重载>>运算符
};
bool cmp(Passenger a, Passenger b);
