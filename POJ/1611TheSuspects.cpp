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
	int n, m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		parent.resize(n, 0);
		for(int i = 0; i < n; i++)
			parent[i] = i;
		for(int i = 0; i < m; i++)
		{
			int num;
			int a;
			cin >> num >> a;
			num--;
			while(num--)
			{
				int b;
				cin >> b;
				unionSet(a, b);
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if(i == 0 || find(i) == 0)
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}
















