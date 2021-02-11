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
vector<int> Rank;

int find(int idx)
{
	if (parent[idx] == idx)
		return idx;
	Rank[idx] = (Rank[idx] + Rank[find(parent[idx])]) % 3;
	return parent[idx] = find(parent[idx]);
}

bool merge(int x, int y, int type)
{
	int px = find(x);
	int py = find(y);
	if(px == py)
	{
		if((Rank[y] - Rank[x] + 3) % 3 != type)
			return true;
		return false;
	}
	else
	{
		parent[py] = px;
		Rank[py] = (Rank[x] - Rank[y] + type + 3) % 3;
	}
	return false;
}

int main()
{
	int N, K;
	cin >> N >> K;
	// Initializationo
	parent.resize(N);
	Rank.resize(N);
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
		Rank[i] = 0;
	}
	int cnt = 0;
	while (K--)
	{
		int type, X, Y;
		cin >> type >> X >> Y;
		if (X > N || Y > N || (type == 2 && X == Y))
			cnt++;
		if(merge(X, Y, type - 1) == true)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
