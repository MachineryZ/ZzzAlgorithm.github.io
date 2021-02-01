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
	int T;
	cin >> T;
	while(T > 0)
	{
		T--;
		int E, P;
		int n;
		cin >> E >> P;
		cin >> n;
		vector<vector<int> > coins(n, vector<int>(2, 0));
		// value and weight
		for(int i = 0; i < n; i++)
			cin >> coins[i][0] >> coins[i][1];
		vector<int> dp(P-E+1, INT_MAX/2);
		dp[0] = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= P-E-coins[i][1]; j++)
			{
				dp[j+coins[i][1]] = min(dp[j+coins[i][1]], dp[j] + coins[i][0]);
			}
		}
		if(dp[P-E] != INT_MAX/2)
			cout << "The minimum amount of money in the piggy-bank is " << dp[P-E] << "." << endl;
		else
			cout << "This is impossible." << endl;
 	}
	
	return 0;
}
















