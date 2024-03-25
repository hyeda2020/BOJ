#include <iostream>
#include <set>
#include <string>
using namespace std;

void solution(int n)
{
	set<string> visited;
	bool flag = true;
	string str = "";

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		visited.insert(str);
	}

	for (auto iter = visited.begin(); iter != visited.end(); iter++)
	{
		str = "";
		for (size_t i = 0; i < iter->size(); i++)
		{
			str += iter->at(i);
			if (iter != visited.find(str) && visited.count(str))
			{
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag)	cout << "YES" << '\n';
	else		cout << "NO" << '\n';
}

int main()
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		solution(n);
	}
	return 0;
}