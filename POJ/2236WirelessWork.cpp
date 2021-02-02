#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> parent;

int find(int idx)
{
	if(parent[idx] == idx)
		return idx;
	return parent[idx] = find(parent[idx]);
}

void unionSet(int x, int y)
{
	int px = find(x);
	int py = find(y);
	if(px == py)
		return;
	if(px < py)
		parent[py] = px;
	else
		parent[px] = py;
	return;
}


int main()
{
	int N, d;
	cin >> N >> d;
	vector<vector<int> > coor(N+1, vector<int>(2, 0));
	vector<bool> mem(N+1, false);
	parent.resize(N+1, 0);
	for(int i = 1; i <= N; i++)
		parent[i] = i;
	for(int i = 1; i <= N; i++)
		cin >> coor[i][0] >> coor[i][1];
	vector<vector<int> > connect(N+1);
	for(int i = 1; i <= N; i++)
	{
		for(int j = i + 1; j <= N; j++)
		{
			if((coor[i][0] - coor[j][0]) * (coor[i][0] - coor[j][0]) + 
				(coor[i][1] - coor[j][1]) * (coor[i][1] - coor[j][1]) <= d*d)
			{
				connect[i].push_back(j);
				connect[j].push_back(i);
			}
		}
	}
	char s;
	int a, b;
	while(cin >> s)
	{
		int a, b;
		if(s == 'O')
		{
			cin >> a;
			mem[a] = true;
			for(int i = 0; i < connect[a].size(); i++)
			{
				if(mem[connect[a][i]] == true)
					unionSet(a, connect[a][i]);
			}
		}
		else if(s == 'S')
		{
			cin >> a >> b;
			if(find(a) == find(b))
				cout << "SUCCESS" << endl;
			else
				cout << "FAIL" << endl;
		}
	}
	return 0;
}
















