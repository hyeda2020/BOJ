#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Tuple
{
public:
    int key;
    int colVal;
    int row;
    
    Tuple(int key, int colVal, int row)
    {
        this->key = key;
        this->colVal = colVal;
        this->row = row;
    }
};

int Col;

class Cmp
{
public:
    bool operator()(vector<int>& left, vector<int>& right)
    {
        if (left[Col] != right[Col]) // key를 기준으로 오름차순
        {
            return left[Col] < right[Col];
        }
        return left[0] > right[0]; // colVal를 기준으로 내림차순
    }
};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
    int answer = 0;
    Col = col - 1;
    sort(data.begin(), data.end(), Cmp());
    
    int leftSum;
    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        leftSum = 0;
        for (size_t j = 0; j < data[i].size(); j++)
        {
            leftSum += (data[i][j] % (i + 1));
        }
        answer ^= leftSum;
    }

    return answer;
}



