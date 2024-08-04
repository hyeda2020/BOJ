#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

#include <iostream>
using namespace std;

bool bCheck[11];
int maxSelectedCntByCombSize[11];
vector<string> solution(vector<string> orders, vector<int> courses) {
    vector<string> answer;
    map<string, int> subOrderCntMap;
    
    for (auto order : orders)
    {
        sort(order.begin(), order.end());
        int orderSize = (int)order.size();
        for (auto course : courses)
        {
            if (orderSize < course) continue;
            
            for (int i = 0; i < course; i++)
            {
                bCheck[i] = true;
            }
            sort(bCheck, bCheck + orderSize);
            
            do {
                string subOrder;
                for (int i = 0; i < orderSize; i++)
                {
                    if (bCheck[i])
                    {
                        subOrder += order[i];
                    }
                }
                
                if (!subOrderCntMap.count(subOrder))
                {
                    subOrderCntMap.insert({ subOrder, 1});
                }
                else
                {
                    subOrderCntMap[subOrder]++;
                }
                
                /* 해당 단품 사이즈에 대해 최대로 많이 선택된 수 갱신 */
                maxSelectedCntByCombSize[(int)subOrder.size()] = max(
                    maxSelectedCntByCombSize[(int)subOrder.size()],
                    subOrderCntMap[subOrder]
                );
            } while(next_permutation(bCheck, bCheck + orderSize));
            memset(bCheck, 0, sizeof(bCheck));
        }
    }
    
    /* 단품 조합 개수별 가장 많은 손님들에게 선택된 조합만 후보에 포함(단 최소 2명 이상) */
    for (auto iter = subOrderCntMap.begin(); iter != subOrderCntMap.end(); iter++)
    {
        if (iter->second >= 2 && maxSelectedCntByCombSize[(int)iter->first.size()] == iter->second)
        {
            answer.push_back(iter->first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}