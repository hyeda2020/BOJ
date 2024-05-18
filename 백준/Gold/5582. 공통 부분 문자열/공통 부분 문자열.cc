#include <iostream>
#include <string>
using namespace std;

int DP[4001][4001];
/*
LCS 배열
 
    A A A
 B  0 0 0
 A  1 1 1
 A  1 2 2
 
 */

int main()
{
    string str1, str2;
    
    cin >> str1 >> str2;
    
    int answer = 0;
    
    for (int i = 0; i < static_cast<int>(str1.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(str2.size()); j++)
        {
            if (str1[i] == str2[j]) // 두 문자열이 같다면 DP배열의 현재 위치 대각선 위쪽 값 + 1
            {
                DP[i + 1][j + 1] = DP[i][j] + 1;
            }
            answer = max(answer, DP[i + 1][j + 1]);
        }
    }
    
    cout << answer << '\n';
    return 0;
}