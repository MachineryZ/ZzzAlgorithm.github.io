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



int main()
{
	int N;
	cin >> N;
	while(N > 0)
	{
		N--;
		int price, year;
		int n;
		cin >> price >> year;
		cin >> n;
		vector<vector<int> > bonds(n, vector<int>(2,0));
		for(int i = 0; i < n; i++)
			cin >> bonds[i][0] >> bonds[i][1];
		vector<int> dp;
		while(year > 0)
		{
			dp.resize(price/1000+1, 0);
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j <= price/1000 - bonds[i][0]/1000; j += 1)
				{
					dp[j + bonds[i][0]/1000] = max(dp[j + bonds[i][0]/1000], dp[j] + bonds[i][1]);
				}
			}
			//cout << price << endl;
			price += dp[price/1000];
			year--;
		}
		cout << price << endl;
	}
	return 0;
}
















