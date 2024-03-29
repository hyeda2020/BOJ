#include <iostream>
#include <string>
using namespace std;

int T;
int IsPalindrome(string& str)
{
    int ret = 0;
    int left = 0, right = (int)str.size() - 1;
    
    int flag = 0;
    int tmpLeft = 0, tmpRight = 0;
    
    while (left < right)
    {
        if (str[left] != str[right])
        {
            if (flag == 0 && str[left + 1] == str[right])
            {
                tmpLeft = left;
                tmpRight = right;
                
                flag = 3;
                left++;
            }
            else if (flag == 0 && str[left] == str[right - 1])
            {
                flag = 1;
                right--;
            }
            else
            {
                if (flag == 3)
                {
                    left = tmpLeft;
                    right = tmpRight - 1;
                    flag = 1;
                }
                else
                {
                    flag = 2;
                    break;
                }
            }
        }
        else
        {
            left++;
            right--;
        }
    }
    
    if (flag == 1 || flag == 3) 
    {
        ret = 1;
    }
    else if (flag == 2)
    {
        ret = 2;
    }
    return ret;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    string str;
    for (int t = 0; t < T; t++)
    {
        cin >> str;
        cout << IsPalindrome(str) << '\n';
    }
    return 0;
}
