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
	int N, K;
	long long mod = 1E18;
	cin >> N >> K;
	vector<long long> lowdp(N+1, 0);
	vector<long long> highdp(N+1, 0);
	lowdp[0] = 1;
	for(int i = 1; i <= K; i++)
	{
		for(int j = 0; j <= N - i; j++)
		{
			highdp[j+i] = (highdp[j+i] + highdp[j]) + 
						  (lowdp[j+i] + lowdp[j]) / mod;
			lowdp[j+i] = (lowdp[j+i] + lowdp[j]) % mod;
		}
	}
	if(highdp[N] > 0)
		cout << highdp[N];
	cout << lowdp[N] << endl;
	return 0;
}
















