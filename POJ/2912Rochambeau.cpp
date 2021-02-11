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
vector<int> r;
int find(int x)
{
    if(parent[x] == x)
        return x;
    r[x] = (r[x] + r[find(parent[x])]) % 3;
    return parent[x] = find(parent[x]);
}


int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> candi;
        parent.resize(n, 0);
        r.resize(n, 0);
        for (int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            int j = 0;
            for (j = 0; j < s.size(); j++)
                if (s[j] == '<' || s[j] == '=' || s[j] == '>')
                    break;
            int a = stoi(s.substr(0, j - 1)), b = stoi(s.substr(j + 1));
            if (s[j] == '<')
            {
                if(merge(a, b, 1) == false)
                {
                    
                }
                
            }
            else if (s[i] == '=')
            {
            }
            else if (s[i] == '>')
            {
            }
        }
    }
    return 0;
}