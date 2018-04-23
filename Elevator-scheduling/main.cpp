#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Passenger.h"
#include "Elevator.h"

using namespace std;

Elevator Ele(Maxfloor);


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	Ele.scin();
	
	//	cout << "×ÜºÄÊ±£º " << sum << endl << s4 << endl;
	fclose(stdin);
	fclose(stdout);
	//system("pause");
	return 0;
}