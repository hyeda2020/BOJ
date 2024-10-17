#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, pair<int, int>>> subseqVec;
    
    int size = (int)sequence.size();
    int begin = 0;
    int end = 0;
    int sum = sequence[begin];
    
    while (begin < size)
    { 
        if (sum < k)
        {
            if (end < size - 1)
            {
                end++;
                sum += sequence[end];
            }
            else
            {
                sum -= sequence[begin++];
            }
        }
        else if (sum > k)
        {
            sum -= sequence[begin++];
        }
        else 
        {
            subseqVec.push_back({ end - begin , { begin, end }});
            if (end < size - 1)
            {
                end++;
                sum += sequence[end];
            }
            else
            {
                sum -= sequence[begin++];
            }
        }
    }
    
    sort(subseqVec.begin(), subseqVec.end());
    
    answer.push_back(subseqVec.front().second.first);
    answer.push_back(subseqVec.front().second.second);
    return answer;
}