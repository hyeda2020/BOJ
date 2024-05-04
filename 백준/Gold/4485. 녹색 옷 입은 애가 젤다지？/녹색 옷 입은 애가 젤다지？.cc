/* 다익스트라 알고리즘 복습 */
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int Drow[4] = { 0, -1, 0, 1 };
int Dcol[4] = { -1, 0, 1, 0 };

int Cave[125][125];
int DP[125][125];
bool bVisited[125][125];

int Dijkstra(int n)
{
    priority_queue<
        pair<int, pair<int, int>>,  // { val, { r, c } }
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > PQ;
    
    DP[0][0] = Cave[0][0];
    PQ.push({ DP[0][0], { 0, 0 } });
    bVisited[0][0] = true;
    
    int r, c, nr, nc;
    while (!PQ.empty())
    {
        r = PQ.top().second.first;
        c = PQ.top().second.second;
        PQ.pop();
        
        for (int i = 0; i < 4; i++)
        {
            nr = r + Drow[i];
            nc = c + Dcol[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            {
                continue;
            }
            if (!bVisited[nr][nc]) 
            {
                bVisited[nr][nc] = true;
                DP[nr][nc] = DP[r][c] + Cave[nr][nc];
                PQ.push({ DP[nr][nc], { nr, nc } });
            }
            else
            {
                if (DP[nr][nc] > DP[r][c] + Cave[nr][nc])
                {
                    DP[nr][nc] = DP[r][c] + Cave[nr][nc];
                    PQ.push({ DP[nr][nc], { nr, nc } });
                }
            }
        }
    }
    return DP[n - 1][n - 1];
}

int main()
{
    int N = 0;
    int tcase = 1;
    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Cave[i][j];
            }
        }
        
        cout << "Problem " << tcase << ": " << Dijkstra(N) << '\n';
        memset(bVisited, 0, sizeof(bVisited));
        tcase++;
    }
    return 0;
}
