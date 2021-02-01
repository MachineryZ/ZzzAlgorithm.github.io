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
	vector<int> dp(N+1, 0);
	vector<int> two;
	dp[0] = 1;
	int t = 1;
	while(t <= N)
	{
		two.push_back(t);
		t = t << 1;
	}
	for(int i = 0; i < int(two.size()); i++)
		for(int j = 0; j <= N - two[i]; j++)
			dp[j + two[i]] = (dp[j + two[i]] +  dp[j])%1000000000;
	cout << dp[N] << endl;
	return 0;
}
















