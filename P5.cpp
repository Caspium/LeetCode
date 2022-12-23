#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = s.length(); j > i; j--)
            {
                if (s[i] == s[j])
                {
                    string forward = s.substr(i, j - i + 1);
                    string backward = forward;
                    reverse(backward.begin(), backward.end());
                    if (forward == backward)
                    {
                        return forward;
                    }
                }
            }
        }
        return s.substr(0, 1);
    }
};

int main()
{
    Solution s;
    string str = "a";
    string result = s.longestPalindrome(str);
    cout << result << endl;
    return 0;
}