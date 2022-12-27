#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        string back = s;
        reverse(back.begin(), back.end());
        return s == back;
    }
};

int main()
{
    Solution s;
    int x = 123;
    bool result = s.isPalindrome(x);
    cout << result << endl;
    return 0;
}