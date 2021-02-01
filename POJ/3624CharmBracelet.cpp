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
	int N, W;
	cin >> N >> W;

	vector<int> w(N, 0);
	vector<int> v(N, 0);
	vector<int> dp(W, 0);

	for(int i = 0; i < N; i++)
		cin >> w[i] >> v[i];

	for(int i = 0; i < N; i++)
		for(int j = W; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
	cout << dp[W] << endl;
	return 0;
}

























