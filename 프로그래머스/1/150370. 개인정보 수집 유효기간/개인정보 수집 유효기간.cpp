#include <string>
#include <vector>
#include <map>
using namespace std;

string TdayYear, TdayMonth, Tday;
map<string, int> TermsMap;
map<int, pair<string, string>> PrivaciesMap;

string AddMonths(string date, int month)
{
    int dateYear = stoi(date.substr(0, 4));
    int dateMonth = stoi(date.substr(5, 2));
    int dateDay = stoi(date.substr(8, 2));
    
    dateDay--;
    if (dateDay == 0)
    {
        dateDay = 28;
        dateMonth--;
    }
    
    dateYear += (month / 12);
    dateMonth += (month % 12);
    if(dateMonth > 12)
    {
        dateYear++;
        dateMonth -= 12;
    }
    
   string ret = "";
    ret += to_string(dateYear);
    ret += ".";
    if (dateMonth < 10)
    {
        ret += "0";
    }
    ret += to_string(dateMonth);
    ret += ".";
    if (dateDay < 10)
    {
        ret += "0";
    }
    ret += to_string(dateDay);
    return ret;
}

bool IsExpired(string date, int month)
{
    bool ret = true;
    
    string privacyDate = AddMonths(date, month);
    string privacyYear = privacyDate.substr(0, 4);
    string privacyMonth = privacyDate.substr(5, 2);
    string privacyDay = privacyDate.substr(8, 2);
    
    if (stoi(TdayYear) < stoi(privacyYear)) // 년 비교
    {
        ret = false;
    }
    else if (TdayYear == privacyYear) // 월 비교
    {
        if (stoi(TdayMonth) < stoi(privacyMonth))
        {
            ret = false;
        }
        else if (TdayMonth == privacyMonth) // 일 비교
        {
            if (stoi(Tday) <= stoi(privacyDay))
            {
                ret = false;
            }
        }
    }
    
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    TdayYear = today.substr(0, 4);
    TdayMonth = today.substr(5, 2);
    Tday = today.substr(8, 2);
    
    //cout << TdayYear << "." << TdayMonth << "." << Tday << endl;
    
    string type, period;
    for (auto cur : terms)
    {
        type = cur.substr(0, 1);
        period = cur.substr(2, (int)cur.size() - 2);
        TermsMap.insert({ type, atoi(&period[0]) });
    }
    
    string privacy;
    for (size_t i = 0; i < privacies.size(); i++)
    {
        privacy = privacies[i].substr(0, 10);
        type = privacies[i].substr(11, 1);
        PrivaciesMap.insert({ i + 1, { privacy, type }});
    }
    
    for (auto iter = PrivaciesMap.begin(); iter != PrivaciesMap.end(); iter++)
    {
        if (IsExpired(iter->second.first, TermsMap[iter->second.second]))
        {
            answer.push_back(iter->first);
        }
    }
    
    return answer;
}

