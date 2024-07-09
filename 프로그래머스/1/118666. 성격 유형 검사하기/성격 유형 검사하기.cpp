#include <string>
#include <vector>
#include <map>
using namespace std;

int Score[8] = { 0, 3, 2, 1, 0, 1, 2, 3 };
char TypeArr[4][2] = {
    { 'R', 'T' },
    { 'C', 'F' },
    { 'J', 'M' },
    { 'A', 'N' }
};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> TypeScore;
    int choice;
    for (int i = 0; i < (int)choices.size(); i++)
    {
        choice = choices[i];
        if (choice < 4)
        {
            TypeScore[survey[i][0]] += Score[choice];
        }
        else if (choice > 4)
        {
            TypeScore[survey[i][1]] += Score[choice];
        }
        else 
        {
            TypeScore[survey[i][0]] += 0;
            TypeScore[survey[i][1]] += 0;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (TypeScore[TypeArr[i][0]] < TypeScore[TypeArr[i][1]])
        {
            answer += TypeArr[i][1];
        }
        else
        {
            answer += TypeArr[i][0];
        }
    }
    
    return answer;
}