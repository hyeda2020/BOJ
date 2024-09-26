#include <string>
#include <vector>
#include <cmath>
using namespace std;

int Drow[4] = { 1, 0, 0, -1 };
int Dcol[4] = { 0, -1, 1, 0 };
char Dir[4] = { 'd', 'l', 'r', 'u' };

int N, M, K;
string answer = "impossible";
pair<int, int> Dest;
bool bArrived = false;

int GetDist(pair<int, int>& cur)
{
    return abs(Dest.first - cur.first) + abs(Dest.second - cur.second);
}

void DFS(pair<int, int> cur, int cnt, string path)
{
    if (bArrived)
    {
        return;
    }
    
    int dist = GetDist(cur);
    if (K - cnt - dist < 0) 
    {
        return;
    } 
    if ((K - cnt - dist) % 2 == 1) 
    {
        return;
    }
    
    if (cnt == K && cur == Dest)
    {
        bArrived = true;
        answer = path;
        return;
    }
    
    int nr, nc;
    for(int i = 0; i < 4; ++i)
    {
        nr = cur.first + Drow[i];
        nc = cur.second + Dcol[i];
        
        if(nr < 1 || nr > N || nc < 1 || nc > M)
        {
            continue;
        }
            
        path += Dir[i];
        DFS({ nr, nc }, cnt + 1, path);
        path.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    N = n;
    M = m;
    K = k;
    Dest = { r, c };
    
    DFS({ x, y }, 0, "");
    
    return answer;
}