
#include "Elevator.h"
void Elevator::dispatch(int t,std::string str,int &wait)
{
	int j = 0, n = str.size(), t1, s1;
	for (int i = time; i < t&& j < n; i++, j++)
	{
		t1 = 0; s1 = 0;
		if (str[j] == '2')
		{
			t1 = person[position];
			person[position] = 0;

			for (int k = 1; k <= Maxfloor; k++) person[k] += a[position][k], a[position][k] = 0;
			s1 = a[position][0];
			a[position][0] = 0;
			wait -= s1;
			tot = tot + s1 - t1;
			//printf_s("%d 时，停靠在%d楼: 进电梯  %d人，出电梯 %d人。\n", i , position- 1, s1, t1);
			std::cout << i << ' ' << position - 1 << std::endl;
		}
		else
		{
			if (str[j] == '1') position++;
			else position--;
		}
		sum += wait + tot;
		s4 += str[j];
	}
	time = t;
}


void Elevator::scin()
{
	Passenger l;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> l;
	    l.position++, l.destination++;
		per.push_back(l);
	}
	l.time = per[n - 1].time + 200;
	per.push_back(l);
	std::sort(per.begin(), per.end(), cmp);
	time = per[0].time;
	search();
}
void Elevator::search()
{
	while (man < n )
	{
		int k = man;
		while (time >= per[man].time)
		{
			a[per[man].position][per[man].destination]++;
			a[per[man].position][0]++;
			man++;
		}
		int t = per[man].time;
		std::string s;
		max1 = 0xfffff; wait += man - k;
		dfs(position, s, 0, wait, tot);
		//std::cout << s1 << std::endl;
		dispatch(t, s1, wait);
	}
}

void Elevator::dfs(int po, std::string s, int ans, int wait, int tot)
{
	int i;
	if (!tot && !wait)
	{
		if (ans < max1)
		{
			s1 = s;
			max1 = ans;
		}
	}
	else
	{
		for (i = 1; i <= Maxfloor; i++)              // 去i 楼载乘客入电梯
			if (a[i][0]>0 || person[i]>0)
			{
				char c;

				if (po == i) c = '2';
				else   c = (i < po) ? '0' : '1';
				int t = abs(i - po), o[Maxfloor + 1], t1 = a[i][0], t2 = person[i];
				std::string s2(t, c);
				memcpy(o, a[i], sizeof(a[i]));
				a[i][0] = 0; person[i] = 0;
				for (int j = 1; j <= Maxfloor; j++) person[j] += a[i][j], a[i][j] = 0;

				dfs(i, s + s2 + '2', ans + (t + 1)*(wait + tot) - t2, wait - t1, tot + t1 - t2);

				memcpy(a[i], o, sizeof(o));
				a[i][0] = t1;
				person[i] = t2;
				for (int j = 1; j <= Maxfloor; j++) person[j] -= a[i][j];
			}
	}
}
