#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;

int Drow[4] = { 0, -1, 0, 1 };
int Dcol[4] = { -1, 0, 1, 0 };

int N, M;
int Country[11][11];
bool bVisited[11][11];

int Graph[7][7];
bool bVisitedForPrim[7];

void GetNumByDFS(int r, int c, int num)
{
    Country[r][c] = num;
    bVisited[r][c] = true;
    
    int nr, nc;
    for (int i = 0; i < 4; i++)
    {
        nr = r + Drow[i];
        nc = c + Dcol[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
        {
            continue;
        }
        if (Country[nr][nc] && !bVisited[nr][nc])
        {
            GetNumByDFS(nr, nc, num);
        }
    }
}

int Prim(int num)
{
    priority_queue<
        pair<int, int>,     // { cost, dest }
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > PQ;
    
    PQ.push({ 0, 1 });
    
    int cur, cost;
    int ret = 0;
    while (!PQ.empty())
    {
        cur = PQ.top().second;
        cost = PQ.top().first;
        PQ.pop();
        
        if (bVisitedForPrim[cur])
        {
            continue;
        }
        
        bVisitedForPrim[cur] = true;
        ret += cost;
        
        for (int next = 1; next <= num; next++)
        {
            if (cur != next && Graph[cur][next] != INT_MAX)
            {
                PQ.push({ Graph[cur][next], next });
            }
        }
    }
    return ret;
}

void MakeMinRoad(int r, int c, int dir)
{
    int cur = Country[r][c];
    int next = cur;
    int dist = -1;
    int nr, nc;
    
    while (true)
    {
        nr = r + Drow[dir];
        nc = c + Dcol[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || Country[nr][nc] == cur)
        {
            dist = -1;
            break;
        }
        
        dist++;
        if (Country[nr][nc])
        {
            next = Country[nr][nc];
            break;
        }
        
        r = nr;
        c = nc;
    }
    
    if (dist > 1)
    {
        Graph[cur][next] = min(dist, Graph[cur][next]);
        Graph[next][cur] = Graph[cur][next]; // 양방향 그래프
    }
}

int main()
{
    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            cin >> Country[r][c];
        }
    }
    
    /* 각 섬들에 번호 부여 */
    int num = 0;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (Country[r][c] && !bVisited[r][c])
            {
                GetNumByDFS(r, c, ++num);
            }
        }
    }
    
    /* 그래프 초기화 */
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            Graph[i][j] = INT_MAX;
        }
    }
    
    /* 섬들사이 도로 연결 */
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (Country[r][c])
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    MakeMinRoad(r, c, dir);
                }
            }
        }
    }
    
    /* Minimum Spanning Tree 구현 */
    int answer = Prim(num);
    
    /* 모든 섬을 연결할 수 있는지 체크 */
    for (int i = 1; i <= num; i++ )
    {
        if (!bVisitedForPrim[i])
        {
            answer = -1;
            break;
        }
    }
    
    cout << answer << '\n';
    return 0;
}