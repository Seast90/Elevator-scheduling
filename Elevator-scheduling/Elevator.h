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
	int position;// ����λ��
	//std::vector <int> person;  // ������ȥ�� i ¥������� person[i];
	int person[Maxfloor + 1];
	int tot; //����λ�� ���� ����0����ͣ 1�������� 2 ��������
	std::string s; // ��¼�����������ַ���0����ͣ 1�������� 2 ��������
	std::vector<Passenger> per;
	int man; // ��ǰָ��ڼ�����
	int sum; // �ȴ�ʱ���ܺ�
	int a[Maxfloor + 1][Maxfloor + 1];  // �˿���i¥ȥ��j¥ ������ 
	int max1; // dfs ����Сֵ
	int time; // ��ǰʱ��
	int wait; // ������ȴ�����
	int n; 
	std::string s1, s4; // ��;��¼ �ַ���
	
	void dispatch(int t, std::string s1, int &wait);
	void scin();  // ����
	void search();     // ����
	void dfs(int po, std::string s, int ans, int wait, int tot);// �����ȶ� ���Ų���
};