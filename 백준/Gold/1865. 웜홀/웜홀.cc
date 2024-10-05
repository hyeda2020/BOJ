#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> EdgesVec; // { src, dest, cost }
int Dist[501];
int TC, N, M, W;

bool BellmanFord(int n, int m)
{
    bool bNegativeCycle = false;
    
    /*
        모든 정점들이 서로 연결되어있다는 보장이 되어있지 않으므로,
        기존 벨만-포드 알고리즘처럼 if(Dist[src] != MAX_INT) 이런 조건을 넣으면
        음의 싸이클이 있는 서브그래프에 도달이 불가능하여, YES인 경우에도 NO라는 결과를 리턴하게 될 수 있음.
     */
    int src, dest, cost;
    for (int v = 1; v <= n - 1; v++)
    {
        for (size_t e = 0; e < EdgesVec.size(); e++)
        {
            src = get<0>(EdgesVec[e]);
            dest = get<1>(EdgesVec[e]);
            cost = get<2>(EdgesVec[e]);
            
            Dist[dest] = min(Dist[dest], Dist[src] + cost);
        }
    }
    
    // 음수 사이클이 있는지 체크
    for (size_t e = 0; e < EdgesVec.size(); e++)
    {
        src = get<0>(EdgesVec[e]);
        dest = get<1>(EdgesVec[e]);
        cost = get<2>(EdgesVec[e]);
        
        if (Dist[dest] > Dist[src] + cost)
        {
            bNegativeCycle = true;
            break;
        }
    }
    
    return bNegativeCycle;
}

int main()
{
    cin >> TC;
    
    int S, E, T;
    for (int i = 0; i < TC; i++)
    {
        cin >> N >> M >> W;
        for (int j = 0; j < M; j++)
        {
            cin >> S >> E >> T;
            EdgesVec.push_back({ S, E, T });
            EdgesVec.push_back({ E, S, T });
        }
        for (int j = 0; j < W; j++)
        {
            cin >> S >> E >> T;
            EdgesVec.push_back({ S, E, -1 * T });
        }
        
        if (BellmanFord(N, M))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
        
        EdgesVec.clear();
    }
    
    return 0;
}
