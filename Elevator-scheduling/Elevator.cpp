#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define N 5
using namespace std;
int sum = 0, a[15][15] = { 0 }, max1, time = 0, wait = 0; // ʱ���ܺ� ��ͬ¥��ȴ�����
string s1, s4;
class node
{
public:
	int time, pos, des; // ʱ�䣬λ�ã�Ŀ�ĵ�
	friend istream &operator>> (istream &is, node &qwe);// ����>>�����
}per[100];
istream &operator>> (istream &is, node &qwe)
{
	is >> qwe.time >> qwe.pos >> qwe.des;
	if (!is)qwe = node();
	return is;
}
struct qwe
{
	int pos, ans[11], tot; //����λ�� ���� ����0����ͣ 1�������� 2 ��������
}Ele;
bool cmp(node a, node b)
{
	return (a.time < b.time);
}
void Eleva(int t, string s, int &pos, int &wait, int &tot)
{
	int j = 0, n = s.size(), t1, s1;
	for (int i = time; i < t&& j < n; i++, j++)
	{
		t1 = 0; s1 = 0;
		if (s[j] == '2')
		{
			t1 = Ele.ans[pos]; 
			Ele.ans[pos] = 0;
            
			for (int k = 1; k <= 10; k++) Ele.ans[k] += a[pos][k], a[pos][k] = 0;
			s1 = a[pos][0];
			a[pos][0] = 0;
			wait -= s1;
			tot = tot + s1 - t1;
			printf("%d ʱ��ͣ����%d¥: ������  %d�ˣ������� %d�ˡ�\n", i, pos, s1, t1);
		}
		else
		{
			if (s[j] == '1') pos++;
			else pos--;
		}
		sum += wait + tot;
		s4 += s[j];
	}
	time = t;
}
void dfs(int po, string s,int ans,int wait,int tot) //�����ֱ��������λ��  ������������ 
{                                                             // �ܺ�ʱ ������ȴ�����
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
		for (i = 1; i <= 10; i++)              // ȥi ¥�س˿������
			if (a[i][0]>0 || Ele.ans[i]>0)
			{
				char c;
				
				if (po == i) c = '2';
				else   c = (i < po) ? '0' : '1';
				int t = abs(i - po), o[15], t1 = a[i][0], t2 = Ele.ans[i];
				string s2(t, c);
				memcpy(o, a[i], sizeof(a[i]));
				a[i][0] = 0; Ele.ans[i] = 0;
				for (int j = 1; j <= 10; j++) Ele.ans[j] += a[i][j],  a[i][j] = 0;
				
				dfs(i, s + s2 + '2', ans + (t + 1)*(wait + tot) - t2, wait - t1, tot + t1 - t2);
				
				memcpy(a[i], o, sizeof(o));
				a[i][0] = t1; 
				Ele.ans[i] = t2;
				for (int j = 1; j <= 10; j++) Ele.ans[j] -= a[i][j];
			}
	}
}
int main()
{
	int man = 1;
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	for (int i = 1; i <= N; i++) cin >> per[i];
	per[N + 1].time = per[N].time + 100;
	Ele.pos = 1;  Ele.tot = 0;
	wait = 0;
	sort(per + 1, per + 1 + N, cmp);
	time = per[1].time;

	while ( man<=N)
	{
		int k = man;
		while (time >= per[man].time)
		{
			a[per[man].pos][per[man].des]++;
			a[per[man].pos][0]++;
			man++;
		}
		int t = per[man].time;
		string s;
		max1 = 0xfffff; wait += man - k;
		dfs(Ele.pos, s, 0, wait, Ele.tot);
		Eleva(t, s1, Ele.pos, wait, Ele.tot);
	} 
	cout << "�ܺ�ʱ�� "<<sum << endl<< s4 << endl;
    fclose(stdin); 
	fclose(stdout);
	return 0;
}
