#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int T;

vector<int> Parse(string input)
{
	vector<int> ret;

	string tmpInput;
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (input[i] == ',')
		{
			tmpInput += ' ';
		}
		else if (input[i] == '[' || input[i] == ']')
		{
			continue;
		}
		else
		{
			tmpInput += input[i];
		}
	}

	istringstream iss(tmpInput);
	string buffer;

	while (getline(iss, buffer, ' '))
	{
		ret.push_back(atoi(&buffer[0]));
	}

	return ret;
}

string Execute(string func, string input)
{
	string ret;
	vector<int> parsedVec = Parse(input);
	
	int begin = 0;
	int end = (int)parsedVec.size() - 1;
	
	int cur = begin;
	int reversedCnt = 0;
	
	for (int i = 0; i < (int)func.size(); i++)
	{
		if (func[i] == 'R')
		{
			if (cur == begin)
			{
				cur = end;
			}
			else
			{
				cur = begin;
			}
			reversedCnt++;
		}
		else // 'D'
		{
			if (begin > end)
			{
				ret = "error";
				return ret;
			}
			else
			{
				if (cur == begin)
				{
					cur++;
					begin++;
				}
				else
				{
					cur--;
					end--;
				}
			}
		}
	}

	ret += '[';
	if (reversedCnt % 2 == 0)
	{
		for (int i = begin; i <= end; i++)
		{
			ret += to_string(parsedVec[i]);
			ret += ',';
		}
	}
	else
	{
		for (int i = end; i >= begin; i--)
		{
			ret += to_string(parsedVec[i]);
			ret += ',';
		}
	}
	
	if (begin <= end)
	{
		ret.pop_back();
	}
	ret += ']';
	return ret;
}

int main()
{
	cin >> T;

	string func, input;
	int size;
	for (int i = 0; i < T; i++)
	{
		cin >> func;
		cin >> size;
		cin >> input;
		cout << Execute(func, input) << '\n';
	}
	return 0;
}