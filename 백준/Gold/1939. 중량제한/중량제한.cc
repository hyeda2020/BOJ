#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<int> Edge;
vector<pair<int, int>> Graph[10001]; // cost, dest;
bool bVisited[10001];

bool bfs(int src, int dest, int weight, int N)
{
    queue<int> Q;
    memset(bVisited, 0, sizeof(bVisited));

    Q.push(src);
    bVisited[src] = 1;

    int cur, next, cost;
    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        
        if (cur == dest)    return true;

        for (size_t i = 0; i < Graph[cur].size(); i++)
        {
            next = Graph[cur][i].second;
            cost = Graph[cur][i].first;

            if (!bVisited[next] && cost >= weight)
            {
                bVisited[next] = 1;
                Q.push(next);
            }
        }
    }
    return false;
}

int solution(int src, int dest, int N)
{
    int ret = 0;
    sort(Edge.begin(), Edge.end());

    int left = 0, right = (int)Edge.size() - 1;
    int mid, weight;

    while (left <= right)
    {
        mid = (left + right) / 2;
        weight = Edge[mid];
        if (bfs(src, dest, weight, N))
        {
            ret = weight;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ret;
}

int main()
{
    int N, M, A, B, C, src, dest;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        Graph[A].push_back({ C, B });
        Graph[B].push_back({ C, A });
        Edge.push_back(C);
    }
    cin >> src >> dest;

    cout << solution(src, dest, N) << '\n';
    return 0;
}
