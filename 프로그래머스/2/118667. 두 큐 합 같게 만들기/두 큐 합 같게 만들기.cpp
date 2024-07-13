#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    int answer = 0;
    
    queue<int> Q1, Q2;
    long long sum1 = 0;
    long long sum2 = 0;
    
    for (int i = 0; i < (int)queue1.size(); i++)
    {
        Q1.push(queue1[i]);
        Q2.push(queue2[i]);
        
        sum1 += queue1[i];
        sum2 += queue2[i]; 
    }
    
    int front;
    while(true)
    {
        if (Q1.empty() || Q2.empty())
        {
            answer = -1;
            break;
        }
        if (answer > 300000)
        {
            answer = -1;
            break;
        }
        
        if (sum1 == sum2)
        {
            break;
        } 
        else if (sum1 > sum2)
        {
            // Q1 -> Q2
            front = Q1.front();
            Q1.pop();
            Q2.push(front);
            
            sum1 -= front;
            sum2 += front;
            answer++;
        } 
        else
        {
            front = Q2.front();
            Q2.pop();
            Q1.push(front);
            
            sum1 += front;
            sum2 -= front;
            answer++;
        }
    }
    
    return answer;
}