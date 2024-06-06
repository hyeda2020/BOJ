#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <cstring>
using namespace std;

bool bErasePairTgtNum[11];
bool bEraseInputPos[201];

int main()
{
    string input;
    cin >> input;
    
    stack<char> stk;
    map<int, pair<int, int>> pairPosMap;
    
    int num = 0;
    for (int i = (int)input.size() - 1; i >= 0; i--)
    {
        if (input[i] == ')')
        {
            stk.push(i);
        }
        else if (input[i] == '(')
        {
            pairPosMap.insert({ num++, { i, stk.top() }});
            stk.pop();
        }
    }
    
    set<string> answer;
    for (int i = num - 1; i >= 0; i--)
    {
        bErasePairTgtNum[i] = true;
        do {
            for (int j = 0; j < num; j++)
            {
                if (bErasePairTgtNum[j])
                {
                    bEraseInputPos[pairPosMap[j].first] = true;
                    bEraseInputPos[pairPosMap[j].second] = true;
                }
            }
            
            /* 괄호쌍 제외하고 삽입 */
            string tmp;
            for (int j = 0; j < (int)input.size(); j++)
            {
                if (!bEraseInputPos[j])
                {
                    tmp += input[j];
                }
            }
            answer.insert(tmp);
            memset(bEraseInputPos, 0, sizeof(bEraseInputPos));
        } while (next_permutation(bErasePairTgtNum, bErasePairTgtNum + num));
    }
    
    for (auto iter : answer)
    {
        cout << iter << '\n';
    }
    return 0;
}