#include <string>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> KeyVec;
bool bCheck[9];
int colSize;

bool IsMinimum(string key)
{
    bool ret = true;
    for (auto cur : KeyVec)
    {
        int cnt = 0;
        for (int i = 0; i < (int)cur.size(); i++)
        {
            if (key.find(cur[i]) != string::npos)
            {
                cnt++;
            }
        }
        
        if (cnt == (int)cur.size())
        {
            ret = false;        
            break;
        }
    }
    return ret;
}

bool IsUnique(vector<vector<string>>& relation, bool* attributeSet)
{
    bool ret = true;
    set<vector<string>> tupleSet;
    
    for (int i = 0; i < (int)relation.size(); i++)
    {
        vector<string> vec;
        for (int j = 0; j < colSize; j++)
        {
            if (attributeSet[j])
            {
                vec.push_back(relation[i][j]);
            }
        }
        
        /* 해당 튜플 조합이 존재하는지 체크 */
        if (tupleSet.count(vec))
        {
            ret = false;
            break;
        }
        else
        {
            tupleSet.insert(vec);
        }
    }
    return ret;
}

int solution(vector<vector<string>> relation) {
    colSize = (int)relation[0].size();
    
    for (int i = 0; i < colSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            bCheck[j] = true;    
        }
        sort(bCheck, bCheck + colSize);
        
        do
        {
            string key = "";
            for (int j = 0; j < colSize; j++)
            {
                if (bCheck[j])
                {
                    key += '0' + j;
                }
            }
            
            if (IsUnique(relation, bCheck) && IsMinimum(key))
            {
                KeyVec.push_back(key);
            }
        } while(next_permutation(bCheck, bCheck + colSize));
        memset(bCheck, 0, sizeof(bCheck));
    }
    
    int answer = max(1, (int)KeyVec.size()); // relation의 컬럼사이즈가 1인 경우에 대한 예외처리
    return answer;
}
