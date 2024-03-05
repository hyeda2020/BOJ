#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T, N, K, X, Y, W;
bool graph[1001][1001];
int indegree[1001];

int cost[1001];
int DP[1001];

void TopologiSort()
{
    queue<int> Q;

    /* indegree가 0인 정점들을 먼저 큐에 삽입 */
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
            DP[i] = cost[i];
        }
    }

    int cur;
    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (graph[cur][i])
            {
                if (--indegree[i] == 0)    Q.push(i);   // 인접한 정점들의 indegree를 하나씩 지우고, indegree가 0인 정점은 큐에 삽입
                DP[i] = max(DP[i], DP[cur] + cost[i]);  // 인접한 정점에 대해 DP값 갱신
            }
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
        {
            cin >> cost[i];
        }

        while (K--)
        {
            cin >> X >> Y;
            graph[X][Y] = 1;
            indegree[Y]++;
        }

        cin >> W;   // 최종 건물 번호

        TopologiSort();
        cout << DP[W] << '\n';

        /* 초기화 */
        memset(DP, 0, sizeof(DP));
        memset(graph, 0, sizeof(graph));
        memset(indegree, 0, sizeof(indegree));
    }
    return 0;
}