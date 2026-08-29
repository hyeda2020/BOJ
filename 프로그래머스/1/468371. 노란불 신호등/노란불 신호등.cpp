#include <string>
#include <vector>

using namespace std;

int LightCycle[5];

// 최대공약수
int GCD(int a, int b)
{
    while(b)
    {
        int t = a % b;
        a = b;
        b = t;
    }

    return a;
}

// 최소공배수
int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int solution(vector<vector<int>> signals) 
{
    int answer = -1;
    int limit = 1;
    
    int sum;
    int lightCycle;
    for (vector<int> vec : signals)
    {
        sum = vec[0] + vec[1] + vec[2];
        limit = LCM(limit, sum);
    }
    
    // 각 신호등의 주기 계산
    for (int l = 0; l < (int)signals.size(); l++)
    {
        LightCycle[l] = signals[l][0] + signals[l][1] + signals[l][2];

    }
    
    for (int s = 1; s <= limit; s++)
    {
        bool yellow = true;
        
        for (int l = 0; l < (int)signals.size(); l++)
        {
            int cur = (s - signals[l][0]) % LightCycle[l];
            if (cur > 0 && cur <= signals[l][1])
            {
                continue;
            }
            
            yellow = false;
        }
        
        if (yellow)
        {
            answer = s;
            break;
        }
    }
    
    return answer;
}