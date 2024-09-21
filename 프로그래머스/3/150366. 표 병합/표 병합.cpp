#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <cstring>
using namespace std;

enum {
    SIZE = 50
};

string Arr[51][51];
pair<int, int> Parent[51][51];

pair<int, int> FindParent(int& r, int& c)
{
    if (Parent[r][c].first == r && Parent[r][c].second == c)
    {
        return { r, c };
    }
    else
    {
        return Parent[r][c] = FindParent(Parent[r][c].first, Parent[r][c].second);
    }
}

void Update(int& r, int& c, string& value)
{
    pair<int, int> parent = Parent[r][c];
    Arr[parent.first][parent.second] = value;
}

void Update(string& value1, string& value2)
{
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (Arr[i][j] == value1)
            {
                Arr[i][j] = value2;
            }
        }
    }
}

void Merge(int& r1, int& c1, int& r2, int& c2)
{
    pair<int, int> parent1 = FindParent(r1, c1);
    pair<int, int> parent2 = FindParent(r2, c2);
    
    if (parent1 == parent2)
    {
        return;
    }
    
    if (Arr[parent1.first][parent1.second] == "EMPTY" && 
       Arr[parent2.first][parent2.second] != "EMPTY")
    {
        Parent[parent1.first][parent1.second] = parent2;
        for (int i = 1; i <= SIZE; i++)
        {
            for (int j = 1; j <= SIZE; j++)
            {
                if (Parent[i][j] == parent1)
                {
                    Parent[i][j] = parent2;
                }
            }
        }
    }
    else
    {
        Parent[parent2.first][parent2.second] = parent1;
        for (int i = 1; i <= SIZE; i++)
        {
            for (int j = 1; j <= SIZE; j++)
            {
                if (Parent[i][j] == parent2)
                {
                    Parent[i][j] = parent1;
                }
            }
        }
    }
}

void Unmerge(int& r, int& c)
{
    pair<int, int> parent = Parent[r][c];
    string parentVal = Arr[parent.first][parent.second];
    
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (Parent[i][j] == parent)
            {
                Parent[i][j] = { i, j };
                Arr[i][j] = "EMPTY";
            }
        }
    }
    
    Arr[r][c] = parentVal;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            Arr[i][j] = "EMPTY";
            Parent[i][j] = { i, j };
        }
    }
    
    vector<vector<string>> commandVec;
    vector<string> command;
    string buffer;
    for (int i = 0; i < (int)commands.size(); i++)
    {
        istringstream iss(commands[i]);
        while(getline(iss, buffer, ' '))
        {
            command.push_back(buffer);
        }
        commandVec.push_back(command);
        command.clear();
    }
    
    int r, c, r2, c2;
    string value1, value2;
    for (vector<string> command : commandVec)
    {
        if (command[0] == "UPDATE")
        {
            if ((int)command.size() > 3)
            {   
                r = atoi(&command[1][0]);
                c = atoi(&command[2][0]);
                value1 = command[3];
                Update(r, c, value1);
            }
            else
            {
                value1 = command[1];
                value2 = command[2];
                Update(value1, value2);
            }    
        }
        else if (command[0] == "MERGE")
        {
            r = atoi(&command[1][0]);
            c = atoi(&command[2][0]);
            r2 = atoi(&command[3][0]);
            c2 = atoi(&command[4][0]);
            Merge(r, c, r2, c2);
        }
        else if (command[0] == "UNMERGE")
        {
            r = atoi(&command[1][0]);
            c = atoi(&command[2][0]);
            Unmerge(r, c);
        }
        else 
        {
            r = atoi(&command[1][0]);
            c = atoi(&command[2][0]);
            pair<int, int> parent = Parent[r][c];
            answer.push_back(Arr[parent.first][parent.second]);
        }
    }
    
    return answer;
}