#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Passenger.h"
class Elevator
{
public:
	Elevator(int maxfloor) :maxfloor(maxfloor), position(1), man(0), sum(0), a(), wait(0), time(0), tot(0)/*,person()*/ {}
	int maxfloor;
	int position;// 电梯位置
	//std::vector <int> person;  // 电梯中去往 i 楼层的人数 person[i];
	int person[Maxfloor + 1];
	int tot; //电梯位置 人数 方向0代表停 1代表向下 2 代表向上
	std::string s; // 记录电梯运作的字符串0代表停 1代表向下 2 代表向上
	std::vector<Passenger> per;
	int man; // 当前指向第几个人
	int sum; // 等待时间总和
	int a[Maxfloor + 1][Maxfloor + 1];  // 乘客在i楼去往j楼 的人数 
	int max1; // dfs 的最小值
	int time; // 当前时间
	int wait; // 电梯外等待人数
	int n; 
	std::string s1, s4; // 中途记录 字符串
	
	void dispatch(int t, std::string s1, int &wait);
	void scin();  // 读入
	void search();     // 查找
	void dfs(int po, std::string s, int ans, int wait, int tot);// 搜索比对 最优策略
};