#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<string, int> UserIdxMap;
set<string> ReportSet[1001];
int Result[1001];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    for (int i = 0; i < (int)id_list.size(); i++)
    {
        UserIdxMap.insert({ id_list[i], i });
    }

    int idx = 0;
    int blankPos = 0;
    string src, dest;
    for (int i = 0; i < (int)report.size(); i++)
    {
        blankPos = report[i].find(" ");
        src = report[i].substr(0, blankPos);
        dest = report[i].substr(blankPos + 1, (int)report[i].size() - 1);

        idx = UserIdxMap.find(dest)->second;
        ReportSet[idx].insert(src);
    }

    for (int i = 0; i < (int)id_list.size(); i++)
    {
        if (ReportSet[i].size() >= k)
        {
            for (auto iter : ReportSet[i]) 
            {
                Result[UserIdxMap[iter]]++;
            }
        }
    }

    for (int i = 0; i < (int)id_list.size(); i++)
    {
        answer.push_back(Result[i]);
    }
    return answer;
}