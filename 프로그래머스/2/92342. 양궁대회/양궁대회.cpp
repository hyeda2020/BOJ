#include <string>
#include <vector>
using namespace std;

int MaxScoreDiff;
vector<int> ApeachInfo, LionInfoResult;

int GetScoreDiff(vector<int>& lionInfo)
{
    int lionScore = 0;
    int apeachScore = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (!ApeachInfo[i] && !lionInfo[i]) continue; // 어느 누구도 단 하나의 화살도 못맞힘
        if (ApeachInfo[i] < lionInfo[i])
        {
            lionScore += (10 - i);
        }
        else
        {
            apeachScore += (10 - i);
        }
    }
    return (lionScore - apeachScore);
}

bool bLowerCase(vector<int>& lionInfo)
{
    bool ret = false;
    for (int i = 10; i >= 0; i--) // 0점 과녁부터 비교
    {
        // 낮은 점수
        if (lionInfo[i] > LionInfoResult[i])
        {
            ret = true;
            break;
        }
        else if (lionInfo[i] < LionInfoResult[i])
        {
            ret = false;
            break;
        }
    }
    return ret;
}

void DFS(vector<int>& lionInfo, int idx, int cnt)
{
    if (idx == 11 || cnt == 0)
    {
        int scoreDiff = GetScoreDiff(lionInfo);
        if (scoreDiff > 0) // 라이언이 이긴 경우
        {
            if (cnt > 0)
            {
                // 화살이 남아있으면 0점에 나머지 화살을 모두 쏨
                lionInfo[10] = cnt;
            }

            if (scoreDiff > MaxScoreDiff) // 최대 점수차 갱신
            {
                MaxScoreDiff = scoreDiff;
                LionInfoResult = lionInfo;
            }
            else if (scoreDiff == MaxScoreDiff && bLowerCase(lionInfo)) // 같은 점수인데 우선순위가 더 높을 경우
            {
                LionInfoResult = lionInfo;
            }

            lionInfo[10] = 0; // 0점은 다시 0건으로
        }
        return;
    }

    if (cnt > ApeachInfo[idx]) // idx에 화살을 쏘는 경우
    {
        lionInfo[idx] = ApeachInfo[idx] + 1;
        DFS(lionInfo, idx + 1, cnt - lionInfo[idx]);
        lionInfo[idx] = 0;
    }
    DFS(lionInfo, idx + 1, cnt); // idx에 쏘지 않고 다음 목표로 넘어가는 경우
}

vector<int> solution(int n, vector<int> info) {
    // 전역변수화
    ApeachInfo = info;
    
    // lionInfo 0으로 초기화
    vector<int> lionInfo(11, 0);

    DFS(lionInfo, 0, n);

    if (!MaxScoreDiff)
    {
        LionInfoResult.push_back(-1);
    }
    return LionInfoResult;
}