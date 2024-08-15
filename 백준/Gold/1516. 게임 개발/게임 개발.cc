#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> Graph[501]; // { dest }
int Indegree[501];
int Cost[501];
int DP[501];

void TopologicalSort()
{
    queue<int> Q;
    for (int i = 1; i <= N; i++)
    {
        if (!Indegree[i])
        {
            Q.push(i);
            DP[i] = Cost[i];
        }
    }
    
    int cur, next;
    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        
        for (int i = 0; i < (int)Graph[cur].size(); i++)
        {
            next = Graph[cur][i];
            if (--Indegree[next] == 0)
            {
                Q.push(next);
            }
            DP[next] = max(DP[next], DP[cur] + Cost[next]);
        }
    }
}
    
int main()
{
    cin >> N;
    
    int src;
    for (int i = 1; i <= N; i++)
    {
        cin >> Cost[i];
        while(true)
        {
            cin >> src;
            if (src == -1)
            {
                break;
            }
            Graph[src].push_back(i);
            Indegree[i]++;
        }
    }
  
    TopologicalSort();
    for (int i = 1; i <= N; i++)
    {
        cout << DP[i] << '\n';
    }
    return 0;
}