#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int FriendsSize;
map<string, int> FriendsIdxMap;
int GiftScore[51];
int GiftTradeCnt[51][51];
int NextMounthGiftResult[51];

int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    
    FriendsSize = static_cast<int>(friends.size());
    for (size_t i = 0; i < friends.size(); i++)
    {
        FriendsIdxMap.insert({ friends[i], (int)i });
    }
    
    string src, dest;
    int blankIdx, srcIdx, destIdx;
    for (size_t i = 0; i < gifts.size(); i++)
    {
        blankIdx = gifts[i].find(" ");
        src = gifts[i].substr(0, blankIdx);
        dest = gifts[i].substr(blankIdx + 1, (int)gifts[i].size() - blankIdx);
        
        srcIdx = FriendsIdxMap.find(src)->second;
        destIdx = FriendsIdxMap.find(dest)->second;
        
        GiftTradeCnt[srcIdx][destIdx]++;
    }
    
    /* 각각의 선물지수 계산 */
    for (int i = 0; i < FriendsSize; i++)
    {
        int giveCnt = 0;
        int getCnt = 0;
        for (int j = 0; j < FriendsSize; j++)
        {
            if (i != j) 
            {
                giveCnt += GiftTradeCnt[i][j];
                getCnt += GiftTradeCnt[j][i];
            }  
        }
        GiftScore[i] += (giveCnt - getCnt);
    }
    
    /* 다음달 선물 받을 개수 계산 */
    for (int i = 0; i < FriendsSize; i++)
    {
        for (int j = 0; j < FriendsSize; j++)
        {
            if (i != j)
            {
                // i가 j에게 받은 것보다 j가 i에게 받은게 더 많다면
                if (GiftTradeCnt[j][i] < GiftTradeCnt[i][j])
                {
                    // i에게 선물 하나 줌
                    NextMounthGiftResult[i]++;
                }
                else if (GiftTradeCnt[i][j] == GiftTradeCnt[j][i]) // 서로 주고받은 수가 같다면
                {
                    // 선물 지수가 더 큰 사람이 선물을 하나 받음
                    if (GiftScore[i] > GiftScore[j])
                    {
                        NextMounthGiftResult[i]++;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < FriendsSize; i++)
    {
        answer = max(answer, NextMounthGiftResult[i]);
    }
    
    return answer;
}