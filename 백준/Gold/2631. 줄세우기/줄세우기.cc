/* 문제 풀이 참고 : https://yabmoons.tistory.com/197 */
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ChildOrder[201];
int DP[201];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ChildOrder[i];
        DP[i] = 1;
    }
    
    /* 가장 긴 증가하는 부분수열을 구함 */
    int longestIncreSubSeqSize = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ChildOrder[j] < ChildOrder[i])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        longestIncreSubSeqSize = max(DP[i], longestIncreSubSeqSize);
    }
    
    /* 주어진 수열 크기에서 가장 큰 증가하는 부분수열의 크기만큼을 빼줌 */
    cout << N - longestIncreSubSeqSize << '\n';
    return 0;
}
