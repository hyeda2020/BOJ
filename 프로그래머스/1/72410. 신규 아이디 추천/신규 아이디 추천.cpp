#include <string>
#include <vector>
#include <set>
using namespace std;

string MergeDots(string str)
{
    set<int> eraseIdx;
    char prev = ' ';
    
    for (int i = 0; i < (int)str.size(); i++)
    {
        char cur = str[i];
        if (prev == '.' && cur == '.')
        {
            eraseIdx.insert(i);
        }
        prev = cur;
    }
    
    string ret = "";
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (!eraseIdx.count(i))
        {
            ret += str[i];
        }
    }
    return ret;
}

string solution(string new_id) {
    string answer = "";
    
    /* 1단계 : 대문자 -> 소문자 */
    for (int i = 0; i < (int)new_id.size(); i++)
    {
        new_id[i] = (char)tolower(new_id[i]);
    }
    
    /* 2단계 : 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자 제거 */
    string tmp = "";
    for (int i = 0; i < (int)new_id.size(); i++)
    {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9'))
        {
            tmp += new_id[i];
        }
    }
    new_id = tmp;
    
    /* 3단계 : 연속된 .을 하나의 .로 치환 */
    new_id = MergeDots(new_id);
    
    /* 4단계 : 맨 앞/끝 . 제거 */
    if (!new_id.empty() && new_id.front() == '.')
    {
        new_id.erase(new_id.begin());
    }
    if (!new_id.empty() && new_id.back() == '.')
    {
        new_id.pop_back();
    }
    
    /* 5단계 : 빈 문자열이라면 "a"로 치환 */
    if (new_id.empty())
    {
        new_id = "a";
    }
    
    /* 6단계 : 길이가 16 이상이면 첫 15개 문자를 제외한 나머지 문자 제거 */
    while (new_id.size() >= 16)
    {
        new_id.pop_back();
    }
    if (new_id.back() == '.') // 마지막이 .인 경우에도 제거
    {
        new_id.pop_back();
    }
    
    /* 7단계 : 길이가 2자 이하라면 마지막 문자를 3이 될 때까지 반복해서 뒤에 붙임 */
    while (new_id.size() <= 2)
    {
        new_id.push_back(new_id.back());
    }
    
    answer = new_id;
    return answer;
}