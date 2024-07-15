#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> Graph[1000001]; // dest
int InGoingCnt[1000001];
set<pair<int, int>> bVisited; // { src, dest }
/*
    정점의 개수 == 간선의 개수 -> 도넛모양
    정점의 개수 >  간선의 개수 -> 막대모양
    정점의 개수 <  간선의 개수 -> 8자모양
*/

void dfs(int cur, int& vertexCnt, int& edgeCnt)
{
    vertexCnt++;
    for (int i = 0; i < (int)Graph[cur].size(); i++)
    {
        int next = Graph[cur][i];
        edgeCnt++;
        if (!bVisited.count({ cur, next })) // 현재 경로 방문체크
        {
            bVisited.insert({ cur, next });
            dfs(next, vertexCnt, edgeCnt);
        }
    }
}

vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> answer;
    
    int vertex; // 외부 정점
    int src, dest;
    for (int i = 0; i < (int)edges.size(); i++)
    {
        src  = edges[i][0];
        dest = edges[i][1];
        Graph[src].push_back(dest);
        InGoingCnt[dest]++;
        
        // Outgoing 간선의 개수가 2개 이상이고 Ingoing 간선이 없으면 외부 정점
        if ((int)Graph[src].size() >= 2 && InGoingCnt[src] == 0) 
        {
           vertex = src;
        }
    }
    
    int eightCnt = 0;
    int dounutCnt = 0;
    int stickCnt = 0;
    for (int i = 0; i < (int)Graph[vertex].size(); i++)
    {
        int start = Graph[vertex][i];
        int vertexCnt = 0;
        int edgeCnt = 0;
        
        dfs(start, vertexCnt, edgeCnt);
        if (vertexCnt == edgeCnt)
        {
            dounutCnt++;
        } 
        else if (vertexCnt > edgeCnt)
        {
            stickCnt++;
        }
        else 
        {
            eightCnt++;
        }
    }
    
    answer = { vertex, dounutCnt, stickCnt, eightCnt };
    return answer;
}